/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:35:03 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/17 13:38:07 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../include/cub3d.h"

int	get_ceiling_oposite_color(t_parser *parser)
{
	int	oposit;
	
	oposit = combiner_to_hexcolorformat(-parser->elem.rgb_c[0], \
	-parser->elem.rgb_c[1], -parser->elem.rgb_c[2], 255);
	return (oposit);
}
/*Draws a square of TILE_SIZE pixels on the position x, y*/
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

int	minimap(mlx_t *mlx, t_game *game, t_parser *parser)
{
	mlx_image_t	*mini_map;
	int			x;
	int			y;
	int			row;
	int			col;
	
	row = 0;
	mini_map = mlx_new_image(mlx, 300, 200);//declares an image (mini_map)
	if (!mini_map)
		return (print_error(ERR_GRAPH), 1);
//Recorremos el array del mapa para pintarlo
	while (game->map[row] != NULL)
	{
		col = 0;
		while (game->map[row][col] != '\0')
		{
//Calcula la pos x, y en la ventana
			x = col * TILE_SIZE;
			y = row * TILE_SIZE;
//If the position in the array is '1' or ' ' paints that position on the image 'mini_map' with the ceiling oposite color
			if (game->map[row][col] == '1' || game->map[row][col] == ' ')
				draw_tile(mini_map, x, y, get_ceiling_oposite_color(parser));
			col++;
		}
		row++;
	}
//Paints the player tile position
	draw_tile(mini_map, game->p_x * TILE_SIZE, game->p_y * TILE_SIZE, 0x00FF00FF);
	
	if (mlx_image_to_window(mlx, mini_map, 10, 10) < 0)//Draws a new instance of the window with 'mini_map' image added
		return (print_error(ERR_GRAPH), 1);
	return (0);
}
