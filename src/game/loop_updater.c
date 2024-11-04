/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_updater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:42:25 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/04 18:58:26 by jocuni-p         ###   ########.fr       */
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
//	mlx_image_to_window(game->mlx, game->img_back, 0, 0);//va en la tercera capa


//--------------------RAYCASTING--------------------------
	if (game->is_moving)//si ha habido un movimiento en el juego
	{
		clear_image(game->img_ray, 0x00000000);//Every frame/movement, put all pixels in black color before to be drawn with the right color
//		draw_raycasting(game); Draw walls with raycasting. It is updated every loop/frame
		mlx_image_to_window(game->mlx, game->img_ray, 0, 0);//va en segunda capa
	}

//---------------------MINIMAP----------------------------
	if (game->is_moving)//si ha habido un movimiento en el juego
	{
		clear_image(game->img_mmap, 0x00000000); // Limpia la imagen del minimapa en cada movimiento
		draw_minimap(game);
		mlx_image_to_window(game->mlx, game->img_mmap, 0, 0);//va en primera capa
		game->is_moving = false;
	}
//	printf("%i\n", frame_cnt);
}