/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:28:56 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/25 02:49:27 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -Wall -Werror -Wextra raycast.c raycast.h ../../lib/MLX42/build/libmlx42.a -ldl -lglfw -lm -o raycast

#include "../include/cub3d.h"

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

void	initialize_raycast_info(int column, t_game *game, t_ray *ray)
{
	t_player	*player;

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
// int	execute_raycasting(t_game *game)
// {
// 	t_ray		*ray;
// 	int			column;

// 	ray = game->ray;
// 	column = -1;
// 	while (++column < WIDTH)
// 	{
// 		initialize_raycast_info(column, game, ray);
// 		configure_dda(game, ray);
// 		execute_dda(game, ray);
// 		compute_wall_intersections(game, ray);
// 		draw_wall(ray, game->img_ray, column, ray->bottom_pixel, ray->top_pixel);
// 		//update_texture_pixels(game_data, &game_data->texinfo, &ray, column);
// 		// column++;
// 	}
// 	// printf("%s FINISHED\n", __func__);
// 	return (1);
// }

int execute_raycasting(t_game *game)
{
    t_ray       *ray;
    int         column;
    uint32_t	wall_color;

    ray = game->ray;
    column = -1;
    while (++column < WIDTH)
    {
        initialize_raycast_info(column, game, ray);
        configure_dda(game, ray);
        execute_dda(game, ray);
        compute_wall_intersections(game, ray);
        // Determine wall color based on direction
        if (ray->side == 0) // Hit a vertical wall (North or South)
        {
            if (ray->step_x > 0) // Ray moving to the East
                wall_color = combiner_hex(128, 10, 199, 255); // Red for East
            else // Ray moving to the West
                wall_color = combiner_hex(28, 90, 50, 255); // Green for West
        }
        else // Hit a horizontal wall (East or West)
        {
            if (ray->step_y > 0) // Ray moving to the South
                wall_color = combiner_hex(218, 190, 150, 255); // Blue for South
            else // Ray moving to the North
                wall_color = combiner_hex(11, 98, 150, 255); // Yellow for North
        }
        draw_wall(game->img_ray, column, ray->bottom_pixel, ray->top_pixel, wall_color);
    }
    return (1);
}

// rendering stuff
void draw_wall(mlx_image_t *img, int column, int bottom_pixel, int top_pixel, uint32_t color)
{
    int y;

    y = bottom_pixel;
    while (y <= top_pixel)
    {
        mlx_put_pixel(img, column, y, color); // Set pixel with the given color
        y++;
    }
}
// void	draw_wall(t_ray *ray, mlx_image_t *img, int x, int bottom_pixel, int top_pixel)
// {
// 	uint32_t	color;
// 	int			i;
	
// 	color = 0xFF0000FF; // Wall color (green)
// 	i = bottom_pixel;
// 	(void) ray;

// 	// int starting_point = i - 1;
// 	while (i < top_pixel)
// 	{
// 		mlx_put_pixel(img, x, i, color);
// 		// printf("x: %d, i: %d, color: %u\n", x, i - starting_point, color);
// 		i ++;
// 	}
// }

// void render_frame(t_player *player, t_ray **rays, char **map, mlx_t *mlx)
// void	render_frame(t_game *game)
// {
// 	mlx_image_t	*img;
// 	// t_player	*player;
// 	t_ray		**rays;
// 	// char		**map;

// 	img = game->img_ray;
// 	// player = &game->player;
// 	rays = game->rays;
// 	// map = game->map_arr;
// 	int			i;
// 	// float		corrected_distance;
// 	// float		wall_height;
// 	// int			top_pixel;
// 	// int			bottom_pixel;
// 	// (void) player;
// 	// (void) map;
// 	// img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	i = -1;
// 	// if (!img) 
// 	// {
// 	// 	printf("Failed to create image\n");
// 	// 	return ;
// 	// }
// 	// cast_all_rays(player, rays, map);
// 	while (++i < WIDTH) {
// 		draw_wall(rays[i], img, i, rays[i]->bottom_pixel, rays[i]->top_pixel);
// 		// printf("Ray %d: Angle = %f, Distance = %f\n", i, rays[i]->angle / M_PI * 180, rays[i]->distance);
// 		// printf("Ray %d: Wall height = %f, Top = %d, Bottom = %d\n", i, wall_height, top_pixel, bottom_pixel);
// 		// printf("Ray %d: Wall height in pixels %d\n", i, bottom_pixel - top_pixel);
// 	}
// 	// printf("finished drawing walls\n");
// 	// mlx_image_to_window(game->mlx, img, 0, 0);
// 	// printf("finished mlx_image_to_window\n");
// 	// mlx_loop(game->mlx);
// 	// printf("finished mlx_image_to_window\n");
// 	// mlx_delete_image(game->mlx, img);
// }

void	draw_raycasting(t_game *game)
{
	execute_raycasting(game);
	// printf("execute_raycasting_complete\n");
	// render_frame(game);
}
