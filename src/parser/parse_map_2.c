/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:33:39 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/11 10:27:10 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*gets the player position on the map*/
void	get_player_pos(t_parser *parser, int x, int y)
{
	if (parser->raw_map[y][x] == 'N' || parser->raw_map[y][x] == 'S' \
	|| parser->raw_map[y][x] == 'W' || parser->raw_map[y][x] == 'E')
	{
		parser->map.player_x = x;
		parser->map.player_y = y;
	}
}

/*Iters through the entire map and check if the characters '0', 'N', 'S', 
'E', or 'W' have any ' ' character around them.*/
int	is_map_properly_closed(t_parser *parser)
{
	int		x;
	int		y;
	char	c;

	y = 1;
	while (y < parser->map.h - 1)//1rst and last lines are not itered
	{
		x = 1;
		while (x < parser->map.w)//first and last element of the line are not checked
		{
			c = parser->raw_map[y][x];
			if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				if (parser->raw_map[y][x + 1] == ' ' \
				|| parser->raw_map[y][x - 1] == ' ' \
				|| parser->raw_map[y + 1][x] == ' ' \
				|| parser->raw_map[y - 1][x] == ' ')
					return (1);
				get_player_pos(parser, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	parse_map_2(t_parser *parser)
{
	if (parser->map.player_qty != 1)
		return (print_error(ERR_MAP), 1);	
	if (parser->map.w < 3 || parser->map.h < 3)//minim map playeble size 
		return (print_error(ERR_MAP), 1);
	if (is_map_properly_closed(parser))
		return (print_error(ERR_MAP), 1);
	return (0);
}
