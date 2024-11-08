/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:47:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/08 16:46:51 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_textures(t_game *game)
{
	// Try to load the file
	game->textures.text_n = mlx_load_png(game->parser.elem.no);
	game->textures.text_s = mlx_load_png(game->parser.elem.so);
	game->textures.text_e = mlx_load_png(game->parser.elem.ea);
	game->textures.text_w = mlx_load_png(game->parser.elem.we);
	if (!game->textures.text_n || !game->textures.text_s ||
		!game->textures.text_e || !game->textures.text_w)
		return (1);
	// Convert texture to a displayable image
	game->textures.img_n = mlx_texture_to_image(game->mlx,
													game->textures.text_n);
	game->textures.img_s = mlx_texture_to_image(game->mlx,
													game->textures.text_s);
	game->textures.img_e = mlx_texture_to_image(game->mlx,
													game->textures.text_e);
	game->textures.img_w = mlx_texture_to_image(game->mlx,
													game->textures.text_w);
	if (!game->textures.img_n || !game->textures.img_s ||
		!game->textures.img_e || !game->textures.img_w)
        return (1);
	return (0);
}

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

int	init_game(t_game *game)
{
	game->is_moving = 1;//flag to ensure that the images which have changed will be redrawn on the next loop
	set_player_direction(game);
	if (init_textures(game))
		return (1);
	
//==========================BACKGROUND==========================	
	game->img_back = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img_back)
		return (1);
	draw_background(game);
	if (mlx_image_to_window(game->mlx, game->img_back, 0, 0) < 0)
		return (1);
		
//=================RAYCASTING - Initial image===================
/*	game->img_ray = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img_ray)
		return (1);
//	draw_raycasting(game);//MISSING CODE
	if (mlx_image_to_window(game->mlx, game->img_ray, 0, 0) < 0)
		return (1);
*/
//============================MINIMAP===========================
	game->img_mmap = mlx_new_image(game->mlx, (WIDTH / 5), (HEIGHT / 5));
	if (!game->img_mmap)
		return (1);
	draw_minimap(game);
	if (mlx_image_to_window(game->mlx, game->img_mmap, 0, 0) < 0)
		return (1);
		
	return (0);
}

int	start_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	if (!game->mlx)
		return (error_mlx(game), 1);
	if (init_game(game))
		 return (error_mlx(game), 1);
	mlx_loop_hook(game->mlx, loop_updater, game);
	print_game_info(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
	