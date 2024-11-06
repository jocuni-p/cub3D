/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:28:56 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/06 13:00:02 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "raycast.h"

double	angle_in_radians(double angle)
{
	return (angle * PI / 180.0);
}

void	print_ray_info(t_ray *ray)
{
	if (ray == NULL)
	{
		printf("Error: Null pointer provided.\n");
		return ;
	}
	printf("Ray Information:\n");
	printf("-------------------------------\n");
	printf("Angle:				%f\n", ray->angle);
	printf("Angle in degrees	%f\n", ray->angle * 180 / PI);
	printf("Direction X:		%f\n", ray->direction_x);
	printf("Direction Y:		%f\n", ray->direction_y);
	printf("Map X:				%d\n", ray->map_x);
	printf("Map Y:				%d\n", ray->map_y);
	printf("Delta Dist X:		%f\n", ray->delta_dist_x);
	printf("Delta Dist Y:		%f\n", ray->delta_dist_y);
	printf("Map Step X:			%d\n", ray->map_step_x);
	printf("Map Step Y:			%d\n", ray->map_step_y);
	printf("Side Dist X:		%f\n", ray->side_dist_x);
	printf("Side Dist Y:		%f\n", ray->side_dist_y);
	printf("Distance:			%f\n", ray->distance);
	printf("-------------------------------\n");
}

void	initialize_player(t_player *player, double x, double y, double angle)
{
	player->x = x * TILE_SIZE;
	player->y = y * TILE_SIZE;
	player->angle = angle;
	player->fov = normalize_angle(RAD(FOV)); // can use angle_in_radians instead
}

void	set_ray_side_distances_and_steps(t_player *player, t_ray *ray)
{
	if (ray->direction_x < 0)
	{
		ray->map_step_x = -1;
		ray->side_dist_x = (player->x - ray->map_x * TILE_SIZE) * ray->delta_dist_x;
	}
	else
	{
		ray->map_step_x = 1;
		ray->side_dist_x = ((ray->map_x + 1.0) * TILE_SIZE - player->x) * ray->delta_dist_x;
	}
	if (ray->direction_y < 0)
	{
		ray->map_step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y * TILE_SIZE) * ray->delta_dist_y;
	}
	else
	{
		ray->map_step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * TILE_SIZE * ray->delta_dist_y;
	}
}

void	initialize_ray(t_player *player, t_ray *ray)
{
	ray->inter_param = malloc(sizeof(t_inter_param));
	if (!ray->inter_param)
		free(ray);
	ray->direction_x = cos(ray->angle);
	ray->direction_y = sin(ray->angle);
	ray->map_x = (int)(player->x / TILE_SIZE);
	ray->map_y = (int)(player->y / TILE_SIZE);
	ray->delta_dist_x = fabs(1/ray->direction_x);
	ray->delta_dist_y = fabs(1/ray->direction_y);
	set_ray_side_distances_and_steps(player, ray);
	ray->distance = -1;
	ray->inter_param->inter_x = 0.0;
	ray->inter_param->inter_y = 0.0;
	ray->inter_param->x_step = 0.0;
	ray->inter_param->y_step = 0.0;
	ray->inter_param->offset = 0;
}

void	free_array_of_rays(t_ray **rays, int array_size)
{
	int	i;

	i = -1;
	while (++i < array_size)
		free(rays[i]);
}

