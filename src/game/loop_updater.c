/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_updater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:42:25 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 13:39:45 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

/*Contains all functions that must be repeated/updated every mlx_loop_hook */
// mlx_image_to_window needs to be used just once at the start of the game
void	loop_updater(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	event_listener(game);
	if (game->is_moving)
	{
		clear_image(game->img_ray, 0x00000000);
		execute_raycasting(game);
	}
	if (game->is_moving)
	{
		clear_image(game->img_mmap, 0x00000000);
		draw_minimap(game);
		game->is_moving = false;
	}
}
