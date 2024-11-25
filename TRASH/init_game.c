/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:45:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/25 04:22:46 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
void reset_player_direction(t_game *game, char orientation)
{
    if (orientation == 'N') {
        game->player.dir.x = 0;
        game->player.dir.y = -1;
    } else if (orientation == 'S') {
        game->player.dir.x = 0;
        game->player.dir.y = 1;
    } else if (orientation == 'E') {
        game->player.dir.x = 1;
        game->player.dir.y = 0;
    } else if (orientation == 'W') {
        game->player.dir.x = -1;
        game->player.dir.y = 0;
    }
}*/

int	init_game(mlx_t *mlx, t_game *game)
{
	game->mlx = mlx;
	game->is_moving = 1;//it means that the images must be redrawn 
	game->player.dir.x = 0;//player looks to EAST (1, 0) as a starting value
	game->player.dir.y = -1;
//	reset_player_direction(game, game->player.orientation);
	
	
/*=========================BACKGROUND=========================*/	
	game->img_back = mlx_new_image(mlx, 1000, 500);
	if (!game->img_back)
		return (error(game), 1);
	draw_background(game);
	if (mlx_image_to_window(game->mlx, game->img_back, 0, 0) < 0)
		return (error(game), 1);


/*========================RAYCASTING===========================*/
//	game->img_ray = mlx_new_image(mlx, 1000, 500);
//	if (!game->img_ray)
//		return (error(), 1);
//	execute_raycasting(game);


/*============================MINIMAP===========================*/
	game->img_mmap = mlx_new_image(mlx, (WIDTH / 5), (HEIGHT / 5));
	if (!game->img_mmap)
		return (error(game), 1);
	draw_minimap(game);
	if (mlx_image_to_window(game->mlx, game->img_mmap, 0, 0) < 0);
		return (error(game), 1);
		
	return (0);
}
