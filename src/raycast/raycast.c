/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:28:56 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/25 04:02:42 by rzhdanov         ###   ########.fr       */
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

int execute_raycasting(t_game *game)
{
	t_ray			*ray;
	int				column;
	mlx_texture_t	*texture;

	ray = game->ray;
	column = -1;
	while (++column < WIDTH)
	{
		initialize_raycast_info(column, game, ray);
		configure_dda(game, ray);
		execute_dda(game, ray);
		compute_wall_intersections(game, ray);
		// Determine wall color based on direction
		// if (ray->side == 0) // Hit a vertical wall (North or South)
		// {
		// 	if (ray->step_x > 0) // Ray moving to the East
		// 		wall_color = combiner_hex(128, 10, 199, 255); // Red for East
		// 	else // Ray moving to the West
		// 		wall_color = combiner_hex(28, 90, 50, 255); // Green for West
		// }
		// else // Hit a horizontal wall (East or West)
		// {
		// 	if (ray->step_y > 0) // Ray moving to the South
		// 		wall_color = combiner_hex(218, 190, 150, 255); // Blue for South
		// 	else // Ray moving to the North
		// 		wall_color = combiner_hex(11, 98, 150, 255); // Yellow for North
		// }
		if (ray->side == 0) // Hit a vertical wall (North or South)
		{
			if (ray->step_x > 0) // Ray moving to the East
				texture = game->textures.text_e; // Red for East
			else // Ray moving to the West
				texture = game->textures.text_w; // Green for West
		}
		else // Hit a horizontal wall (East or West)
		{
			if (ray->step_y > 0) // Ray moving to the South
				texture = game->textures.text_s; // Blue for South
			else // Ray moving to the North
				texture = game->textures.text_n; // Yellow for North
		}
		draw_wall(ray, game->img_ray, texture, column, ray->bottom_pixel, ray->top_pixel);
	}
	return (1);
}

void draw_wall(t_ray *ray, mlx_image_t *img, mlx_texture_t *texture, int column, int bottom_pixel, int top_pixel)
{
	int	y;
	int	d;
	int texture_x;
	int texture_y;
	uint32_t color;
	uint8_t *pixel;

	// Calculate the x-coordinate in the texture
	texture_x = (int)(ray->wall_hit_x * texture->width);
	if (ray->side == 0 && ray->direction.x > 0) // Flip horizontally for specific sides
		texture_x = texture->width - texture_x - 1;
	if (ray->side == 1 && ray->direction.y < 0)
		texture_x = texture->width - texture_x - 1;
	if (texture_x < 0)
		texture_x = 0;
	if ((uint32_t)texture_x >= texture->width)
		texture_x = texture->width - 1;
	// Draw the wall column
	y = bottom_pixel;
	while (y <= top_pixel)
	{
		// Map the current screen pixel to a texture pixel
		d = y * 2 - HEIGHT + ray->wall_height; // Adjust for perspective
		texture_y = ((d * texture->height) / ray->wall_height) / 2;
		if (texture_y < 0)
			texture_y = 0;
		if ((uint32_t)texture_y >= texture->height)
			texture_y = texture->height - 1;

		// Fetch the color from the texture
		pixel = texture->pixels + (texture_y * texture->width + texture_x) * texture->bytes_per_pixel;
		color = combiner_hex(pixel[0], pixel[1], pixel[2], 255);
		// Draw the pixel
		mlx_put_pixel(img, column, y, color);
		y++;
	}
}
