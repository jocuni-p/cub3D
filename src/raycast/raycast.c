/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:28:56 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/04 15:53:42 by rzhdanov         ###   ########.fr       */
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
		ray->side_dist_x = ((ray->map_x + 1.0f) * TILE_SIZE - player->x) * ray->delta_dist_x;
	}
	if (ray->direction_y < 0)
	{
		ray->map_step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y * TILE_SIZE) * ray->delta_dist_y;
	}
	else
	{
		ray->map_step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0f - player->y) * TILE_SIZE * ray->delta_dist_y;
	}
}

void	initialize_ray(t_player *player, t_ray *ray)
{
	ray->direction_x = cos(ray->angle);
	// if (!ray->direction_x)
	// 	ray->direction_x = 1e-6;
	ray->direction_y = sin(ray->angle);
	// if (!ray->direction_y)
	// 	ray->direction_y = 1e-6;
	ray->map_x = (int)(player->x / TILE_SIZE);
	ray->map_y = (int)(player->y / TILE_SIZE);
	ray->delta_dist_x = fabs(1/ray->direction_x);
	ray->delta_dist_y = fabs(1/ray->direction_y);
	set_ray_side_distances_and_steps(player, ray);
	ray->changed_x_position = 0;
	ray->changed_y_position = 0;
	ray->distance = -1;
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

float	cast_one_ray(t_player *player, t_ray *ray, char **map)
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

void	swap_axis_values(float *axis_1_c, float *axis_2_c,
						float *axis_1_step, float *axis_2_step)
{
	float	temp;

	temp = *axis_1_c;
	*axis_1_c = *axis_2_c;
	*axis_2_c = temp;
	temp = *axis_1_step;
	*axis_1_step = *axis_2_step;
	*axis_2_step = temp;
}

float	inverse_tangent(angle_tangent, swap)
{
	float	result;

	result = angle_tangent;
	if (swap)
		result = 1.0f / angle_tangent;
	return (result);
}



float	get_perpendicular_intersection(t_player *player, t_ray *ray, int swap)
{
	float	axis_1_c;
	float	axis_2_c;
	float	axis_1_step;
	float	axis_2_step;
	float	angle_tan;
	int		offset;

	angle_tan = inverse_tangent(tan(ray->angle), swap);
	axis_1_c = floor(player->x / TILE_SIZE) * TILE_SIZE;
	axis_2_c = player->y + (axis_1_c - player->x) * angle_tan;
	axis_1_step = TILE_SIZE;
	axis_2_step = TILE_SIZE * angle_tan;
	if (swap)
		swap_axis_values(&axis_1_c, &axis_2_c, &axis_1_step, &axis_2_step);
	offset = check_intersection(ray->angle, &axis_1_c, &axis_1_step, swap);

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
	initialize_player(player, 6.5f, 6.5f, angle_in_radians(120.0f));
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
