/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:45:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/23 16:48:36 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Draws enterely the background image*/
void draw_img_background(t_game *game)
{
    int y;
    int x;

	y = 0;
	while (y < HEIGHT / 2)//provar si funciona con >> 1
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(game->img_backgr, x, y, game->parser.elem.c_color);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(game->img_backgr, x, y, game->parser.elem.f_color);
			x++;
		}
		y++;
	}
}


int	init_game(mlx_t *mlx, t_game *game, t_parser *parser)
{
	game->map = parser->raw_map;
	game->p_x = parser->map.player_x;
	game->p_y = parser->map.player_y;
	game->p_view = parser->map.player_view;
	game->mlx = mlx;
	game->img_backgr = mlx_new_image(mlx, 1000, 500);
	game->img_raycasting = mlx_new_image(mlx, 1000, 500);
	game->img_minimap = mlx_new_image(mlx, 300, 200);
	if (!game->img_backgr || !game->img_raycasting || !game->img_minimap)
		return (error(), 1);
	draw_img_background(game);
	draw_img_minimap(game);//draw the initial minimap
//	game->no = parser->elem.no;
//	game->so = parser->elem.so;
//	game->ea = parser->elem.ea;
//	game->we = parser->elem.we;
//	game->c_opposite = get_opposite_color(parser);
	return (0);
	
}
