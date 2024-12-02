/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction_based_on_angle.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:55:08 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/12/02 22:29:50 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_direction_based_on_angle(t_game *game)
{
	float	angle;

	angle = M_PI / 180 * game->player.angle;
	game->player.dir.x = cos(angle);
	game->player.dir.y = sin(angle);
	game->player.plane.x = -game->player.dir.y * 0.6;
	game->player.plane.y = game->player.dir.x * 0.6;
	game->is_moving = true;
}
