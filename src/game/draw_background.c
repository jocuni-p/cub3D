/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:19:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/26 13:06:56 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Draws enterely the background image*/
void	draw_background(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT >> 1)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(game->img_back, x, y, game->parser.elem.c_color);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(game->img_back, x, y, game->parser.elem.f_color);
			x++;
		}
		y++;
	}
}
