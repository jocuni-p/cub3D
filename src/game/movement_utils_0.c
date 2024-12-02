/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:31:21 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/12/03 00:55:21 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Moves the player forward if the W or UP key is pressed. Uses the player's
 * direction vector and speed to calculate the new position. Calls the
 * `move` function to update the position.
 */
void	try_to_move_forward(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		|| mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move(game, game->player.dir.x, game->player.dir.y,
			game->player.speed);
}

/**
 * Moves the player backward if the S or DOWN key is pressed. Calculates
 * the new position by reversing the direction vector. Calls the `move`
 * function to handle the update.
 */
void	try_to_move_backward(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		|| mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move(game, -game->player.dir.x, -game->player.dir.y,
			game->player.speed);
}

/**
 * Enables strafing movement. Moves the player left if A is pressed or right
 * if D is pressed. Adjusts the movement direction perpendicular to the
 * player's current direction. Uses the `move` function for updates.
 */
void	try_to_strafe(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move(game, game->player.dir.y, -game->player.dir.x,
			game->player.speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move(game, -game->player.dir.y, game->player.dir.x,
			game->player.speed);
}

/**
 * Rotates the player when LEFT or RIGHT keys are pressed. Updates the
 * player's direction and camera plane using the `rotate` function. Adjusts
 * the rotation angle based on the rotation speed.
 */
void	try_to_rotate(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate(game, -game->player.rotation_speed * 80);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate(game, game->player.rotation_speed * 80);
}

/**
 * Teleports the player to their original position if the Y key is pressed.
 * Calls the `teleport_to_original_position` function to handle the update.
 */
void	try_to_teleport(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_Y))
		teleport_to_original_position(game);
}
