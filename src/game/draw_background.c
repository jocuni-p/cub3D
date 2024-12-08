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

/**
 * Draws a ceiling pixel with brightness adjustment. Calculates the pixel's
 * color by blending the ceiling color with the specified brightness. Places
 * the pixel on the background image at position (x, y).
 */
static void	draw_ceiling(t_game *game, int x, int y, float brightness)
{
	uint32_t	pixel_color;
	uint32_t	background_color;

	background_color = game->parser.elem.c_color;
	pixel_color = combiner_hex((uint32_t)(((background_color >> 24) & 0xFF)
				* (brightness)),
			(uint32_t)(((game->parser.elem.c_color >> 16) & 0xFF)
				* (brightness)),
			(uint32_t)(((game->parser.elem.c_color >> 8) & 0xFF)
				* (brightness)), 255);
	mlx_put_pixel(game->img_back, x, y, pixel_color);
}

/**
 * Draws a floor pixel with brightness adjustment. Calculates the pixel's
 * color by blending the floor color with the specified brightness. Places
 * the pixel on the background image at position (x, y).
 */
static void	draw_floor(t_game *game, int x, int y, float brightness)
{
	uint32_t	pixel_color;
	uint32_t	background_color;

	background_color = game->parser.elem.f_color;
	pixel_color = combiner_hex((uint32_t)(((background_color >> 24) & 0xFF)
				* (brightness)),
			(uint32_t)(((game->parser.elem.c_color >> 16) & 0xFF)
				* (brightness)),
			(uint32_t)(((game->parser.elem.c_color >> 8) & 0xFF)
				* (brightness)), 255);
	mlx_put_pixel(game->img_back, x, y, pixel_color);
}

/**
 * Draws the entire background, including the ceiling and floor. Gradually
 * adjusts the brightness of the ceiling and floor based on their distance
 * from the middle of the screen. Calls `draw_ceiling` and `draw_floor` for
 * individual pixel rendering.
 */
void	draw_background(t_game *game)
{
	int			y;
	int			x;
	float		brightness;

	y = -1;
	while (++ y < HEIGHT >> 1)
	{
		brightness = calculate_brightness((float) y, (float)(HEIGHT / 2),
				0.2f);
		x = -1;
		while (++ x < WIDTH)
			draw_ceiling(game, x, y, brightness);
	}
	while (y ++ < HEIGHT)
	{
		x = -1;
		brightness = 1.0f - calculate_brightness((float)(y - HEIGHT / 2),
				(float)(HEIGHT / 2), 0.2f);
		while (++ x < WIDTH)
			draw_floor(game, x, y, brightness);
	}
}
