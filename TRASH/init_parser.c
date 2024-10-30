/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:43:28 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/25 18:06:59 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*----Sets to 0 all struct and substruct variables----*/
void	init_parser(t_parser *parser)
{
	parser->cub = NULL;
	parser->cub_ln0 = NULL;
	parser->map_ln0 = NULL;
	parser->elem.no = NULL;
	parser->elem.so = NULL;
	parser->elem.we = NULL;
	parser->elem.ea = NULL;
	parser->elem.c = NULL;
	parser->elem.rgb_c[0] = 0;
	parser->elem.rgb_c[1] = 0;
	parser->elem.rgb_c[2] = 0;
	parser->elem.c_color = 0;
	parser->elem.c_opposite = 0;
	parser->elem.f = NULL;
	parser->elem.rgb_f[0] = 0;
	parser->elem.rgb_f[1] = 0;
	parser->elem.rgb_f[2] = 0;
	parser->elem.f_color = 0;
	parser->map.w = 0;
	parser->map.h = 0;
	parser->map.ply_qty = 0;
	parser->map.ply_view = 0;
	parser->map.ply_x = 0;
	parser->map.ply_y = 0;
	parser->raw_map = NULL;
}
