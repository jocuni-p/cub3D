/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:43:28 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/21 19:18:16 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*----Sets to 0 all struct variables----*/ 
void	init_parser(t_parser *parser)
{
	parser->cub = NULL;
	parser->elem.no = NULL;
	parser->elem.so = NULL;
	parser->elem.we = NULL;
	parser->elem.ea = NULL;
	parser->elem.c = NULL;
	parser->elem.f = NULL;
	parser->raw_map = NULL;
}