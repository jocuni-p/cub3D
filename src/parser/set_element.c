/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:10:19 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/27 10:20:47 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
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
