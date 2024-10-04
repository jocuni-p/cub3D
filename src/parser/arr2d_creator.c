/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr2d_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:14:18 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/04 18:47:29 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	map_size(t_parser *parser)
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
	if (len < 3 || high < 3)//tamanyo minimo de caracteres y lineas que podria presentar el mapa
		return (handle_error(ERR_MAP), 1);
	parser->map.w = len;
	parser->map.h = high;
//	printf("map size = %i x %i\n\n", len, high);//TEMPORAL
	return (0);
}

int	arr2d_creator(t_parser *parser)
{
	if (map_size(parser))
		return (1);
//MALLOCADO DE LA MATRIZ EXTERNA
	parser->raw_map = (char **)malloc(sizeof(char *) * parser->map.h + 1);
	if (!parser->raw_map)
		return (handle_error(ERR_MAP), 1);//ademas, liberar todo allocado hasta ahora
//MALLOCADO DE TODOS LOS ELEMENTOS AL MISMO TAMANYO, ULTIMO A NULL>>>>>>>>>>>>>>
	reservo memoria con malloc(size_t num_elem, sizeof(char)) para map.w (el padding NO hace falta porque inicio y fin de linea estan verificados a 1)
	funcion que inicializa cada byte del str con " " para que la memoria no contengan basura que me entorpeceria a la hora de chequear si contiene un " " o un '1'
	relleno cada elemento de la matriz con su linea, donde no alcance el relleno habra un " "
	entre la 2a y penultima linea, recorro todos los '0' mirando arriba, abajo, der, izq si hay algun ' '->INVALID
	sustituyo espacios iniciales y finales de cada linea por '1' 



	while (parser->map_firstline)
	{

		map_firstline = map_firstline->next;
	}
	return (0);
}

//si la matriz contiene player_qty != 1 -> INVALID
