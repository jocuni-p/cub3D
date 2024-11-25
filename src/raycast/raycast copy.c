/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:28:56 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/25 03:43:39 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -Wall -Werror -Wextra raycast.c raycast.h ../../lib/MLX42/build/libmlx42.a -ldl -lglfw -lm -o raycast

#include "../include/cub3d.h"
// #include "raycast.h"
/* Printing functions */
// void	print_inter_param(t_inter_param param)
// {
// 	printf("Intersection Parameters:\n");
// 	printf("inter_x: %.2f\n", param.inter_x);
// 	printf("inter_y: %.2f\n", param.inter_y);
// 	printf("x_step: %.2f\n", param.x_step);
// 	printf("y_step: %.2f\n", param.y_step);
// 	printf("offset: %d\n", param.offset);
// }

// void	print_ray_info(t_ray *ray)
// {
// 	if (ray == NULL)
// 	{
// 		printf("Error: Null pointer provided.\n");
// 		return ;
// 	}
// 	printf("Ray Information:\n");
// 	printf("-------------------------------\n");
// 	printf("Angle:				%f\n", ray->angle);
// 	printf("Angle in degrees:	%f\n", ray->angle * 180 / PI);
// 	printf("Distance:			%f\n", ray->distance);
// 	printf("-------------------------------\n");
// }

// void	print_ray_info(t_ray *ray)
// {
//     if (!ray)
//     {
//         printf("Error: Null ray pointer\n");
//         return;
//     }
// 	printf("-----=====-----\n");
//     printf("Ray Information:\n");
//     printf("Camera Offset: %.4f\n", ray->camera_offset);
//     printf("Direction X: %.4f\n", ray->direction.x);
//     printf("Direction Y: %.4f\n", ray->direction.y);
//     printf("Grid X: %d\n", ray->grid_x);
//     printf("Grid Y: %d\n", ray->grid_y);
//     printf("Step X: %d\n", ray->step_x);
//     printf("Step Y: %d\n", ray->step_y);
//     printf("Side Distance X: %.4f\n", ray->side_dist_x);
//     printf("Side Distance Y: %.4f\n", ray->side_dist_y);
//     printf("Delta Distance X: %.4f\n", ray->delta_dist_x);
//     printf("Delta Distance Y: %.4f\n", ray->delta_dist_y);
//     printf("Wall Distance: %.4f\n", ray->wall_distance);
//     printf("Wall X: %.4f\n", ray->wall_hit_x);
//     printf("Side: %d\n", ray->side);
//     printf("Line Height: %d\n", ray->wall_height);
//     printf("Draw Start: %d\n", ray->bottom_pixel);
//     printf("Draw End: %d\n", ray->top_pixel);
// 	printf("Angle in rads: %f\n", atan2(ray->direction.y, ray->direction.x));
// 	printf("Angle in degrees: %f\n", atan2(ray->direction.y, ray->direction.x)*180/ PI);

// 	// printf("Angle in rads: %f\n", normalize_angle(atan2(ray->direction.y, ray->direction.x)));
// 	// printf("Angle in degrees: %f\n", normalize_angle(atan2(ray->direction.y, ray->direction.x))*180/ PI );
// 	printf("*****_____*****\n");
// }

/* Service functions */
// float	normalize_angle(float angle)
// {
// 	angle = fmod(angle, 2 * PI);
// 	if (angle < 0)
// 		angle += 2 * PI;
// 	return (angle);
// }

// float	my_angle_in_radians(float angle)
// {
// 	return (angle * PI / 180.0);
// }

// float	angle_in_radians(float angle)
// {
// 	return (angle * PI / 180.0);
// }

/* Struct initialization functions */
// void	initialize_player(t_player *player, float x, float y, float angle)
// {
// 	// player->pos.x = x * TILE_SIZE;
// 	// player->pos.y = y * TILE_SIZE;
// 	player->pos.x = x;
// 	player->pos.y = y;
// 	player->dir.x = 1;
// 	player->dir.y = 0;
// 	player->plane.x = 0;
// 	player->plane.y = -0.6;
// 	player->angle = angle;
// 	player->fov = normalize_angle(RAD(FOV)); // can use angle_in_radians instead
// }

