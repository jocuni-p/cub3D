/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:35:03 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/14 18:35:23 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	minimap(mlx_t *mlx, t_game *game)
{
	mlx_image_t	*mini_map;
	int			x;
	int			y;
	int			j;
	
	x = 0;
	y = 0;
//	j = 5;
	if ((!game->map))
		return (print_error(ERR_GRAPH), 1);
	mini_map = mlx_new_image(mlx, 100, 100);//declaro una imagen
		
	if (!mini_map || (mlx_image_to_window(mlx, mini_map, 0, 0) < 0))//si existe, la coloco en la ventana
		return (print_error(ERR_GRAPH), 1);

	while (game->map[y] != NULL)
	{
		while (game->map[y][x] != '\0')
		{
			j = 0;
			while (j < 5)
			{
				mlx_put_pixel(mini_map, x, y, 0xFF00FFFF);
				j++;
				x++;
			}
		}
		x = 0;
		y++;
	}

/*		while (y < HEIGHT)
		{
			while (x < WIDTH)
			{
				mlx_put_pixel(mini_map, x, y, 0xFFFF00FF);
				x++;
			}
			x = 0;
			y++;
		}*/
	return (0);
}