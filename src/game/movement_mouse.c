/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:42:09 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/12/03 01:08:14 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Handles mouse movement to rotate the player's view. Tracks the horizontal
 * mouse movement (delta_x) and adjusts the player's direction accordingly.
 * Uses the game's sensitivity value to scale the rotation speed.
 */
void	rotate_with_mouse(t_game *game)
{
	static int32_t	prev_mouse_x = 0;
	int32_t			current_mouse_x;
	int32_t			current_mouse_y;
	int32_t			delta_x;

	mlx_get_mouse_pos(game->mlx, &current_mouse_x, &current_mouse_y);
	delta_x = current_mouse_x - prev_mouse_x;
	if (delta_x != 0)
		rotate(game, delta_x * game->sensitivity);
	prev_mouse_x = current_mouse_x;
}

/**
 * Handles mouse button input events. Reacts to mouse button presses:
 * - Middle button: Teleports the player to their original position.
 * - Left button: Sets the player's direction to south and marks movement.
 * - Right button: Sets the player's direction to north and marks movement.
 */
void	mouse_button_hook(mouse_key_t button, action_t action,
			modifier_key_t mods, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	(void) mods;
	if (button == MLX_MOUSE_BUTTON_MIDDLE && action == MLX_PRESS)
		teleport_to_original_position(game);
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		set_direction_south(game);
		game->is_moving = true;
	}
	if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS)
	{
		set_direction_north(game);
		game->is_moving = true;
	}
}

/**
 * Adjusts the game's rotation sensitivity based on mouse scroll input.
 * Increases sensitivity on upward scroll and decreases it on downward scroll.
 * Ensures sensitivity stays within the bounds of 0.0005 to 0.01. Logs the
 * updated sensitivity value to the console.
 */
void	scroll_hook(double xoffset, double yoffset, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	(void) xoffset;
	if (yoffset > 0)
		game->sensitivity += 0.0005;
	else if (yoffset < 0)
		game->sensitivity -= 0.0005;
	if (game->sensitivity < 0.0005)
		game->sensitivity = 0.0005;
	if (game->sensitivity > 0.01)
		game->sensitivity = 0.01;
	printf("Updated rotation sensitivity: %f\n", game->sensitivity);
}
