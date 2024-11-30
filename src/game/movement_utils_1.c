/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:31:21 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/30 14:01:52 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	try_to_run(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT)
		&& !game->player.is_running)
		sprint_on(game);
	if (!mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT)
		&& game->player.is_running)
		sprint_off(game);
}

void	sprint_on(t_game *game)
{
	game->player.speed *= 2;
	game->player.rotation_speed += ROTATION_SPEED / 2;
	game->player.is_running = true;
}

void	sprint_off(t_game *game)
{
	game->player.speed *= 0.5;
	game->player.rotation_speed -= ROTATION_SPEED / 2;
	game->player.is_running = false;
}