// void	init_player(t_player *player)
// {
// 	player->dir = '\0';
// 	player->pos_x = 0.0;
// 	player->pos_y = 0.0;
// 	player->dir_x = 0.0;
// 	player->dir_y = 0.0;
// 	player->plane_x = 0.0;
// 	player->plane_y = 0.0;
// 	player->has_moved = 0;
// 	player->move_x = 0;
// 	player->move_y = 0;
// 	player->rotate = 0;
// }

void	initialize_array_of_rays(t_ray **rays, int array_size)
{
	int i;

	i = -1;
	// printf("%s STARTED\n", __func__);
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
	// printf("%s FINISHED\n", __func__);
}

// void	reset_ray_values(t_player *player, t_ray *ray)
// {
// 	(void) player;
// 	ray->distance = -1;
// 	ray->angle = 0;
// 	ray->inter_param = malloc(sizeof(t_inter_param));
// 	if (!ray->inter_param)
// 		free(ray); //TODO: write a separate void function which will print error message, free the ray and will be returned here
// 	ray->inter_param->inter_x = 0.0;
// 	ray->inter_param->inter_y = 0.0;
// 	ray->inter_param->x_step = 0.0;
// 	ray->inter_param->y_step = 0.0;
// 	ray->inter_param->offset = 0;
// }

void	reset_ray_values(t_ray *ray)
{
	ray->camera_offset = 0;
	ray->direction.x = 0;
	ray->direction.y = 0;
	ray->grid_x = 0;
	ray->grid_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->wall_distance = 0;
	ray->wall_hit_x = 0;
	ray->side = 0;
	ray->wall_height = 0;
	ray->bottom_pixel = 0;
	ray->top_pixel = 0;
}

/* Struct freeing functions */
void	free_array_of_rays(t_ray **rays, int array_size)
{
	int	i;

	i = -1;
	while (++i < array_size)
		free(rays[i]);
	free(rays);
}

/* Ray casting functions */

void	initialize_raycast_info(int column, t_game *game)
{
	t_ray		*ray;
	t_player	*player;

	ray = game->rays[column];
	player = &game->player;
	// printf("%s STARTED\n", __func__);
	reset_ray_values(ray);
	// printf("column is %d\n", column);
	ray->camera_offset = 2 * column / (float)WIDTH - 1;
	// printf("camera_offset is %f \n", ray->camera_offset);
	ray->direction.x = player->dir.x + player->plane.x * ray->camera_offset;
	ray->direction.y = player->dir.y + player->plane.y * ray->camera_offset;
	ray->grid_x = (int)player->pos.x;
	ray->grid_y = (int)player->pos.y;
	ray->delta_dist_x = fabs(1 / ray->direction.x);
	ray->delta_dist_y = fabs(1 / ray->direction.y);
	// printf("%s FINISHED\n", __func__);
}

/*
- Sets up the DDA algorithm based on the ray direction and player's position.
- Adjusts step and initial side distances in the x and y directions.
*/

void	configure_dda(t_game *game, t_ray *ray)
{
	// printf("%s STARTED\n", __func__);
	t_player	*player;

	player = &game->player;
	if (ray->direction.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos.x - ray->grid_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->grid_x + 1.0 - player->pos.x) * ray->delta_dist_x;
	}
	if (ray->direction.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos.y - ray->grid_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->grid_y + 1.0 - player->pos.y) * ray->delta_dist_y;
	}
	// print_ray_info(ray);
	// printf("%s FINISHED\n", __func__);
}

/*
- Executes the DDA loop to determine the first wall intersection point.
*/

