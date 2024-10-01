/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:26:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/01 17:25:16 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>IN_PROGRESS>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/*----Parses just the map---*/
int	parse_map(t_parser *parser)
{
//	EN LA LLISTA:CHEQUEO PREVIO AL PASO A MATRIZ:
//El parser->aux esta en la siguiente linea de elements (podria estar vacia,con tab o cosas)
	while (parser->aux->str[0] == '\n')//skips empty lines
		parser->aux = parser->aux->next;
	
	while (lista al mapa)
	{
		remove_nl(str??)
		trimmed_line = ft_strtrim(line)
		firstline_and_lastline(trimmed_line)//si primera y ultima linea No contiene 1->INVALID
//			si contiene algo que no sea "1" o " " o esta vacia-> INVALID	
		firstchar_and_lastchar(trimmed_line)//si empieza y acaba en 1  
		valid_chars(trimmed_line)//si contiene algo diferente de 1, 0, E, N,S, W, " " -> INVALID	

	}
	
	Passar a fer el arr2d:
		map_size per fer el malloc
	

	
			return (handle_error(ERR_FILE), 1);


}