void	initialize_array_of_rays(t_ray **rays, int array_size)
{
	int i;

	i = -1;
	while (++i < array_size)
	{
		rays[i] = malloc(sizeof(t_ray));
		if (!rays[i])
		{
			free_array_of_rays(rays, i);
			printf("Failed to allocate memory for ray No %d\n", i);
			return ;
		}
	}
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

void	print_ray_data(t_ray *ray)
{	
	printf("side_dist_x\t%f\nside_dist_y\t%f\ndistance\t%f\n",
		ray->side_dist_x, ray->side_dist_y, ray->distance);
	printf("map_x\t%d\nmap_y\t%d\n*********ANGLE\t%f\n",
		ray->map_x, ray->map_y, ray->angle);
	printf("ANGLE in degrees:%f\n\n", ray->angle * 180 / PI);
}

double	cast_one_ray(t_player *player, t_ray *ray, char **map)
{
	int		wall_hit;

	wall_hit = 0;
	//printf("Before the cycle:\n");
	//print_ray_info(ray);
	while (!wall_hit && ray->map_x >= 0 && ray->map_y >=0
			&& ray->map_x < (int)strlen(map[0]) 
			&& ray->map_y < (int)strlen(map[0]))
	{
		print_ray_info(ray);
		if(map[ray->map_x][ray->map_y] == '1')
		{
			printf("calculating hypotenuse\n");
			printf("player->x is : %f, ray->map_x is : %d\n", player->x, ray->map_x);
			printf("player->y is : %f, ray->map_y is : %d\n", player->y, ray->map_y);
			ray->distance = hypot((player->x - ray->map_x),
			 						(player->y - ray->map_y));
			// ray->distance = hypot(ray->changed_x_position * ray->side_dist_x,
			// 						ray->changed_y_position * ray->side_dist_y);			
			wall_hit = 1;
			printf("HURRAY A HIT!\n");
			print_ray_info(ray);
			return (ray->distance);
		}
		if(ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->map_step_x;
			
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->map_step_y;
		}
	}
	return (ray->distance);
}

int	check_inter(double angle, double *intersection, double *step, char orientation)
{
	if(orientation == VERTICAL)
	{
		if(angle > PI / 2 && angle < 3 * PI / 2)
		{
			*intersection += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else if(orientation == HORIZONTAL)
	{
		if(angle > 0 && angle < PI)
		{
			*intersection += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

void	set_intersection_parameters(t_player *player, t_ray *ray, 
									t_inter_param *inter_param, char orientation)
{
	if (orientation == VERTICAL)
	{
		inter_param->x_step = TILE_SIZE;
		inter_param->y_step = TILE_SIZE * tan(ray->angle);
		inter_param->inter_x = floor(player->x / TILE_SIZE) * TILE_SIZE;
		inter_param->inter_y = player->y + (inter_param->inter_x - player->x) *
											 tan(ray->angle);
		inter_param->offset = check_inter(ray->angle, &inter_param->inter_x, 
											&inter_param->x_step, orientation);
		//TODO modify the y_step if necessary by multiplying by -1 depending on which half of the circle the ray is
	}
	else if(orientation == HORIZONTAL)
	{
		inter_param->x_step = TILE_SIZE / tan(ray->angle);
		inter_param->y_step = TILE_SIZE;
		inter_param->inter_x = player->x + (inter_param->inter_y - player->y) /
											tan(ray->angle);
		inter_param->inter_y = floor(player->y / TILE_SIZE) * TILE_SIZE;
		inter_param->offset = check_inter(ray->angle, &inter_param->inter_y,
											&inter_param->y_step, orientation);
		//TODO modify the x_step if necessary by multiplying by -1 depending on which half of the circle the ray is
	}
}

double	get_perpendicular_intersection(t_player *player, t_ray *ray,
										char orientation)
{
	set_intersection_parameters(player, ray, ray->inter_param, orientation);
	
	
}


void	cast_all_rays(t_player *player, t_ray **rays, char **map)
{
	double	start_angle; 
	double	angle_increment;
	int		i;

	start_angle = player->angle - (player->fov / 2);
	angle_increment = player->fov / WIN_WIDTH;
	i = -1;
	while (++ i < WIN_WIDTH)
	{
		// Initialize the ray to starting values
		rays[i]->angle = start_angle + (i * angle_increment);
		initialize_ray(player, rays[i]);
		// Calculate the angle for this specific ray
		// Cast the ray at this angle and calculate the distance to a wall
		printf("===RAY No %d===\n\n\n", i);
		cast_one_ray(player, rays[i], map);
		//i += 10;
	}
}

int	main(void)
{
	t_player	*player;
	t_ray		*rays[WIN_WIDTH];
	char 		*map[] = {
		"11111111111",
		"10000000001",
		"10000000001",
		"10000000001",
		"10000000001",
		"10000000001",
		"10000000001",
		"10000000001",
		"10000000001",
		"10000000001",
		"11111111111"
};

	player = malloc(sizeof(t_player));
	if (!player)
	{
		printf("Memory allocation for player failed \n");
		return (1);
	}
	initialize_player(player, 6.5, 6.5, angle_in_radians(120.0));
	printf("Player's angle in Pi is %f\n", player->angle);
	initialize_array_of_rays(rays, WIN_WIDTH);
	cast_all_rays(player, rays, map);
	int i = -1;
	while (++i < WIN_WIDTH)
	{
		//print_ray_data(rays[i]);
	//	printf("Ray No: %d,\nangle\t%f\ndistance\t%f\n", i, rays[i]->angle,
	//													rays[i]->distance);
	}
	return (0);
}
