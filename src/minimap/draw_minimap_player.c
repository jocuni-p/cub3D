/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:44:15 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 15:56:01 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_bresenham_values(t_game *game)
{
	int	line_length;

	line_length = 20;
	game->mmap.bres.x = (int)game->mmap.pl_screen_x;
	game->mmap.bres.y = (int)game->mmap.pl_screen_y;
	game->mmap.bres.end_x = game->mmap.bres.x
		+ (int)(game->player.dir.x * line_length);
	game->mmap.bres.end_y = game->mmap.bres.y
		+ (int)(game->player.dir.y * line_length);
	game->mmap.bres.d_x = abs(game->mmap.bres.end_x - game->mmap.bres.x);
	game->mmap.bres.d_y = abs(game->mmap.bres.end_y - game->mmap.bres.y);
}

void	update_bresenham_values(t_game *game)
{
	if (game->mmap.bres.x < game->mmap.bres.end_x)
		game->mmap.bres.sx = 1;
	else
		game->mmap.bres.sx = -1;
	if (game->mmap.bres.y < game->mmap.bres.end_y)
		game->mmap.bres.sy = 1;
	else
		game->mmap.bres.sy = -1;
	game->mmap.bres.err = game->mmap.bres.d_x - game->mmap.bres.d_y;
}

void	draw_minimap_direction_line(t_game *game, uint32_t color)
{
	set_bresenham_values(game);
	update_bresenham_values(game);
	while (game->mmap.bres.x != game->mmap.bres.end_x
		|| game->mmap.bres.y != game->mmap.bres.end_y)
	{
		mlx_put_pixel(game->img_mmap, game->mmap.bres.x,
			game->mmap.bres.y, color);
		game->mmap.bres.e2 = 2 * game->mmap.bres.err;
		if (game->mmap.bres.e2 > -game->mmap.bres.d_y)
		{
			game->mmap.bres.err -= game->mmap.bres.d_y;
			game->mmap.bres.x += game->mmap.bres.sx;
		}
		if (game->mmap.bres.e2 < game->mmap.bres.d_x)
		{
			game->mmap.bres.err += game->mmap.bres.d_x;
			game->mmap.bres.y += game->mmap.bres.sy;
		}
	}
}

void	draw_minimap_player(t_game *game, uint32_t color)
{
	int	i;
	int	j;

	i = -3;
	while (i < 4)
	{
		j = -3;
		while (j < 4)
		{
			mlx_put_pixel(game->img_mmap, game->mmap.pl_screen_x + i,
				game->mmap.pl_screen_y + j, color);
			j++;
		}
		i++;
	}
}
