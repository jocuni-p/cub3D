/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_updater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:42:25 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/02 22:01:30 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * Clears an image by setting all its pixels to a specified color. Loops
 * through each pixel in the image's width and height. Calls `mlx_put_pixel`
 * for every pixel to apply the color. Ensures the entire image is uniform
 * with the given color.
 */

void	clear_image(mlx_image_t *img, uint32_t color)
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

/**
 * Handles game loop updates. Processes input events with `event_listener`.
 * Clears raycasting and minimap images if movement is detected. Executes
 * raycasting to update the view. Redraws the minimap to reflect changes.
 * Resets the movement flag (`is_moving`) after updates. Ensures the screen
 * is refreshed correctly after every frame.
 */

void	loop_updater(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	event_listener(game);
	if (game->is_moving)
	{
		clear_image(game->img_ray, TRANSPARENT);
		execute_raycasting(game);
	}
	if (game->is_moving)
	{
		clear_image(game->img_mmap, TRANSPARENT);
		draw_minimap(game);
		game->is_moving = false;
	}
}
