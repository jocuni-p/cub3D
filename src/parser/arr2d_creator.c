/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr2d_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:14:18 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/06 14:04:11 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	arr2d_size(t_parser *parser)
{
	t_cub	*tmp;
	int		len;
	int		high;
	int		len_aux;
	
	len = 0;
	high = 1;
	tmp = parser->map_firstline;//lo apunto al inicio del mapa
	len = ft_strlen(tmp->str);
	tmp = tmp->next;
	while (tmp)
	{
		len_aux = ft_strlen(tmp->str);
		if (len_aux > len)
			len = len_aux;
		tmp = tmp->next;
		high++;
	}
	parser->map.w = len;
	parser->map.h = high;
//	printf("map size = %i x %i\n\n", len, high);//TEMPORAL
	return (0);
}

//	relleno cada elemento de la matriz con su linea y donde acabe habra " "
int arr2d_filler(t_parser *parser)
{
	int	i;
	int	j;

	i = 0;
	while (parser->raw_map[i] != NULL && parser->map_firstline != NULL)
	{
		j =0;
		while (parser->map_firstline->str[j] != '\0' && j < parser->map.w)
		{
			parser->raw_map[i][j] = parser->map_firstline->str[j];
			j++;
		}
		i++;
		parser->map_firstline = parser->map_firstline->next;
	}
	return (0);
}

/*Transfers the map from a list in a rectangular 2D matrix*/
int	arr2d_creator(t_parser *parser)
{
	int	i;

	i = 0;
	if (arr2d_size(parser))
		return (1);
//MALLOCADO DE LA MATRIZ EXTERNA
	parser->raw_map = (char **)malloc(sizeof(char *) * parser->map.h + 1);
	if (!parser->raw_map)
		return (handle_error(ERR_MAP), 1);//OJO, liberar todo lo allocado hasta ahora		
//MALLOCADO DE SUS ELEMENTOS, AL MISMO SIZE
	 while (i < parser->map.h)
	{
		parser->raw_map[i] = (char *)malloc(sizeof(char) * parser->map.w + 1);
		if (!parser->raw_map[i])
			return (handle_error(ERR_MAP), 1);//OJO, liberar todo lo allocado hasta ahora
		ft_memset(parser->raw_map[i], ' ', parser->map.w);//inicializo todo el str con ' '
		parser->raw_map[i][parser->map.w] = '\0';//cierro el str 
		i++;
	}
	parser->raw_map[i] = NULL;//cierro el arr2d
	arr2d_filler(parser);
	return (0);
}
