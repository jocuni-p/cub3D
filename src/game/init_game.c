/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:45:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/25 23:29:04 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_game(mlx_t *mlx, t_game *game)
{
//	printf("map_w: %d, map_h: %d\n", game->map_w, game->map_h);//DEBUG
	game->mlx = mlx;
//	game->map_arr = game->parser.raw_map;//OJO: de momento lo conservo, pero es duplicado
//	game->map_w = game->parser.map.w;//OJO: de momento lo conservo, pero es duplicado
//	game->map_h = game->parser.map.h;//OJO: de momento lo conservo, pero es duplicado
//	game->p_x = game->parser.map.ply_x;//OJO: de momento lo conservo, pero es duplicado
//	game->p_y = game->parser.map.ply_y;//OJO: de momento lo conservo, pero es duplicado
//	game->p_view = game->parser.map.ply_view;//OJO: de momento lo conservo, pero es duplicado
	
/*-----Background img declaration, painting and putting into the mlx window-------*/	
	game->img_back = mlx_new_image(mlx, 1000, 500);
	if (!game->img_back)
		return (error(), 1);
	draw_img_background(game);
	mlx_image_to_window(game->mlx, game->img_back, 0, 0);

//	printf("intit_game_debug\n");//DEBUG
	
/*-----RAYCASTING img declaration, painting and putting into the mlx window-------*/
//	game->img_ray = mlx_new_image(mlx, 1000, 500);
//	if (!game->img_ray)
//		return (error(), 1);
//	draw_img_raycasting(game);/*---RAYCASTING CODE IS PENDING------*/

/*-----minimap img declaration, painting and putting into the mlx window-------*/
	game->img_mmap = mlx_new_image(mlx, 300, 200);
	if (!game->img_mmap)
		return (error(), 1);
	draw_img_minimap(game);
	mlx_image_to_window(game->mlx, game->img_mmap, 0, 0);


//	printf("init_game\n");//DEBUG
	return (0);
}
