/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:44:15 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/06 21:09:20 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_bresenham_values(t_game *game)
{
	int	line_length;//length of the minimap player's direction line

	line_length = 20;
	// Centro del minimapa, donde quiero que empieze la linea
	game->mmap.bres.x = (int)game->mmap.pl_screen_x;
	game->mmap.bres.y = (int)game->mmap.pl_screen_y;

    // Calcula el punto final de la línea utilizando la dirección y longitud deseada
    game->mmap.bres.end_x = game->mmap.bres.x + (int)(game->player.dir.x * line_length);
    game->mmap.bres.end_y = game->mmap.bres.y + (int)(game->player.dir.y * line_length);

	// Bresenham's algorithm for drawing lines on a pixel grid from (x, y) til (end_x, end_y)
    game->mmap.bres.d_x = abs(game->mmap.bres.end_x - game->mmap.bres.x);
    game->mmap.bres.d_y = abs(game->mmap.bres.end_y - game->mmap.bres.y);
}

void	draw_minimap_direction_line(t_game *game, uint32_t color)
{
	set_bresenham_values(game);//refers to Bresenham's algorithm
	if (game->mmap.bres.x < game->mmap.bres.end_x)
    	game->mmap.bres.sx = 1;
	else
    	game->mmap.bres.sx = -1;
	if (game->mmap.bres.y < game->mmap.bres.end_y)
		game->mmap.bres.sy = 1;
	else
    	game->mmap.bres.sy = -1;
   game->mmap.bres.err = game->mmap.bres.d_x - game->mmap.bres.d_y;
//Este proceso se repite hasta que x e y llegan al punto final (end_x, end_y), 
//dibujando una línea continua entre el punto inicial y el punto final.
    while (game->mmap.bres.x != game->mmap.bres.end_x || game->mmap.bres.y != game->mmap.bres.end_y)
	{
        mlx_put_pixel(game->img_mmap, game->mmap.bres.x, game->mmap.bres.y, color); // Dibuja el píxel de la línea
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
 	int i;
    int j;

    i = -3;
    while (i < 4)//minimap player size
    {
        j = -3;
        while (j < 4)//minimap player size
        {
                mlx_put_pixel(game->img_mmap, game->mmap.pl_screen_x + i,
				 game->mmap.pl_screen_y + j, color);
            j++;
        }
        i++;
    }
}