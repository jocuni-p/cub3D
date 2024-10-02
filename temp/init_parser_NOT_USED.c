/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:43:28 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/27 11:39:50 by jocuni-p         ###   ########.fr       */
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
	parser->elem.rgb_c[3] = {0};
	parser->elem.c_color = 0;//potser hauria de posar un -1 ????
	parser->elem.f = NULL;
	parser->elem.rgb_f[3] = {0};
	parser->elem.f_color = 0;//potser hauria de posar un -1 ????
	parser->raw_map = NULL;
}