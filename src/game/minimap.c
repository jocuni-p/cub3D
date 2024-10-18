/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:26:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/18 12:10:40 by jocuni-p         ###   ########.fr       */
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



/*
int	get_ceiling_opposite_color(t_parser *parser)
{
	int	opposite;
	
	opposite = combiner_to_hexcolorformat(-parser->elem.rgb_c[0], \
	-parser->elem.rgb_c[1], -parser->elem.rgb_c[2], 255);
//	ft_printf("ceiling oposite: %X\n", opposite);
	return (opposite);
}*/
int	get_ceiling_opposite_color(t_parser *parser)
{
	int	opposite;

	opposite = combiner_to_hexcolorformat(255 - parser->elem.rgb_c[0], \
		255 - parser->elem.rgb_c[1], 255 - parser->elem.rgb_c[2], 255);
	return (opposite);
}


// Dibuja un tile en la posición x, y dentro de la imagen mini_map
void draw_tile(mlx_image_t *mini_map, int x, int y, uint32_t color)
{
    int i;
    int j;

    i = 0;
    while (i < TILE_SIZE)
    {
        j = 0;
        while (j < TILE_SIZE)
        {
            // Solo dibuja los píxeles que están dentro de los límites del mini_map
            if ((uint32_t)x + i >= 0 && (uint32_t)x + i < mini_map->width && (uint32_t)y + j >= 0 && (uint32_t)y + j < mini_map->height)
                mlx_put_pixel(mini_map, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

// Función modificada para mostrar solo una parte del mapa centrada en el jugador
int minimap(mlx_t *mlx, t_game *game, t_parser *parser)
{
//OJO: max 5 declaradas por funcion, seguramente debere de hacer una struct_minimap que las contenga
    mlx_image_t *mini_map;
    int x, y;
    int row, col;
    int map_offset_x, map_offset_y; // Para centrar al jugador
    int start_col, end_col, start_row, end_row; // Límites de los tiles visibles
    int player_screen_x, player_screen_y; // Posición del jugador dentro del mini_map

    // imagen minimapa.OJO: se eliminara cuando tengamos la img del juego, porque lo pintare encima
    mini_map = mlx_new_image(mlx, 300, 200); // Tamaño del minimapa
    if (!mini_map)
        return (print_error(ERR_GRAPH), 1);

    // Calcular el desplazamiento (offset) para centrar el minimapa en el jugador
    player_screen_x = mini_map->width >> 1; // Jugador en el centro de mini_map (eje X)
    player_screen_y = mini_map->height >> 1; // Jugador en el centro de mini_map (eje Y)
//Sustituir las divisiones por desplazamientos de bits (/2 = >> 1)

    // Calcular la esquina superior izquierda del minimapa en el mapa global
    map_offset_x = game->p_x  * TILE_SIZE - player_screen_x;
    map_offset_y = game->p_y  * TILE_SIZE - player_screen_y;

    // Calcular los límites de las filas y columnas que deben dibujarse
    start_col = map_offset_x / TILE_SIZE;
    end_col = (map_offset_x + mini_map->width) / TILE_SIZE;
    start_row = map_offset_y / TILE_SIZE;
    end_row = (map_offset_y + mini_map->height) / TILE_SIZE;
	
    // Asegurar que los valores no se salgan de los límites del mapa
    if (start_row < 0)
		start_row = 0;
    if (start_col < 0)
		start_col = 0;
    if (end_row >= parser->map.h)
		end_row = parser->map.h - 1;
    if (end_col >= parser->map.w)
		end_col = parser->map.w - 1;
	
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
                draw_tile(mini_map, x, y, get_ceiling_opposite_color(parser));

            col++;
        }
        row++;
    }

    // Dibujar la posición del jugador centrada en el minimapa (>> 1 == / 2)
//    draw_tile(mini_map, player_screen_x - TILE_SIZE / 2, player_screen_y - TILE_SIZE / 2, 0xFFFFFFFF);
	draw_tile(mini_map, player_screen_x, player_screen_y, 0xFFFFFFFF);

	// Pinta contorno frame mini_map
	draw_mini_map_frame(mini_map, 0, 0, 0xFFFFFFFF);//get_ceiling_oposite_color(parser));
//	ft_printf("ceiling opposite: %X\n", get_ceiling_opposite_color(parser));
	
    // Mostrar minimapa en ventana. Eliminare cuando tenga la img del juego
    if (mlx_image_to_window(mlx, mini_map, 20, 20) < 0)
        return (print_error(ERR_GRAPH), 1);

    return (0);
}
