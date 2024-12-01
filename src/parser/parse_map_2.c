/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:33:39 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 19:01:34 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*gets the player position on the map*/
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

/*Iters through the entire map and check if the characters '0', 'N', 'S', 
'E', or 'W' have any ' ' character around them.*/
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
