/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:26:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/23 18:32:52 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_mini_map_frame(mlx_image_t *mini_map, int x, int y, uint32_t color)
{
	while (y < 200)
	{
		x = 0;
		while (x < 300)
		{
			if (y == 0 || y == 199)
			{
				 mlx_put_pixel(mini_map, x, y, color);
				 x++;
			}
			else
			{
				mlx_put_pixel(mini_map, 0, y, color);
				mlx_put_pixel(mini_map, 299, y, color);
				x = 300;
			}	
		}
		y++;
	}
}

/* Draws a tile on the mini_map image at x, y position.*/
void draw_minimap_tile(mlx_image_t *game_img, int x, int y, uint32_t color)
{
    int i;
    int j;

    i = 0;
    while (i < TILE_SIZE)
    {
        j = 0;
        while (j < TILE_SIZE)
        {
            //Draws only the pixels located inside the mini_map limits
            if ((uint32_t)x + i >= 0 && (uint32_t)x + i < game_img->width \
			&& (uint32_t)y + j >= 0 && (uint32_t)y + j < game_img->height)
                mlx_put_pixel(game_img, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void	draw_player_tile(mlx_image_t *game_img, int x, int y, uint32_t color)
{
 	int i;
    int j;

    i = 0;
    while (i < 4)//player will be 4 pix high
    {
        j = 0;
        while (j < 4)//player will be 4 pix wide
        {
            // Solo dibuja los píxeles que están dentro de los límites del mini_map
            if ((uint32_t)x + i >= 0 && (uint32_t)x + i < game_img->width \
			&& (uint32_t)y + j >= 0 && (uint32_t)y + j < game_img->height)//Creo que puedo prescindir de esta condicion??
                mlx_put_pixel(game_img, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

/*Draws a small image of the map. The player keeps centered all time and the 
map moves around it. Map color is the opposite to the ceiling color to get a 
better visual effect.*/
void draw_img_minimap(t_game *game)
{
    int x, y;
    int row, col;
    int map_offset_x, map_offset_y; // Para centrar al jugador
    int start_col, end_col, start_row, end_row; // Límites de los tiles visibles
    int player_screen_x, player_screen_y; // Posición del jugador dentro del mini_map

    // Calcular el desplazamiento (offset) para centrar el minimapa en el jugador
    player_screen_x = (int)game->img_minimap->width >> 1; // Jugador en el centro de mini_map (eje X)
    player_screen_y = (int)game->img_minimap->height >> 1; // Jugador en el centro de mini_map (eje Y)
	//Sustituir las divisiones por desplazamientos de bits (/2 = >> 1)

    // Calcular la esquina superior izquierda del minimapa en el mapa global
    map_offset_x = game->p_x  * TILE_SIZE - player_screen_x;
    map_offset_y = game->p_y  * TILE_SIZE - player_screen_y;

    // Calcular los límites de las filas y columnas que deben dibujarse
    start_col = map_offset_x / TILE_SIZE;
    end_col = (map_offset_x + game->img_minimap->width) / TILE_SIZE;
    start_row = map_offset_y / TILE_SIZE;
    end_row = (map_offset_y + game->img_minimap->height) / TILE_SIZE;
	
    // Asegurar que los valores no se salgan de los límites del mapa
    if (start_row < 0)
		start_row = 0;
    if (start_col < 0)
		start_col = 0;
    if (end_row >= game->parser.map.h)
		end_row = game->parser.map.h - 1;
    if (end_col >= game->parser.map.w)
		end_col = game->parser.map.w - 1;
	
    // Dibujar los tiles visibles en el minimapa
    row = start_row;
    while (row <= end_row && game->map[row] != NULL)
    {
        col = start_col;
        while (col <= end_col && game->map[row][col] != '\0')
        {
            // Calcular la posición del tile en la imagen del minimapa
            x = (col * TILE_SIZE) - map_offset_x;
            y = (row * TILE_SIZE) - map_offset_y;

            // Si el tile es una pared o un espacio, lo dibuja
            if (game->map[row][col] == '1' || game->map[row][col] == ' ')
//              draw_tile(mini_map, x, y, get_ceiling_opposite_color(parser));
				draw_minimap_tile(game->img_minimap, x, y, game->parser.elem.c_opposite);
            col++;
        }
        row++;
    }
	printf("Tile: row: %d, col: %d, x: %d, y: %d\n", row, col, x, y);//DEBUG

    // Dibujar la posición del jugador centrada en el minimapa (>> 1 == / 2)
//    draw_tile(mini_map, player_screen_x - TILE_SIZE / 2, player_screen_y - TILE_SIZE / 2, 0xFFFFFFFF);
	draw_player_tile(game->img_minimap, player_screen_x + 3, player_screen_y + 2, 0xFFFFFFFF);//algo desplazado respecto al mapa, lo centro con +3 y +2

	// Draws a white frame surrounding the mini_map
	draw_mini_map_frame(game->img_minimap, 0, 0, 0xFFFFFFFF);
}
