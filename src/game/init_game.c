/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:45:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/24 23:13:26 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_game(mlx_t *mlx, t_game *game, t_parser *parser)
{
	printf("parser->map.w: %d, h: %d\n", parser->map.w, parser->map.h);//DEBUG
	game->map_arr = parser->raw_map;
	game->map_w = parser->map.w;
	game->map_h = parser->map.h;
	printf("game->map_w: %d, h: %d\n", game->map_w, game->map_h);
	game->p_x = parser->map.player_x;
	game->p_y = parser->map.player_y;
	game->p_view = parser->map.player_view;
	game->mlx = mlx;
	
/*-----Background img declaration, painting and putting into the mlx window-------*/	
	game->img_backgr = mlx_new_image(mlx, 1000, 500);
	if (!game->img_backgr)
		return (error(), 1);
	draw_img_background(game);
	mlx_image_to_window(game->mlx, game->img_backgr, 0, 0);

//	printf("intit_game_debug\n");//DEBUG
	
/*-----RAYCASTING img declaration, painting and putting into the mlx window-------*/
//	game->img_raycasting = mlx_new_image(mlx, 1000, 500);
//	if (!game->img_raycasting)
//		return (error(), 1);
/*---To draw the RAYCASTING img is code pending------*/

/*-----minimap img declaration, painting and putting into the mlx window-------*/
	game->img_minimap = mlx_new_image(mlx, 300, 200);
	if (!game->img_minimap)
		return (error(), 1);
	draw_img_minimap(game);
	mlx_image_to_window(game->mlx, game->img_minimap, 0, 0);


//	printf("init_game\n");//DEBUG
	return (0);
}
