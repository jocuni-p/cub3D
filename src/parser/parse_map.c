/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:26:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/02 12:52:22 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>IN_PROGRESS>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
int	firstline_and_lastline(char *line)
{
	if ()
}

/*----Parses just the map---*/
int	parse_map(t_parser *parser)
{
	char	*trimmed_line;
	
	while (parser->cub->str[0] == '\n')//skips empty lines
		parser->cub = parser->cub->next;
	parser->map_firstline = parser->cub;//sets a pointer to the map beginning
//			si primera linea contenido != ("1" && '\n') || (1 && " " && '\n') ->INVALID
	while (parser->cub)
	{
		remove_nl(parser->cub->str);
		if (parser->cub->str == '\n')//if it's an empty line
			return (handle_error(ERR_FILE), 1);
			
		trimmed_line = ft_strtrim(parser->cub->str, " ");//quito espacios para analizar el str
		firstchar_and_lastchar(trimmed_line)//si empieza y acaba en 1  
		valid_chars(trimmed_line)//si contenido != 1, 0, E, N,S, W, " " -> INVALID
		if (parser->cub->next == NULL)//si es la ultima linea
//			si contiene algo != ("1" || (1 && " ")) ->INVALID			
		free(trimmed_line);
		parser->cub = parser->cub->next;
	}
//	>>>>>>>>AQUI FER UN PRINT PER PROBAR EL MAPA<<<<<<<<<<
}

//	>>>>>>>>CONFECCIO DE LA MATRIU>>>>>>>>
	Passar a fer el arr2d:
		map_size per fer el malloc	
			return (handle_error(ERR_FILE), 1);
	if (firstline_and_lastline(trimmed_line))//si primera y ultima linea No contiene 1->INVALID

