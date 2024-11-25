/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_player_direction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:31:37 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/25 12:31:48 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_direction_north(t_game *game)
{
	game->player.dir.x = 0;
	game->player.dir.y = -1;
	game->player.plane.x = 0.6;
	game->player.plane.y = 0;
}

void	set_direction_south(t_game *game)
{
	game->player.dir.x = 0;
	game->player.dir.y = 1;
	game->player.plane.x = -0.6;
	game->player.plane.y = 0;
}

void	set_direction_east(t_game *game)
{
	game->player.dir.x = 1;
	game->player.dir.y = 0;
	game->player.plane.x = 0;
	game->player.plane.y = 0.6;
}

void	set_direction_west(t_game *game)
{
	game->player.dir.x = -1;
	game->player.dir.y = 0;
	game->player.plane.x = 0;
	game->player.plane.y = -0.6;
}
