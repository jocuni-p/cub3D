/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:00:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/09 15:40:39 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Frees all allocated elements in the struct elem */
void	elem_free(t_parser *parser)
{
	if(parser->elem.no)
		free(parser->elem.no);
	if(parser->elem.so)
		free(parser->elem.so);
	if(parser->elem.we)
		free(parser->elem.we);
	if(parser->elem.ea)
		free(parser->elem.ea);
	if(parser->elem.c)
		free(parser->elem.c);
	if(parser->elem.f)
		free(parser->elem.f);
}

/*------Frees all t_parser struct memory-----*/
void	parser_free(t_parser *parser)
{
//	lst_clear(&parser->cub);
	lst_clear(&parser->cub_firstline);
	elem_free(parser);
	arr2d_free(&parser->raw_map);
}
