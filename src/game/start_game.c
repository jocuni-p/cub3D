/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:47:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/01 21:48:27 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Loads textures for the game. Reads texture file paths from the parser
 * and loads them as PNGs using `mlx_load_png`. Converts the textures to
 * images with `mlx_texture_to_image`. Returns 1 if any texture fails to
 * load or convert, otherwise returns 0.
 */
int	init_textures(t_game *game)
{
	game->textures.text_n = mlx_load_png(game->parser.elem.no);
	game->textures.text_s = mlx_load_png(game->parser.elem.so);
	game->textures.text_e = mlx_load_png(game->parser.elem.ea);
	game->textures.text_w = mlx_load_png(game->parser.elem.we);
	if (!game->textures.text_n || !game->textures.text_s
		|| !game->textures.text_e || !game->textures.text_w)
		return (1);
	game->textures.img_n = mlx_texture_to_image(game->mlx,
			game->textures.text_n);
	game->textures.img_s = mlx_texture_to_image(game->mlx,
			game->textures.text_s);
	game->textures.img_e = mlx_texture_to_image(game->mlx,
			game->textures.text_e);
	game->textures.img_w = mlx_texture_to_image(game->mlx,
			game->textures.text_w);
	if (!game->textures.img_n || !game->textures.img_s
		|| !game->textures.img_e || !game->textures.img_w)
		return (1);
	return (0);
}

/**
 * Initializes player-related values. Sets default movement speed,
 * rotation speed, and running state. Resets the player's direction
 * based on their orientation using `reset_player_direction`.
 */
void	init_player_values(t_game *game)
{
	game->player.is_running = false;
	game->player.speed = SPEED;
	game->player.rotation_speed = ROTATION_SPEED;
	reset_player_direction(game);
}

/**
 * Allocates memory for the raycasting structure. Returns 1 if memory
 * allocation fails, otherwise returns 0.
 */
int	init_ray(t_game *game)
{
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
		return (1);
	return (0);
}

/**
 * Initializes the game. Sets up textures, player values, background,
 * raycasting, and minimap images. Loads all graphical elements into
 * the game window. Returns 1 if any initialization step fails,
 * otherwise returns 0.
 *
 * There are 3 different images into the game window:
 * -The background image, drawing half ceiling and 
 *  half floor, displayed into the last window layer
 * -The raycasting image, drawing the walls in the 
 *  right perspective, displayed into the medium layer
 * -The minimap image, drawing a top-left small square
 *  map, displayed into the first layer 
*/
int	init_game(t_game *game)
{
	game->is_moving = 1;
	init_player_values(game);
	if (init_textures(game))
		return (1);
	game->img_back = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img_back)
		return (1);
	draw_background(game);
	if (mlx_image_to_window(game->mlx, game->img_back, 0, 0) < 0)
		return (1);
	if (init_ray(game))
		return (1);
	game->img_ray = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img_ray)
		return (1);
	execute_raycasting(game);
	if (mlx_image_to_window(game->mlx, game->img_ray, 0, 0) < 0)
		return (1);
	game->img_mmap = mlx_new_image(game->mlx, (WIDTH / 5), (HEIGHT / 5));
	if (!game->img_mmap)
		return (1);
	draw_minimap(game);
	if (mlx_image_to_window(game->mlx, game->img_mmap, 0, 0) < 0)
		return (1);
	return (0);
}

/**
 * Starts the game loop. Initializes the graphical window and game
 * resources. Hooks the game loop to the updater function. Displays
 * game information and enters the main event loop. Cleans up resources
 * upon termination. Returns 0 on success or 1 on failure.
 */
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
