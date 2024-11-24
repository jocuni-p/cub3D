/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:47:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/25 01:44:46 by rzhdanov         ###   ########.fr       */
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

void init_player_values(t_game *game)
{
	game->player.is_running = false; // probably do a standalone init function
									// or rename this one
	game->player.speed = SPEED;
    if (game->player.orientation == 'N')//player looks to NORTH (0, -1)
		set_player_direction_north(game);
	else if (game->player.orientation == 'S')//player looks to SOUTH (0, 1)
		set_player_direction_south(game);
	else if (game->player.orientation == 'E')//player looks to EAST (1, 0)
		set_player_direction_east(game);
	else if (game->player.orientation == 'W')//player looks to WEST (-1, 0)
		set_player_direction_west(game);
}

int	init_game(t_game *game)
{
	game->is_moving = 1;//flag to ensure that the images which have changed will be redrawn on the next loop
	init_player_values(game);
	if (init_textures(game))
		return (1);
	
//==========================BACKGROUND==========================	
	game->img_back = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img_back)
		return (1);
	draw_background(game);
	if (mlx_image_to_window(game->mlx, game->img_back, 0, 0) < 0)
		return (1);
//-----ROMAN, this is just a prove to see the textures,
// please comment this part at your convenience.
//======================textures TEST==========================
	// if (mlx_image_to_window(game->mlx, game->textures.img_e, 100, 250) < 0)
	// 	return (1);
	// if (mlx_image_to_window(game->mlx, game->textures.img_w, 550, 250) < 0)
	// 	return (1);
	// if (mlx_image_to_window(game->mlx, game->textures.img_n, 1000, 250) < 0)
	// 	return (1);
	// if (mlx_image_to_window(game->mlx, game->textures.img_s, 1450, 250) < 0)
	// 	return (1);
//===============================================================
		
		
//=================RAYCASTING - Initial image===================
	game->rays = malloc(sizeof(t_ray) * WIDTH);
	if (!game->rays)
		return (1);
	initialize_array_of_rays(game->rays, WIDTH);
	if (!game->rays)
		return (1);

	game->img_ray = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img_ray)
		return (1);
	draw_raycasting(game);//MISSING CODE
	// printf("called draw_raycasting\n");
	if (mlx_image_to_window(game->mlx, game->img_ray, 0, 0) < 0)
		return (1);

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
	