/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:33:39 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/30 18:49:40 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*gets the player position on the map*/
void	get_player_pos(t_game *game, int x, int y)
{
	if (game->map_arr[y][x] == 'N' || game->map_arr[y][x] == 'S' \
	|| game->map_arr[y][x] == 'W' || game->map_arr[y][x] == 'E')
	{
		game->player.pos.x = x;
		game->player.pos.y = y;
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
	while (y < game->map_h - 1)//1rst and last lines are not itered
	{
		x = 1;
		while (x < game->map_w)//first and last element of the line are not checked
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
	if (game->map_w < 3 || game->map_h < 3)//minim map playable size 
		return (print_error(ERR_MAP), 1);
	if (is_map_properly_closed(game))
		return (print_error(ERR_MAP), 1);
	return (0);
}
