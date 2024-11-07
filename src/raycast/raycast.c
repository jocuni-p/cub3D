/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:28:56 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/07 06:10:20 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "raycast.h"

double	angle_in_radians(double angle)
{
	return (angle * PI / 180.0);
}

double	my_tan(double angle)
{
	angle = normalize_angle(angle);
	if (angle == PI / 2 || angle == 3 * PI / 2)
		angle -= 1e-6;
	return(tan(angle));
}
void print_inter_param(t_inter_param param)
{
	printf("Intersection Parameters:\n");
	printf("inter_x: %.2f\n", param.inter_x);
	printf("inter_y: %.2f\n", param.inter_y);
	printf("x_step: %.2f\n", param.x_step);
	printf("y_step: %.2f\n", param.y_step);
	printf("offset: %d\n", param.offset);
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
	printf("Angle in degrees:	%f\n", ray->angle * 180 / PI);
	// printf("Direction X:		%f\n", ray->direction_x);
	// printf("Direction Y:		%f\n", ray->direction_y);
	// printf("Map X:				%d\n", ray->map_x);
	// printf("Map Y:				%d\n", ray->map_y);
	// printf("Delta Dist X:		%f\n", ray->delta_dist_x);
	// printf("Delta Dist Y:		%f\n", ray->delta_dist_y);
	// printf("Map Step X:			%d\n", ray->map_step_x);
	// printf("Map Step Y:			%d\n", ray->map_step_y);
	// printf("Side Dist X:		%f\n", ray->side_dist_x);
	// printf("Side Dist Y:		%f\n", ray->side_dist_y);
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

// double	cast_one_ray(t_player *player, t_ray *ray, char **map)
// {
// 	int		wall_hit;

// 	wall_hit = 0;
// 	//printf("Before the cycle:\n");
// 	//print_ray_info(ray);
// 	while (!wall_hit && ray->map_x >= 0 && ray->map_y >=0
// 			&& ray->map_x < (int)strlen(map[0]) 
// 			&& ray->map_y < (int)strlen(map[0]))
// 	{
// 		print_ray_info(ray);
// 		if(map[ray->map_x][ray->map_y] == '1')
// 		{
// 			printf("calculating hypotenuse\n");
// 			printf("player->x is : %f, ray->map_x is : %d\n", player->x, ray->map_x);
// 			printf("player->y is : %f, ray->map_y is : %d\n", player->y, ray->map_y);
// 			ray->distance = hypot((player->x - ray->map_x),
// 			 						(player->y - ray->map_y));
// 			// ray->distance = hypot(ray->changed_x_position * ray->side_dist_x,
// 			// 						ray->changed_y_position * ray->side_dist_y);			
// 			wall_hit = 1;
// 			printf("HURRAY A HIT!\n");
// 			print_ray_info(ray);
// 			return (ray->distance);
// 		}
// 		if(ray->side_dist_x < ray->side_dist_y)
// 		{
// 			ray->side_dist_x += ray->delta_dist_x;
// 			ray->map_x += ray->map_step_x;
			
// 		}
// 		else
// 		{
// 			ray->side_dist_y += ray->delta_dist_y;
// 			ray->map_y += ray->map_step_y;
// 		}
// 	}
// 	return (ray->distance);
// }

int	check_inter(double angle, double *intersection, double *step,
				char orientation)
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

bool	wall_is_hit(double x, double y, char **map)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if (x < 0 || y < 0 || map_x > (int)strlen(map[0]) ||
						map_y > (int)strlen(map[0])) // works only with squares. need to change
		return (1);
	if (map[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	set_intersection_parameters(t_player *player, t_ray *ray, 
									t_inter_param *inter_param,
									char orientation)
{
	if (orientation == VERTICAL)
	{
		inter_param->x_step = TILE_SIZE;
		inter_param->y_step = TILE_SIZE * my_tan(ray->angle);
		printf("ray->angle is %f\n", ray->angle);
		printf("my_tan(angle) is %f\n", tan(ray->angle));
		printf("tan(angle) is %f\n", my_tan(ray->angle));
		inter_param->inter_x = floor(player->x / TILE_SIZE) * TILE_SIZE;
		inter_param->inter_y = player->y + (inter_param->inter_x - player->x) *
											 my_tan(ray->angle);
		inter_param->offset = check_inter(ray->angle, &inter_param->inter_x, 
											&inter_param->x_step, orientation);
		//TODO modify the y_step if necessary by multiplying by -1 depending on which half of the circle the ray is
		//print_inter_param(*inter_param);
		validate_step_direction(ray->angle, orientation, &inter_param->y_step);
	}
	else if(orientation == HORIZONTAL)
	{
		inter_param->x_step = TILE_SIZE / my_tan(ray->angle);
		inter_param->y_step = TILE_SIZE;
		inter_param->inter_x = player->x + (inter_param->inter_y - player->y) /
											my_tan(ray->angle);
		inter_param->inter_y = floor(player->y / TILE_SIZE) * TILE_SIZE;
		inter_param->offset = check_inter(ray->angle, &inter_param->inter_y,
											&inter_param->y_step, orientation);
		//TODO modify the x_step if necessary by multiplying by -1 depending on which half of the circle the ray is
		validate_step_direction(ray->angle, orientation, &inter_param->x_step);
	}
}

void	validate_step_direction(double angle, char orientation, double *step)
{
	bool	target_circle_half;

	if (orientation == VERTICAL)
	{
		target_circle_half = angle > 0 && angle < PI;
		if ((target_circle_half && *step < 0) ||
			(!target_circle_half && *step > 0))
			*step *= -1;
	}
	else if (orientation == HORIZONTAL)
	{
		target_circle_half = angle > (PI / 2) && angle < (3 * PI / 2);
		if ((target_circle_half && *step > 0) ||
			(!target_circle_half && *step < 0))
			*step *= -1;
	}
}

double	get_perpendicular_intersection(t_player *player, t_ray *ray,
										char **map, char orientation)
{
	//printf("get_perp_dist\n");
	t_inter_param	*tmp;

	tmp = ray->inter_param;
	set_intersection_parameters(player, ray, tmp, orientation);
	if (orientation == VERTICAL)
	{
		while(!wall_is_hit(tmp->inter_x - tmp->offset, tmp->inter_y, map))
		{
			tmp->inter_x += tmp->x_step;
			tmp->inter_y += tmp->y_step;
		}
	}
	else if (orientation == HORIZONTAL)
	{
		while(!wall_is_hit(tmp->inter_x, tmp->inter_y - tmp->offset, map))
		{
			tmp->inter_x += tmp->x_step;
			tmp->inter_y += tmp->y_step;
		}
	}
	print_inter_param(*tmp);
	return (hypot((tmp->inter_x - player->x), (tmp->inter_y - player->y)));
}

void	cast_all_rays(t_player *player, t_ray **rays, char **map)
{
	double	start_angle;
	double	angle_increment;
	double	hor_intersection;
	double	ver_intersection;
	int		i;

	start_angle = normalize_angle(player->angle - (player->fov / 2));
	printf("STARTING RAY IS %f\n", start_angle * 180 / M_PI);
	angle_increment = player->fov / WIN_WIDTH;
	i = -1;
	while (++ i < WIN_WIDTH)
	{
		printf("%d\n", i);
		initialize_ray(player, rays[i]);
		rays[i]->angle = start_angle + (i * angle_increment);
		hor_intersection = get_perpendicular_intersection(player, rays[i],
														map, HORIZONTAL);
	//	printf("hor_int is %f\n", hor_intersection);
		ver_intersection = get_perpendicular_intersection(player, rays[i],
														map, VERTICAL);
	//	printf("ver_int is %f\n", ver_intersection);
		if (ver_intersection <= hor_intersection)
			rays[i]->distance = ver_intersection;
		else
			rays[i]->distance = hor_intersection;
		print_ray_info(rays[i]);
	}
}

// void draw_a_wall(t_player *player, t_ray *ray, int top_pixel, int bottom_pixel)
// {
// 	int color;

// 	color = 0x00FF00;
// 	while (t_pix < b_pix)
// 		//MLX42 pixel put;
// }

// void render_wall(t_player *player, t_ray *ray, t_mlx *mlx, int ray) // render the wall
// {
// 	double wall_height;
// 	double top_pixel;
// 	double bottom_pixel;

// 	ray->distance *= cos(normalize_angle(ray->angle - player->angle));
// 	wall_height = (TILE_SIZE / ray->distance) * ((WIN_WIDTH / 2) / tan(player->fov / 2));
// 	top_pixel = (WIN_HEIGHT / 2) - (wall_height / 2);
// 	bottom_pixel = (WIN_HEIGHT / 2) + (wall_height / 2);
// 	if (bottom_pixel > WIN_HEIGHT)
// 		bottom_pixel = WIN_HEIGHT;
// 	if (top_pixel < 0)
// 		top_pixel = 0;
// 	draw_wall(player, ray, top_pixel, bottom_pixel);
// }


int	main(void)
{
	t_player	*player;
	t_ray		*rays[WIN_WIDTH];
	char 		*map[] = {
		"11111111111",
		"10000000001",
		"10000000x01",
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
	initialize_player(player, 8.1, 8.1, angle_in_radians(120.0));
	printf("Player's angle in Pi is %f\n", player->angle);
	initialize_array_of_rays(rays, WIN_WIDTH);
	cast_all_rays(player, rays, map);
	return (0);
}
