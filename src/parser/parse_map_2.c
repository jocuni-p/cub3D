/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:33:39 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/03 16:00:30 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_map_2(t_parser *parser)
{




	return (0);
}
//si la matriz tiene menos de 3 de ancho y menos de 3 de alto (medidas minimas)->INVALID
//si la matriz contiene player (N, S, W, E) y solo 1 player (contarlos todos y el total solo puede ser 1)-> seguir
//si el mapa esta abierto (es decir, un 0 junto a un espacio)->INVALID