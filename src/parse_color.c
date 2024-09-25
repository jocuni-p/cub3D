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
/*----Parse the color data and save it on the struct ----*/
//	color_rgb_to_hex//convierte rgb a hexadecimal + canal Alfa(FF) 

//Retorna 1 si NO es valido el color (+err_msg +free), sino lo convierte a 
//hexadecimal, lo guarda en la struct y retorna 0. 


parser_colors

		parse_c(parser);
		parse_f(parser);
		
int	parse_color(t_parser *parser, char *str)//parsea 1 elemento a la vez (c o f)
{
	int		i;
	int		j;
	char	**rgb;

	i = 0;
	rgb = ft_split(str, ',');
	free (str);
	if (arr2d_element_cnt(rgb) != 3)
	{
		arr2d_free(rgb);
//		return (handle_error(ERR_FILE), parser_free(parser)), 1);
		return (handle_error(ERR_FILE), 1);
	}
	while(rgb[i])
	{
		j = 0;
		while(rgb[i][j])
		{
			if (ft_isdigit(rgb[i][j]) == 0)
//				return (handle_error(ERR_FILE), parser_free(parser)), 1);
				return (handle_error(ERR_FILE), 1);
			j++;
		}
		nbr = ft_atoi(rgb[i]);//guardar en 3 variables para la construccion del hex

		if (i = 0 && (nbr >= 0 && nbr <= 255))
			color->r = nbr;
		else if (i = 1 && (nbr >= 0 && nbr <= 255))
			color->g = nbr;
		else if (i = 2 && (nbr >= 0 && nbr <= 255))
			color->b = ft_atoi(rgb[i]);
		else
//			return (handle_error(ERR_FILE), parser_free(parser)), 1);
			return (handle_error(ERR_FILE), 1);
		i++;
	}
		liberar rgb
		convertir a put_hex-. ver chat
}

/*-De mbueno-g
int	cub_atoi(const char *nptr, long *nbr)
{
	*nbr = 0;
	if (!nptr || !ft_isdigit(*nptr))
		return (-1);
	while (ft_isdigit(*nptr))
	{
		*nbr = 10 * (*nbr) + (*nptr - '0');
		if (*nbr < 0 || *nbr > 255)
			return (-1);
		nptr++;
	}
	if (*nptr)
		return (-1);
	return (0);
}	
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
