/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:33:39 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/02 01:19:59 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Retrieves the player's position from the map. Identifies the player's
 * starting position based on the characters 'N', 'S', 'W', or 'E'. Updates
 * the player's position and original position to the center of the tile.
 */
void	get_player_pos(t_game *game, int x, int y)
{
	if (game->map_arr[y][x] == 'N' || game->map_arr[y][x] == 'S'
	|| game->map_arr[y][x] == 'W' || game->map_arr[y][x] == 'E')
	{
		game->player.pos.x = (float)x + 0.5;
		game->player.pos.y = (float)y + 0.5;
		game->player.orig_pos.x = game->player.pos.x;
		game->player.orig_pos.y = game->player.pos.y;
	}
}

/**
 * Checks if the map is properly enclosed. Iterates through the map and ensures
 * that characters '0', 'N', 'S', 'W', or 'E' are not adjacent to a ' ' 
 * character.  * Calls `get_player_pos` to set the player's starting position 
 * if found. Returns * 1 if the map is improperly closed, otherwise returns 0.
 */
int	is_map_properly_closed(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = 1;
	while (y < game->map_h - 1)
	{
		x = 1;
		while (x < game->map_w)
		{
			c = game->map_arr[y][x];
			if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				if (game->map_arr[y][x + 1] == ' ' \
				|| game->map_arr[y][x - 1] == ' ' \
				|| game->map_arr[y + 1][x] == ' ' \
				|| game->map_arr[y - 1][x] == ' ')
					return (1);
				get_player_pos(game, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

/**
 * Validates the map after the elements have been parsed. Ensures there is 
 * exactly one player, and the map dimensions meet the minimum requirements. 
 * Checks if the map is properly enclosed using `is_map_properly_closed`. 
 * Returns 1 if any validation fails.
 */
int	parse_map_2(t_game *game)
{
	if (game->parser.ply_qty != 1)
		return (print_error(ERR_MAP), 1);
	if (game->map_w < 3 || game->map_h < 3)
		return (print_error(ERR_MAP), 1);
	if (is_map_properly_closed(game))
		return (print_error(ERR_MAP), 1);
	return (0);
}
