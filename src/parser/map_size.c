/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:14:18 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/01 14:27:33 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void set_map_size(t_parser *parser)
{
	t_cub	*tmp;
	int		len;
	int		len_aux;
	int		high;
	
	len = 0;
	tmp = parser->aux;//aux apunta al inicio del mapa
	len = ft_strlen(tmp->str);
	temp = temp->next;
	while (tmp)
		len_aux = ft_strlen(tmp->str);
//		if (tmp->str[len - 1] == '\n')
//			len -= 1;
		if (len_aux > len)
			len = len_aux;
			

El map              a tendra un high size desde el puntero inicial hasta donde acabe la lista




		al final setear h y w de la struct
}