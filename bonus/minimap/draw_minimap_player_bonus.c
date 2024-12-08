/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:44:15 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/01 23:53:19 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

/**
 * Sets the initial values for drawing a direction line on the minimap
 * using Bresenham's line algorithm. Calculates the start and end points
 * of the line based on the player's position and direction. Computes
 * differences (`d_x` and `d_y`) between the start and end points.
 */
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

/**
 * Updates Bresenham's line-drawing values for step directions and error
 * handling. Determines the step increments (`sx`, `sy`) based on the
 * relationship between start and end points. Calculates the initial
 * error term.
 */
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

/**
 * Draws a direction line on the minimap representing the player's facing
 * direction. Uses Bresenham's line algorithm to plot pixels from the
 * player's position to the end of the line. Calls helper functions to
 * initialize and update Bresenham's values. Colors each pixel with the
 * given color.
 */
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

/**
 * Draws the player's position on the minimap as a small square. Plots
 * pixels in a 7x7 grid around the player's center position. Colors all
 * pixels with the specified color.
 */
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
