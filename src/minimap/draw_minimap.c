/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:26:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/26 14:40:05 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Draws a tile on the mini_map image at x, y position.*/
void	draw_minimap_tile(mlx_image_t *img_mmap, uint32_t x, uint32_t y,
						uint32_t color)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < MINIMAP_TILE_SIZE)
	{
		j = 0;
		while (j < MINIMAP_TILE_SIZE)
		{
			if ((uint32_t)x + i < img_mmap->width \
			&& (uint32_t)y + j < img_mmap->height)
				mlx_put_pixel(img_mmap, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap_frame(mlx_image_t *img_mmap, uint32_t x, uint32_t y,
							uint32_t color)
{
	while (y < (HEIGHT / 5))
	{
		x = 0;
		while (x < (WIDTH / 5))
		{
			if (y == 0 || y == ((HEIGHT / 5) - 1))
			{
				mlx_put_pixel(img_mmap, x, y, color);
				x++;
			}
			else
			{
				mlx_put_pixel(img_mmap, 0, y, color);
				mlx_put_pixel(img_mmap, ((WIDTH / 5) - 1), y, color);
				x = (WIDTH / 5);
			}
		}
		y++;
	}
}

/*Draws the visible part of the map into the minimap*/
void	draw_minimap_only_visible_tiles(t_game *game)
{
	game->mmap.row = game->mmap.start_row;
	while (game->mmap.row <= game->mmap.end_row \
	&& game->map_arr[game->mmap.row] != NULL)
	{
		game->mmap.col = game->mmap.start_col;
		while (game->mmap.col <= game->mmap.end_col \
		&& game->map_arr[game->mmap.row][game->mmap.col] != '\0')
		{
			game->mmap.x = (game->mmap.col
					* MINIMAP_TILE_SIZE) - game->mmap.map_offset_x;
			game->mmap.y = (game->mmap.row
					* MINIMAP_TILE_SIZE) - game->mmap.map_offset_y;
			if (game->mmap.x < game->img_mmap->width
				&& game->mmap.y < game->img_mmap->height)
			{
				if (game->map_arr[game->mmap.row][game->mmap.col] == '1'
				|| game->map_arr[game->mmap.row][game->mmap.col] == ' ')
					draw_minimap_tile(game->img_mmap, game->mmap.x,
						game->mmap.y, game->parser.elem.c_opposite);
			}
			game->mmap.col++;
		}
		game->mmap.row++;
	}
}

void	draw_minimap(t_game *game)
{
	game->mmap.pl_screen_x = game->img_mmap->width >> 1;
	game->mmap.pl_screen_y = game->img_mmap->height >> 1;
	game->mmap.map_offset_x = (int)(game->player.pos.x * MINIMAP_TILE_SIZE)
		- (game->img_mmap->width / 2);
	game->mmap.map_offset_y = (int)(game->player.pos.y * MINIMAP_TILE_SIZE)
		- (game->img_mmap->height / 2);
	if (game->mmap.map_offset_x < 0)
		game->mmap.start_col = 0;
	else
		game->mmap.start_col = game->mmap.map_offset_x / MINIMAP_TILE_SIZE;
	if (game->mmap.map_offset_y < 0)
		game->mmap.start_row = 0;
	else
		game->mmap.start_row = game->mmap.map_offset_y / MINIMAP_TILE_SIZE;
	game->mmap.end_col = ((game->mmap.map_offset_x
				+ game->img_mmap->width) / MINIMAP_TILE_SIZE);
	game->mmap.end_row = ((game->mmap.map_offset_y
				+ game->img_mmap->height) / MINIMAP_TILE_SIZE);
	draw_minimap_only_visible_tiles(game);
	draw_minimap_player(game, 0x000000FF);
	draw_minimap_direction_line(game, 0x000000FF);
	draw_minimap_frame(game->img_mmap, 0, 0, 0x000000FF);
}
