/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:43:28 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/17 15:01:50 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*----Sets to 0 all struct variables----*/ 
void	init_parser(t_parser *parser)
{
	parser->cub = NULL;
	parser->elem.no = NULL;
	parser->elem.no_qty = 0;
	parser->elem.so = NULL;
	parser->elem.so_qty = 0;
	parser->elem.we = NULL;
	parser->elem.we_qty = 0;
	parser->elem.ea = NULL;
	parser->elem.ea_qty = 0;
	parser->elem.c = NULL;
	parser->elem.c_qty = 0;
	parser->elem.f = NULL;
	parser->elem.f_qty = 0;
	parser->raw_map = NULL;
//	parser->player_x = 0;
//	parser->player_y = 0;
//	parser->player_view = 0;
}