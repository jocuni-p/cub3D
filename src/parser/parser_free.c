/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:00:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/08 17:22:06 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
//>>>>>>>>>>>>>>>>IN CONSTRUCTION<<<<<<<<<<<<<<<<<<<<<<

/*Frees all allocated elements in the struct elem */
void	elem_free(t_elem elem)
{
	if(elem.no)
		free(elem.no);
	if(elem.no)
		free(elem.so);
	if(elem.no)
		free(elem.we);
	if(elem.no)
		free(elem.ea);
	if(elem.no)
		free(elem.c);
	if(elem.no)
		free(elem.f);
}

/*------Frees all t_parser struct memory-----*/
//LIBERADOR FINAL DEL PROGRAMA SI TODO FUE BIEN
void	parser_free(t_parser *parser)
{
	lst_clear(&parser->cub);//libera la lista cub, crear un punter a l'inici i guardarlo
	elem_free(parser->elem);
	arr2d_free(&parser->raw_map);
}
