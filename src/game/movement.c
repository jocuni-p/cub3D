/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:19:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/01 01:00:39 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*permite al jugador moverse en la dirección deseada, verificando que no 
choque con paredes u obstáculos. Primero calcula las coordenadas futuras 
(next_x y next_y), comprueba si el jugador puede moverse allí sin colisión, 
y si es posible, actualiza la posición del jugador.*/
/* Actualiza la posición del jugador en función de un vector de dirección 
(fx, fy) y una velocidad de movimiento (move_speed).*/

/**
 * Moves the player in a specified direction. Calculates the new position
 * using the direction vector and movement speed. Checks for collisions
 * with walls or obstacles. Updates the player's position if the path is
 * clear. Marks the player as moving.
 */
void	move(t_game *game, float dir_x, float dir_y, float move_speed)
{
	float	next_move_x;
	float	next_move_y;

	next_move_x = game->player.pos.x + dir_x * (move_speed + 0.01);
	next_move_y = game->player.pos.y + dir_y * (move_speed + 0.01);
	if (game->map_arr[(int)next_move_y][(int)game->player.pos.x] == '0' \
		|| game->map_arr[(int)next_move_y][(int)game->player.pos.x] == 'N' \
		|| game->map_arr[(int)next_move_y][(int)game->player.pos.x] == 'S' \
		|| game->map_arr[(int)next_move_y][(int)game->player.pos.x] == 'E' \
		|| game->map_arr[(int)next_move_y][(int)game->player.pos.x] == 'W')
		game->player.pos.y += dir_y * move_speed;
	if (game->map_arr[(int)game->player.pos.y][(int)next_move_x] == '0' \
		|| game->map_arr[(int)game->player.pos.y][(int)next_move_x] == 'N' \
		|| game->map_arr[(int)game->player.pos.y][(int)next_move_x] == 'S' \
		|| game->map_arr[(int)game->player.pos.y][(int)next_move_x] == 'E' \
		|| game->map_arr[(int)game->player.pos.y][(int)next_move_x] == 'W')
		game->player.pos.x += dir_x * move_speed;
	game->is_moving = true;
}

/**
 * Rotates the player's direction and camera plane by a given angle. Uses
 * trigonometric functions to calculate the new direction and plane vectors.
 * Marks the player as moving to update the game state.
 */
void	rotate(t_game *game, float angle)
{
	float	dir;
	float	plane;

	dir = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(angle)
		- game->player.dir.y * sin(angle);
	game->player.dir.y = dir * sin(angle)
		+ game->player.dir.y * cos(angle);
	plane = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * cos(angle)
		- game->player.plane.y * sin(angle);
	game->player.plane.y = plane * sin(angle)
		+ game->player.plane.y * cos(angle);
	game->is_moving = true;
}

/**
 * Teleports the player to their original position. Resets the direction
 * to the initial state. Updates the player's position to the stored
 * original coordinates. Marks the player as moving to refresh the state.
 */
void	teleport_to_original_position(t_game *game)
{
	reset_player_direction(game);
	game->player.pos.x = game->player.orig_pos.x;
	game->player.pos.y = game->player.orig_pos.y;
	game->is_moving = true;
}

/**
 * Handles all movement-related actions. Calls specific functions for
 * moving forward, backward, strafing, rotating, running, and teleporting.
 * Centralizes movement processing to simplify event handling.
 */
void	process_movement(t_game *game)
{
	try_to_move_forward(game);
	try_to_move_backward(game);
	try_to_strafe(game);
	try_to_rotate(game);
	try_to_run(game);
	try_to_teleport(game);
}

/**
 * Listens for input events. Checks for key presses such as ESCAPE to quit
 * the game. Delegates movement handling to the `process_movement` function.
 * Ensures all input-driven actions are processed during the game loop.
 */
void	event_listener(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		error_mlx(game);
	process_movement(game);
}

/*
the stuff below was in the even_listener and was tranfered into 
process_movement function and its sub functions
// if(mlx_is_key_down(game->mlx, MLX_KEY_W)
	|| mlx_is_key_down(game->mlx, MLX_KEY_UP))
// 	move(game, game->player.dir.x, game->player.dir.y,
		game->player.speed); //moves towards palyer.dir
// if(mlx_is_key_down(game->mlx, MLX_KEY_S)
	|| mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
// 	move(game, -game->player.dir.x, -game->player.dir.y, game->player.speed);
// if(mlx_is_key_down(game->mlx, MLX_KEY_A))
// 	move(game, game->player.dir.y, -game->player.dir.x, game->player.speed);
// if(mlx_is_key_down(game->mlx, MLX_KEY_D))
// 	move(game, -game->player.dir.y, game->player.dir.x, game->player.speed);
// if (mlx_is_key_down(game->mlx, MLX_KEY_Y))
// 	teleport_to_original_position(game);
// if(mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT)
		&& !game->player.is_running)
// 	sprint_on(game);
// if(!mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT)
		&& game->player.is_running)
// 	sprint_off(game);
*/
