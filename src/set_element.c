/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:10:19 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/23 17:10:20 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*Sets every parser->elem.var with his content. If a duplicate or non valid 
element is found returns 1. Finally frees **elements. */
int	set_element(t_parser *parser, char **elements)
{
	if ((ft_strcmp(elements[0], "NO") == 0) && parser->elem.no == NULL)
		parser->elem.no = ft_strdup(elements[1]);				
	else if ((ft_strcmp(elements[0], "SO") == 0) && parser->elem.so == NULL)
		parser->elem.so = ft_strdup(elements[1]);				
	else if ((ft_strcmp(elements[0], "WE") == 0) && parser->elem.we == NULL)
		parser->elem.we = ft_strdup(elements[1]);
	else if ((ft_strcmp(elements[0], "EA") == 0) && parser->elem.ea == NULL)
		parser->elem.ea = ft_strdup(elements[1]);
	else if ((ft_strcmp(elements[0], "C") == 0) && parser->elem.c == NULL)
		parser->elem.c = ft_strdup(elements[1]);
	else if ((ft_strcmp(elements[0], "F") == 0) && parser->elem.f == NULL)
		parser->elem.f = ft_strdup(elements[1]);
	else
	{
		arr2d_free(elements);
		return (1);
	}
	arr2d_free(elements);
	return (0);
}
