/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:28:56 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/12/02 01:10:02 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Computes the x-coordinate of the texture for a wall slice. Adjusts the
 * value based on the ray's hit side and direction. Ensures the texture x
 * value stays within valid bounds.
 */
static void	set_texture_x(t_game *game, mlx_texture_t *texture,
							int *texture_x)
{
	*texture_x = (int)(game->ray->wall_hit_x * texture->width);
	if ((game->ray->side == 0 && game->ray->direction.x > 0)
		|| (game->ray->side == 1 && game->ray->direction.y < 0))
		*texture_x = texture->width - *texture_x - 1;
	if (*texture_x < 0)
		*texture_x = 0;
	if ((uint32_t) * texture_x >= texture->width)
		*texture_x = texture->width - 1;
}
// The ugly int array inside is my way of addressing too many arguments issue 
// the components are as follows
// int			y; //i_a[0]
// int			d; //i_a[1]
// int			texture_x; //i_a[2]
// int			texture_y; //i_a[3]
// The normal version is commented out below

/**
 * Draws a vertical slice of a wall for the given column. Uses the raycasting
 * data to calculate the texture coordinates and fetches the pixel colors
 * from the texture. Maps these colors onto the screen using `mlx_put_pixel`.
 */
void	draw_wall(t_game *game, mlx_texture_t *texture, int column)
{
	int			i_a[4];
	uint32_t	color;
	uint8_t		*pixel;

	i_a[0] = game->ray->bottom_pixel;
	set_texture_x(game, texture, &i_a[2]);
	while (i_a[0] <= game->ray->top_pixel)
	{
		i_a[1] = i_a[0] * 2 - HEIGHT + game->ray->wall_height;
		i_a[3] = ((i_a[1] * texture->height) / game->ray->wall_height) / 2;
		if (i_a[3] < 0)
			i_a[3] = 0;
		if ((uint32_t)i_a[3] >= texture->height)
			i_a[3] = texture->height - 1;
		pixel = texture->pixels + (i_a[3] * texture->width + i_a[2])
			* texture->bytes_per_pixel;
		color = combiner_hex(pixel[0], pixel[1], pixel[2], 255);
		mlx_put_pixel(game->img_ray, column, i_a[0], color);
		i_a[0]++;
	}
}

// void	draw_wall(t_game *game, mlx_texture_t *texture, int column)
// {
// 	int			y;
// 	int			d;
// 	int			texture_x;
// 	int			texture_y;
// 	// int			i_a[4];
// 	uint32_t	color;
// 	uint8_t		*pixel;

// 	y = game->ray->bottom_pixel;
// 	set_texture_x(game,  texture, &texture_x);
// 	while (y <= game->ray->top_pixel)
// 	{
// 		d = y * 2 - HEIGHT + game->ray->wall_height;
// 		texture_y = ((d * texture->height) / game->ray->wall_height) / 2;
// 		if (texture_y < 0)
// 			texture_y = 0;
// 		if ((uint32_t)texture_y >= texture->height)
// 			texture_y = texture->height - 1;
// 		pixel = texture->pixels + (texture_y * texture->width + texture_x)
// 			* texture->bytes_per_pixel;
// 		color = combiner_hex(pixel[0], pixel[1], pixel[2], 255);
// 		mlx_put_pixel(game->img_ray, column, y, color);
// 		y++;
// 	}
// }