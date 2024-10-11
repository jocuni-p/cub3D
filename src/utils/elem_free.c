/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:13:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/11 10:14:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Frees all allocated elements in the struct elem */
void	elem_free(t_parser *parser)
{
	if (parser->elem.no)
		free(parser->elem.no);
	if (parser->elem.so)
		free(parser->elem.so);
	if (parser->elem.we)
		free(parser->elem.we);
	if (parser->elem.ea)
		free(parser->elem.ea);
	if (parser->elem.c)
		free(parser->elem.c);
	if (parser->elem.f)
		free(parser->elem.f);
}