// void	execute_dda(t_data *game_data, t_ray *ray)
void	execute_dda(t_game *game, t_ray *ray)
{
	// printf("%s STARTED\n", __func__);
	int		has_hit;
	char	**map;

	map = game->map_arr;
	has_hit = 0;
	while (has_hit == 0)
	{
		// printf("entered while cycle\n");
		// print_ray_info(ray);
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->grid_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->grid_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->grid_y < 0.25
			|| ray->grid_x < 0.25
			|| ray->grid_y > HEIGHT - 1.25
			|| ray->grid_x > WIDTH - 1.25)
			break ;
		// else if (map[ray->grid_y][ray->grid_x] > '0')
		else if (map[ray->grid_y][ray->grid_x] == '1')
			has_hit = 1;
	}
	// printf("%s FINISHED\n", __func__);
}

/*
- Calculates the height of the line to be drawn based on the wall hit point.
*/

// void	compute_wall_intersections(t_ray *ray, t_data *game_data, t_player *player)
void	compute_wall_intersections(t_game *game, t_ray *ray)
{
	t_player	*player;

	player = &game->player;
	if (ray->side == 0)
		ray->wall_distance = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->wall_distance = (ray->side_dist_y - ray->delta_dist_y);
	ray->wall_height = (int)(HEIGHT / ray->wall_distance);
	ray->bottom_pixel = -(ray->wall_height) / 2 + HEIGHT / 2;
	if (ray->bottom_pixel < 0)
		ray->bottom_pixel = 0;
	ray->top_pixel = ray->wall_height / 2 + HEIGHT / 2;
	if (ray->top_pixel >= HEIGHT)
		ray->top_pixel = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_hit_x = player->pos.y + ray->wall_distance * ray->direction.y;
	else
		ray->wall_hit_x = player->pos.x + ray->wall_distance * ray->direction.x;
	ray->wall_hit_x -= floor(ray->wall_hit_x);
}

/*
- The main raycasting function loops through each column on the screen,
  calculates the ray for that column, and renders the corresponding wall.
*/

// int	execute_raycasting(t_player *player, t_data *game_data)
// int	execute_raycasting(t_player *player, t_ray *ray, char **map)
int	execute_raycasting(t_game *game)
{
	// printf("%s STARTED\n", __func__);
	// t_ray	ray;
	// t_player	*player;
	t_ray		**rays;
	// char		**map;
	int		column;

	// player = &game->player;
	rays = game->rays;
	// map = game->map_arr;
	column = -1;
	// ray = game_data->ray;
	while (++column < WIDTH)
	{
		initialize_raycast_info(column, game);
		configure_dda(game, rays[column]);
		execute_dda(game, rays[column]);
		compute_wall_intersections(game, rays[column]);
		//update_texture_pixels(game_data, &game_data->texinfo, &ray, column);
		// column++;
	}
	// printf("%s FINISHED\n", __func__);
	return (1);
}

// rendering stuff

void	draw_wall(t_ray *ray, mlx_image_t *img, int x, int bottom_pixel, int top_pixel)
{
	uint32_t	color;
	int			i;
	
	color = 0xFF0000FF; // Wall color (green)
	i = top_pixel;
	(void) ray;

	// int starting_point = i - 1;
	while (i < bottom_pixel)
	{
		mlx_put_pixel(img, x, i, color);
		// printf("x: %d, i: %d, color: %u\n", x, i - starting_point, color);
		i ++;
	}
}

