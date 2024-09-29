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

/*---Returns 0 if all elements are set; otherwise, returns 1.----*/
int	flag_elem(t_parser *parser)
{
	if (parser->elem.no != NULL && parser->elem.so != NULL \
		&& parser->elem.we != NULL && parser->elem.ea != NULL \
		&& parser->elem.c_color != 0 && parser->elem.f_color != 0)
		return (0);
	return (1);
}

/*----Parse just the elements that define the 4 textures (NO, SO, WE, EA)---*/
int	parse_elements(t_parser *parser)
{
	t_cub 	*aux;
	char	**elements;

	aux = parser->cub;
	while(aux)//frenar quan ha fet 6 pasades, pels elements i no pel mapa
	{
		remove_nl(aux->str);
		if (check_element_chars(aux->str))//return 0 si chars valids
			return (handle_error(ERR_FILE), 1);
		elements = ft_split(aux->str, ' ');//retorns a char ** allocated
		if (arr2d_element_cnt(elements) != 2)//checks if the array has only 2 elements
		{
			arr2d_free(elements);
			return (handle_error(ERR_FILE), 1);
		}
//		arr2d_print(elements);//TEMPORAL
		if (set_element(parser, elements))//gets the content of each element
			return (handle_error(ERR_FILE), 1);
		aux = aux->next;
//		if (!flag_elem(parser) && !check_map_chars(aux->str))//si ja tens tots els elements i la linea actual pertany al mapa, retorna
//			setear el puntero con el inicio del mapa en la lista
//			return (0);
	}
	return (0);//aquest return no faria falta
}
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
			return (1);
	}
	return (0);
}