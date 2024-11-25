/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_updater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:42:25 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/25 03:43:20 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void clear_image(mlx_image_t *img, uint32_t color)
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

/*Contains all functions that must be repeated/updated every mlx_loop_hook */
void	loop_updater(void *param)
{
	t_game *game = (t_game *)param;
	
	event_listener(game);
	
//--------------------BACKGROUND--------------------------
//Esta imagen no deberia actualizarse aqui porque siempre es igual
//	mlx_image_to_window(game->mlx, game->img_back, 0, 0);//deeper layer


// //--------------------RAYCASTING--------------------------
	if (game->is_moving)//if any key has been pressed
	{
		clear_image(game->img_ray, 0x00000000);//Every frame/movement, put all pixels in black color before to be drawn with the right color
		execute_raycasting(game); //Draw walls with raycasting. It is updated every loop/frame
		// mlx_image_to_window(game->mlx, game->img_ray, 0, 0);//middle layer
	}

//---------------------MINIMAP----------------------------
	if (game->is_moving)//if any key has been pressed
	{
		clear_image(game->img_mmap, 0x00000000); // Clears the minimap image when a key is pressed
		draw_minimap(game);
		// mlx_image_to_window(game->mlx, game->img_mmap, 0, 0);//superficial layer
		game->is_moving = false;
	}
}
