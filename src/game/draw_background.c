/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:19:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/26 13:06:56 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 * Draws the screen background. Fills the upper half with the ceiling color.
 * Fills the lower half with the floor color.
 *
 * Parameters:
 *  - t_game *game: Game structure with image and color data.
 *
 * Implementation:
 *  - Loops through each pixel. Uses `mlx_put_pixel` to set colors.
 *  - Ceiling color: `game->parser.elem.c_color`.
 *  - Floor color: `game->parser.elem.f_color`.
 */

void	draw_background(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT >> 1)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(game->img_back, x, y, game->parser.elem.c_color);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(game->img_back, x, y, game->parser.elem.f_color);
			x++;
		}
		y++;
	}
}
