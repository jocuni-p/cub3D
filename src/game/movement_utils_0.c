/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:31:21 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/30 13:43:21 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	try_to_move_forward(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		|| mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move(game, game->player.dir.x, game->player.dir.y,
			game->player.speed);
}

void	try_to_move_backward(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		|| mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move(game, -game->player.dir.x, -game->player.dir.y,
			game->player.speed);
}

void	try_to_strafe(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move(game, game->player.dir.y, -game->player.dir.x,
			game->player.speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move(game, -game->player.dir.y, game->player.dir.x,
			game->player.speed);
}

void	try_to_rotate(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate(game, -game->player.rotation_speed * 80);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate(game, game->player.rotation_speed * 80);
}

void	try_to_teleport(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_Y))
		teleport_to_original_position(game);
}
