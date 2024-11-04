/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:47:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/04 11:31:17 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void set_player_direction(t_game *game)
{
    if (game->player.orientation == 'N')//player looks to NORTH (0, -1)
	{
        game->player.dir.x = 0;
        game->player.dir.y = -1;
    }
	else if (game->player.orientation == 'S')//player looks to SOUTH (0, 1)
	{
        game->player.dir.x = 0;
        game->player.dir.y = 1;
    }
	else if (game->player.orientation == 'E')//player looks to EAST (1, 0)
	{
        game->player.dir.x = 1;
        game->player.dir.y = 0;
    }
	else if (game->player.orientation == 'W')//player looks to WEST (-1, 0)
	{
        game->player.dir.x = -1;
        game->player.dir.y = 0;
    }
}

int	init_game(mlx_t *mlx, t_game *game)
{
	game->mlx = mlx;
	game->is_moving = 1;//flag to ensure that the images will be redrawn every loop
//	game->player.dir.x = 0;
//	game->player.dir.y = -1;
	set_player_direction(game);
	
/*==========================BACKGROUND==========================*/	
	game->img_back = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img_back)
		return (error_mlx(game), 1);
	draw_background(game);
	if (mlx_image_to_window(game->mlx, game->img_back, 0, 0) < 0)
		return (error_mlx(game), 1);

/*======TEMPORAL - JUST TO SHOW THE TEXTURE IMAGES==============*/
	if (textures_test(game))
		return (error_mlx(game), 1);
	
/*=================RAYCASTING - Initial image===================*/
	game->img_ray = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img_ray)
		return (error_mlx(game), 1);
//	draw_raycasting(game);//MISSING CODE
	if (mlx_image_to_window(game->mlx, game->img_ray, 0, 0) < 0)
		return (error_mlx(game), 1);

/*============================MINIMAP===========================*/
	game->img_mmap = mlx_new_image(game->mlx, (WIDTH / 5), (HEIGHT / 5));
	if (!game->img_mmap)
		return (error_mlx(game), 1);
	draw_minimap(game);
	if (mlx_image_to_window(game->mlx, game->img_mmap, 0, 0) < 0)
		return (error_mlx(game), 1);
		
	return (0);
}

int	start_game(t_game *game)
{
	mlx_t *mlx;
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	if (!mlx)
		return (error_mlx(game), 1);
	if (init_game(mlx, game))
		 return (error_mlx(game), 1);
	mlx_loop_hook(mlx, loop_updater, game);
	print_game_info(game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
	