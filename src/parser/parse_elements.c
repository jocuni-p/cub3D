/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:34:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/23 13:46:50 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Returns 1 if it is found on *str any invalid character, otherwise returns 0*/
int	check_element_chars(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '/' \
			|| str[i] == '.' || str[i] == ' ' || str[i] == ',')
			i++;
		else
			return (1);
	}
	return (0);
}

/*Sets every parser->elem.var with his content. If a duplicate or non valid 
element is found returns 1. Finally frees **elements. */
int	set_element(t_parser *parser, char **elements)
{
	if ((ft_strcmp(elements[0], "NO") == 0) && parser->elem.no == NULL)//si el elemento es "NO" y la variable no ha sido seteada previamente, se le asigna el valor del segundo elemento
		parser->elem.no = ft_strdup(elements[1]);//no cal duplicar podria seguir amb elements? (Adria?)				
	else if ((ft_strcmp(elements[0], "SO") == 0) && parser->elem.so == NULL)
		parser->elem.so = ft_strdup(elements[1]);				
	else if ((ft_strcmp(elements[0], "WE") == 0) && parser->elem.we == NULL)
		parser->elem.we = ft_strdup(elements[1]);
	else if ((ft_strcmp(elements[0], "EA") == 0) && parser->elem.ea == NULL)
		parser->elem.ea = ft_strdup(elements[1]);
	else if ((ft_strcmp(elements[0], "C") == 0) && parser->elem.c == NULL)
	{
		parser->elem.c = ft_strdup(elements[1]);
		if (parse_color(parser, parser->elem.c, 'c'))
			return (1);
	}
	else if ((ft_strcmp(elements[0], "F") == 0) && parser->elem.f == NULL)
	{
		parser->elem.f = ft_strdup(elements[1]);
		if (parse_color(parser, parser->elem.f, 'f'))//No cal enviar elem.f, ja esta a parser
			return (1);
	}
	else
		return (arr2d_free(elements), 1);
	return (arr2d_free(elements), 0);
}

/*---Returns 0 if all elements are set; otherwise, returns 1.----*/
int	flag_elem(t_parser *parser)
{
	if (parser->elem.no != NULL && parser->elem.so != NULL \
		&& parser->elem.we != NULL && parser->elem.ea != NULL \
		&& parser->elem.c_color != 0 && parser->elem.f_color != 0)
		return (0);
	return (1);
}

/*----Parses just the elements (4 textures + 2 colors) and sets parser->aux 
pointed to the beginning of the map---*/
int	parse_elements(t_parser *parser)
{
//	t_cub 	*aux;
	char	**elements;

	parser->aux = parser->cub;
	while(parser->aux)
	{
		remove_nl(parser->aux->str);
		if (check_element_chars(parser->aux->str))//return 0 if chars are valids
			return (handle_error(ERR_FILE), 1);
		elements = ft_split(parser->aux->str, ' ');//retorns a char ** allocated
		if (arr2d_element_cnt(elements) != 2)//checks if the array has only 2 elements
		{
			arr2d_free(elements);
			return (handle_error(ERR_FILE), 1);
		}
//		arr2d_print(elements);//TEMPORAL
		if (set_element(parser, elements))//gets the content of each element
			return (handle_error(ERR_FILE), 1);
		parser->aux = parser->aux->next;
		if (!flag_elem(parser))//si ja tenim tots els elements setejats 
			return (0);
	}
	return (0);//aquest return no faria falta??
}
