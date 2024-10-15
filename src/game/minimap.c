/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:35:03 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/15 14:46:57 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Draws a square on the position x, y*/
void	draw_tile (mlx_image_t *mini_map, int x, int y, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx_put_pixel(mini_map, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

int	minimap(mlx_t *mlx, t_game *game)
{
	mlx_image_t	*mini_map;
	int			x;
	int			y;
	int			raw;
	int			col;
	
	raw = 0;
	mini_map = mlx_new_image(mlx, 800, 800);//declaro una imagen
	if (!mini_map)
		return (print_error(ERR_GRAPH), 1);
//Recorremos el array del mapa
	while (game->map[raw] != NULL)
	{
		col = 0;
		while (game->map[raw][col] != '\0')
		{
//Calcula la pos x, y en la ventana
			x = col * TILE_SIZE;
			y = raw * TILE_SIZE;
//Dibuja dependiendo de si es un '1', un ' ' o un player
			if (game->map[raw][col] == '1' || game->map[raw][col] == ' ')
				draw_tile(mini_map, x, y, 0xFF00FFFF);
			if (game->map[raw][col] == 'N' || game->map[raw][col] == 'S' \
			|| game->map[raw][col] == 'W' || game->map[raw][col] == 'E')
				draw_tile(mini_map, x, y, 0x00FF00FF);
			col++;
		}
		raw++;
	}
	if (mlx_image_to_window(mlx, mini_map, 0, 0) < 0)//si existe, la coloco en la ventana
		return (print_error(ERR_GRAPH), 1);
	return (0);
}