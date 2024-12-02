/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_player_direction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:31:37 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/12/02 22:03:18 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Resets the player's direction and camera plane based on their orientation.
 * Checks the player's orientation ('N', 'S', 'E', or 'W') and calls the
 * corresponding direction-setting function to update the direction vector
 * and camera plane.
 */
void	reset_player_direction(t_game *game)
{
	if (game->player.orientation == 'N')
		set_direction_north(game);
	else if (game->player.orientation == 'S')
		set_direction_south(game);
	else if (game->player.orientation == 'E')
		set_direction_east(game);
	else if (game->player.orientation == 'W')
		set_direction_west(game);
}

/**
 * Every function below sets the player's direction to face the corresponding
 * direction (north, south, east, west). Updates the direction vector and 
 * adjusts the camera plane to align with the new direction.
 */
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
