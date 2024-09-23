/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:52:20 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/23 16:19:52 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*----Parse just the 2 elements that define the ceiling and floor color----*/
//	color_rgb_to_hex//convierte rgb a hexadecimal + canal Alfa(FF) 

int	parse_color(t_parser *parser)
{
	split(str, ',');
	if (tiene solo 3 elementos)
	while(elemento[i])
		ft_isdigit(str);
		atoi(str)//guardar en 3 variables para la construccion del hex
		if (rango >= 0  && <= 255)
		convertir a put_hex-. ver chat

}
/*	
	t_cub 	*aux;
	char	**elements;
	
	aux = parser->cub;
	while(aux)
	{
		remove_nl(aux->str);
		if (check_valid_chars(aux->str))//return 0 si chars valids
//			return (handle_error(ERR_FILE), parser_free(parser)), 1);
			return (handle_error(ERR_FILE), 1);
		elements = ft_split(aux->str, ' ');//retorna un char ** con 2 elementos + NULL mallocados
		if (arr2d_element_cnt(elements) != 2)//checks if the array contains only 2 elements
		{
			arr2d_free(elements);
//			return (handle_error(ERR_FILE), parser_free(parser)), 1);
			return (handle_error(ERR_FILE), 1);
		}
//		arr2d_print(elements);//TEMPORAL
		if (set_element(parser, elements))//gets the content of each element
//			return (handle_error(ERR_FILE), parser_free(parser)), 1);
			return (handle_error(ERR_FILE), 1);
		aux = aux->next;
	}
	return (0);
}*/
