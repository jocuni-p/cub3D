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

#include "../include/cub3d.h"

/* Draws a tile on the mini_map image at x, y position.*/
void draw_minimap_tile(mlx_image_t *img_mmap, uint32_t x, uint32_t y,
						 uint32_t color)
{
    uint32_t	i;
    uint32_t	j;

    i = 0;
    while (i < TILE_SIZE)
    {
        j = 0;
        while (j < TILE_SIZE)
        {
            //Draws only the pixels located inside the mini_map limits
            if ((uint32_t)x + i >= 0 && (uint32_t)x + i < img_mmap->width \
			&& (uint32_t)y + j >= 0 && (uint32_t)y + j < img_mmap->height)
                mlx_put_pixel(img_mmap, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void	draw_minimap_player(mlx_image_t *img_mmap, uint32_t x, uint32_t y,
							 uint32_t color)
{
 	int i;
    int j;

    i = 0;
    while (i < 4)//player will have 4 pix high
    {
        j = 0;
        while (j < 4)//player will have 4 pix wide
        {
            // Solo dibuja los píxeles que están dentro de los límites del mini_map
//            if ((uint32_t)x + i >= 0 && (uint32_t)x + i < img_mmap->width \
//			&& (uint32_t)y + j >= 0 && (uint32_t)y + j < img_mmap->height)
                mlx_put_pixel(img_mmap, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void	draw_minimap_frame(mlx_image_t *img_mmap, uint32_t x, uint32_t y,
							 uint32_t color)
{
	while (y < 200)
	{
		x = 0;
		while (x < 300)
		{
			if (y == 0 || y == 199)
			{
				 mlx_put_pixel(img_mmap, x, y, color);
				 x++;
			}
			else
			{
				mlx_put_pixel(img_mmap, 0, y, color);
				mlx_put_pixel(img_mmap, 299, y, color);
				x = 300;
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
            // Calcular la posición del tile en la imagen del minimapa
            game->mmap.x \
			= (game->mmap.col * TILE_SIZE) - game->mmap.map_offset_x;
            game->mmap.y \
			= (game->mmap.row * TILE_SIZE) - game->mmap.map_offset_y;
            // Dibujar el tile solo si está dentro de los límites del minimapa
        	if (game->mmap.x >= 0 && game->mmap.x < game->img_mmap->width \
			&& game->mmap.y >= 0 && game->mmap.y < game->img_mmap->height)
			{
            	if (game->map_arr[game->mmap.row][game->mmap.col] == '1' \
				|| game->map_arr[game->mmap.row][game->mmap.col] == ' ')
					draw_minimap_tile(game->img_mmap, game->mmap.x,
					 game->mmap.y, game->parser.elem.c_opposite);
            }
            game->mmap.col++;
        }
        game->mmap.row++;
    }
}

void draw_minimap(t_game *game)
{
    // Calcular la posición del jugador en el minimapa (centro)
    game->mmap.pl_screen_x = game->img_mmap->width >> 1;
    game->mmap.pl_screen_y = game->img_mmap->height >> 1;

    // Calcular el desplazamiento del mapa para centrar el minimapa en el jugador
	//ESTE ES EL PARAM QUE HACE MOVER EL MAP DENTRO DEL MINIMAP
    game->mmap.map_offset_x = (game->pl_orig[0] * TILE_SIZE) -\
								 game->mmap.pl_screen_x;
    game->mmap.map_offset_y = (game->pl_orig[1] * TILE_SIZE) -\
								 game->mmap.pl_screen_y;

    // Calcular los límites de las filas y columnas que deben dibujarse
	// Calcular columna de inicio
	if (game->mmap.map_offset_x < 0)
	    game->mmap.start_col = 0;  // Si el offset es negativo, comenzamos desde la primera columna
	else
	    game->mmap.start_col = game->mmap.map_offset_x / TILE_SIZE;  // Si es positivo, calculamos la columna correspondiente
	// Calcular fila de inicio
	if (game->mmap.map_offset_y < 0)
	    game->mmap.start_row = 0;  // Si el offset es negativo, comenzamos desde la primera fila
	else
	    game->mmap.start_row = game->mmap.map_offset_y / TILE_SIZE;  // Si es positivo, calculamos la fila correspondiente
	// Calcular columna de final
    game->mmap.end_col = ((game->mmap.map_offset_x +\
						 game->img_mmap->width) / TILE_SIZE);
	// Calcular fila de final
    game->mmap.end_row = ((game->mmap.map_offset_y +\
						 game->img_mmap->height) / TILE_SIZE);

	print_minimap_vars(game);//DEBUG

    // Dibujar los tiles visibles en el minimapa
	draw_minimap_only_visible_tiles(game);
	
    // Dibujar la posición del jugador centrada en el minimapa
    draw_minimap_player(game->img_mmap, game->mmap.pl_screen_x + 3,
						 game->mmap.pl_screen_y + 2, 0x000000FF);
    
    // Dibujar el marco del minimapa
   draw_minimap_frame(game->img_mmap, 0, 0, 0x000000FF);
}
