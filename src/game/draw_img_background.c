/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:19:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/24 23:04:58 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Draws enterely the background image*/
void draw_img_background(t_game *game)
{
    int y;
    int x;
	printf("draw_img_background_debug\n");//DEBUG
	y = 0;
	while (y < HEIGHT / 2)//provar si funciona con >> 1
	{
		x = 0;
		while (x < WIDTH)
		{
//			mlx_put_pixel(game->img_backgr, x, y, game->parser.elem.c_color);
			mlx_put_pixel(game->img_backgr, x, y, 0x7ecdf1ff);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
//			mlx_put_pixel(game->img_backgr, x, y, game->parser.elem.f_color);
			mlx_put_pixel(game->img_backgr, x, y, 0x8e6a78ff);
			x++;
		}
		y++;
	}
}