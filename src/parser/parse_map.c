/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:26:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/03 12:56:15 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>IN_PROGRESS>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*---Return 0 if str contains '1' and/or ' ' character, otherwise return 1*/
int	is_map_firstline_valid(char *str)
{
	int	i;

	i = 0;
	remove_nl(str);
	while(str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}

/*Return 0 if str began and finish with char '1', otherwise return 1*/
int	is_first_and_last_char_valid(char *str)
{
	if (str[0] == '1' && str[ft_strlen(str) - 1] == '1')
		return (0);
	else
		return (1);
}

/*Return 0 if str contents 1/0/' '/N/S/W or E, otherwise return 1*/
int	is_middle_char_valid(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '1' || str[i] == '0' || str[i] == 'N' \
			|| str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
			i++;
		else
			return (1);
	}
	return (0);
}

int	parse_map(t_parser *parser)
{
	char	*trimmed_line;
	
	while (parser->cub->str[0] == '\n')//skips empty lines
		parser->cub = parser->cub->next;
	parser->map_firstline = parser->cub;//sets a pointer to the map first line
//			si primera linea contenido != ("1" && '\n') || (1 && " " && '\n') ->INVALID
	if (is_map_firstline_valid(parser->cub->str))
		return (handle_error(ERR_MAP), 1);
	parser->cub = parser->cub->next;
	while (parser->cub)
	{
		remove_nl(parser->cub->str);
		if (parser->cub->str[0] == '\0')//if it's an empty line
			return (handle_error(ERR_MAP), 1);
			
		trimmed_line = ft_strtrim(parser->cub->str, " ");//quito espacios para analizar el str
		if (is_first_and_last_char_valid(trimmed_line))//si la linea empieza y acaba en 1  
			return (handle_error(ERR_MAP), 1);
			
		if (is_middle_char_valid(trimmed_line))//si contenido != 1, 0, E, N,S, W, " " -> INVALID
			return (handle_error(ERR_MAP), 1);
		if (parser->cub->next == NULL)//si es la ultima linea
//			si contiene algo != ("1" || (1 && " ")) ->INVALID		
		free(trimmed_line);
		parser->cub = parser->cub->next;
	}
//FER UN ERR_PRINT per elements i un altre pel mapa
//	funcion de la matriz
//	>>>>>>>>AQUI FER UN PRINT PER PROBAR EL MAPA<<<<<<<<<<
}

//	>>>>>>>>CONFECCIO DE LA MATRIU>>>>>>>>
	Passar a fer el arr2d:
		map_size per fer el malloc de la matriu	
			return (handle_error(ERR_FILE), 1);


//si la matriz tiene mas de x de ancho y x de alto (medidas minimas)-> seguir
//si la matriz contiene 1 solo player-> seguir
//si el mapa esta abierto (es decir, un 0 junto a un espacio)->INVALID