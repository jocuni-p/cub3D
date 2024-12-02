/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:31:21 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/12/03 00:44:43 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Toggles sprinting based on the LEFT SHIFT key. Activates sprint if the key
 * is pressed and sprinting is off. Deactivates sprint if the key is released
 * and sprinting is on. Calls `sprint_on` and `sprint_off` accordingly.
 */
void	try_to_run(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT)
		&& !game->player.is_running)
		sprint_on(game);
	if (!mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT)
		&& game->player.is_running)
		sprint_off(game);
}

/**
 * Activates sprinting mode. Doubles the player's movement speed and increases
 * the rotation speed by half the default rotation increment. Marks the player
 * as running.
 */
void	sprint_on(t_game *game)
{
	game->player.speed *= 2;
	game->player.rotation_speed += ROTATION_SPEED / 2;
	game->player.is_running = true;
}

/**
 * Deactivates sprinting mode. Halves the player's movement speed and reduces
 * the rotation speed by half the default rotation increment. Marks the player
 * as not running.
 */
void	sprint_off(t_game *game)
{
	game->player.speed *= 0.5;
	game->player.rotation_speed -= ROTATION_SPEED / 2;
	game->player.is_running = false;
}

void	change_angle_for_testing(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_M) && !game->player.m_n_is_pressed)
	{
		game->player.m_n_is_pressed = true;
		game->player.angle += 1.0f;
		printf("Angle INCREASED by 1 degree.\nNew value: %f\n",
			game->player.angle);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_N) && !game->player.m_n_is_pressed)
	{
		game->player.m_n_is_pressed = true;
		game->player.angle -= 1.0f;
		printf("Angle DECREASED by 1 degree.\nNew value: %f\n",
			game->player.angle);
	}
	if (!mlx_is_key_down(game->mlx, MLX_KEY_M)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_N)
		&& game->player.m_n_is_pressed)
		game->player.m_n_is_pressed = false;
}
