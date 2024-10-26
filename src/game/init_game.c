/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:45:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/26 16:01:23 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_game(mlx_t *mlx, t_game *game)
{
	game->mlx = mlx;
	
/*-----BACKGROUND img declaration, painting and putting into the mlx window-------*/	
	game->img_back = mlx_new_image(mlx, 1000, 500);
	if (!game->img_back)
		return (error(), 1);
	draw_background(game);
	mlx_image_to_window(game->mlx, game->img_back, 0, 0);
	
/*-----RAYCASTING img declaration, painting and putting into the mlx window-------*/
//	game->img_ray = mlx_new_image(mlx, 1000, 500);
//	if (!game->img_ray)
//		return (error(), 1);
//	draw_img_raycasting(game);/*---RAYCASTING CODE IS PENDING------*/

/*-----MINIMAP img declaration, painting and putting into the mlx window-------*/
	game->img_mmap = mlx_new_image(mlx, 300, 200);
	if (!game->img_mmap)
		return (error(), 1);
	draw_minimap(game);
	mlx_image_to_window(game->mlx, game->img_mmap, 0, 0);

//	printf("init_game\n");//DEBUG
	return (0);
}
