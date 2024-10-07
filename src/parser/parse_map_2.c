/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:33:39 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/07 17:27:38 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//	-entre la 2a y penultima linea, recorro todos los '0' y el player (N, S, E, W) 
//  mirando arriba, abajo, der, izq, si hay algun ' '->INVALID

int	is_map_properly_closed(t_parser *parser)
{
	int	x;
	int	y;
	
	y = 1;
	while (y < parser->map.h - 1)//no recorro ni la 1a ni la ultima
	{
		x = 1;//no miro el primer element de cada linea y aixi no entrara en segfault
		while (x < parser->map.w)// - 1 ??
		{
			if (parser->raw_map[y][x] == '0' || parser->raw_map[y][x] == 'N' \
			|| parser->raw_map[y][x] == 'S' || parser->raw_map[y][x] == 'W' \
			|| parser->raw_map[y][x] == 'E')
			{
//				if (check_char(parser, x, y))
//					return (handle_error(ERR_MAP), 1);
				if (parser->raw_map[y][x + 1] == ' ' || parser->raw_map[y][x - 1] == ' ' \
				|| parser->raw_map[y + 1][x] == ' ' || parser->raw_map[y - 1][x] == ' ')
					return (1);
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
		return (handle_error(ERR_MAP), 1);
		
	if (parser->map.w < 3 || parser->map.h < 3)//tamanyo minimo de mapa viable
		return (handle_error(ERR_MAP), 1);

	if (is_map_properly_closed(parser))
		return (handle_error(ERR_MAP), 1);
 
//	sustituyo espacios iniciales y finales de cada linea por '1' (NO SE SI HACE FALTA DESARROLLAR ESTO ??)

	return (0);
}
 