// void render_frame(t_player *player, t_ray **rays, char **map, mlx_t *mlx)
void	render_frame(t_game *game)
{
	mlx_image_t	*img;
	// t_player	*player;
	t_ray		**rays;
	// char		**map;

	img = game->img_ray;
	// player = &game->player;
	rays = game->rays;
	// map = game->map_arr;
	int			i;
	// float		corrected_distance;
	// float		wall_height;
	// int			top_pixel;
	// int			bottom_pixel;
	// (void) player;
	// (void) map;
	// img = mlx_new_image(mlx, WIDTH, HEIGHT);
	i = -1;
	// if (!img) 
	// {
	// 	printf("Failed to create image\n");
	// 	return ;
	// }
	// cast_all_rays(player, rays, map);
	while (++i < WIDTH) {
		draw_wall(rays[i], img, i, rays[i]->bottom_pixel, rays[i]->top_pixel);
		// printf("Ray %d: Angle = %f, Distance = %f\n", i, rays[i]->angle / M_PI * 180, rays[i]->distance);
		// printf("Ray %d: Wall height = %f, Top = %d, Bottom = %d\n", i, wall_height, top_pixel, bottom_pixel);
		// printf("Ray %d: Wall height in pixels %d\n", i, bottom_pixel - top_pixel);
	}
	// printf("finished drawing walls\n");
	// mlx_image_to_window(game->mlx, img, 0, 0);
	// printf("finished mlx_image_to_window\n");
	// mlx_loop(game->mlx);
	// printf("finished mlx_image_to_window\n");
	// mlx_delete_image(game->mlx, img);
}

// int main(void) {
// 	mlx_t *mlx;
// 	t_player player;
// 	t_ray *rays[WIDTH];

// 	mlx = mlx_init(WIDTH, HEIGHT, "Raycasting Demo", true);
// 	if (!mlx)
// 	{
// 		printf("Failed to initialize MLX42\n");
// 		return 1;
// 	}
// 	initialize_player(&player, 2.0, 2.0, angle_in_radians(330.0));
// 	initialize_array_of_rays(rays, WIDTH);

// 	char *map[] = {
// 		"11111111111",
// 		"10000000001",
// 		"10000000001",
// 		"10000000001",
// 		"10000000001",
// 		"10000000001",
// 		"10000000001",
// 		"10000000001",
// 		"10000000001",
// 		"10000000001",
// 		"11111111111"
// 	};

// 	render_frame(&player, rays, map, mlx);

// 	free_array_of_rays(rays, WIDTH);
// 	mlx_terminate(mlx);
// 	return 0;
// }

// int	main(void)
// {
// 	t_player	*player;
// 	t_ray		**rays;
// 	mlx_t		*mlx;
// 	// t_ray		*rays[WIDTH];

// 	mlx = mlx_init(WIDTH, HEIGHT, "Raycasting Demo", true);
// 	if (!mlx)
// 	{
// 		printf("Failed to initialize MLX42\n");
// 		return 1;
// 	}

// 	char 		*map[] = {
// 		"11111111111",
// 		"10000000001",
// 		"10000000x01",
// 		"10000000001",
// 		"10000000001",
// 		"10000000001",
// 		"10000000001",
// 		"10000000001",
// 		"10000000001",
// 		"10000000001",
// 		"11111111111"
// };

// 	player = malloc(sizeof(t_player));
// 	if (!player)
// 	{
// 		printf("Memory allocation for player failed \n");
// 		return (1);
// 	}
// 	rays = malloc(sizeof(t_ray) * WIDTH);
// 	if (!rays)
// 	{
// 		printf("Memory allocation for RAYS failed \n");
// 		return (1);
// 	}
// 	// (void) map;
// 	initialize_player(player, 6.0, 2.0, angle_in_radians(120.0));
// 	printf("Player's angle in Pi is %f\n", player->angle);
// 	initialize_array_of_rays(rays, WIDTH);
// 	execute_raycasting(player, rays, map);
// 	// int i = -1;
// 	// while (++i < WIDTH)
// 	// {
// 	// 	printf("Ray #: %d\n", i);
// 	// 	print_ray_info(rays[i]);
// 	// }
// 	render_frame(player, rays, map, mlx);
// 	free_array_of_rays(rays, WIDTH);
// 	mlx_terminate(mlx);
// 	return (0);
// }

void	execute_raycastin(t_game *game)
{
	execute_raycasting(game);
	// printf("execute_raycasting_complete\n");
	render_frame(game);
}
