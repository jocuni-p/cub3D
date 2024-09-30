/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:26:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/30 12:52:14 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Returns 1 if it is found on *str any invalid character, otherwise returns 0*/
int	check_map_chars(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == ' ' || str[i] == '1' || str[i] == '0' || str[i] == 'N' \
			|| str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			i++;
		else
			return (handle_error(ERR_FILE), 1);
	}
	return (0);
}

/*----Parses just the map---*/
int	parse_map(t_parser *parser)
{
//	t_cub 	*aux;
	char	**elements;

//	parser->aux = parser->cub;
	while(parser->aux)
	{
		remove_nl(parser->aux->str);
		if (check_map_chars(parser->aux->str))//return 0 if chars are valids
			return (handle_error(ERR_FILE), 1);
//		elements = ft_split(parser->aux->str, ' ');//retorns a char ** allocated
//		if (arr2d_element_cnt(elements) != 2)//checks if the array has only 2 elements
//		{
//			arr2d_free(elements);
//			return (handle_error(ERR_FILE), 1);
//		}
//		arr2d_print(elements);//TEMPORAL
		if (set_element(parser, elements))//gets the content of each element
			return (handle_error(ERR_FILE), 1);
		parser->aux = parser->aux->next;
//		if (!flag_elem(parser))//si ja tenim tots els elements setejats 
//			return (0);
	}
	return (0);//aquest return no faria falta??
}

