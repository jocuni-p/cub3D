/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr2d_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:14:18 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/03 18:17:20 by jocuni-p         ###   ########.fr       */
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
	if (len < 3 || high < 3)
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
//		map_size per fer el malloc de la matriu	
	return (0);
}

//si la matriz tiene menos de 3 de ancho y menos de 3 de alto (medidas minimas)->INVALID
//si la matriz contiene player y solo 1 player-> seguir
//si el mapa esta abierto (es decir, un 0 junto a un espacio)->INVALID