/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:20:55 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/24 11:43:14 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_elem(t_parser *parser)
{
	printf("┌──────PARSE STRUCT─────────┐\n");
//	printf("cub: %p\n", parser->cub);
	printf("no: %s\n", parser->elem.no);
	printf("so: %s\n", parser->elem.so);
	printf("we: %s\n", parser->elem.we);
	printf("ea: %s\n", parser->elem.ea);
//	printf("c: %s\n", parser->elem.c);
//	printf("rgb_c: %i,%i,%i\n", parser->elem.rgb_c[0], parser->elem.rgb_c[1], parser->elem.rgb_c[2]);
	printf("c_color: 0x%X\n", parser->elem.c_color);
//	printf("f: %s\n", parser->elem.f);
//	printf("rgb_f: %i,%i,%i\n", parser->elem.rgb_f[0], parser->elem.rgb_f[1], parser->elem.rgb_f[2]);
	printf("f_color: 0x%X\n", parser->elem.f_color);
	printf("map size (w x h): %i x %i\n", parser->map.w, parser->map.h);
//	printf("player qty: %i\n", parser->map.player_qty);
	printf("player_view: %c\n", parser->map.player_view);
	printf("Player position: (%i,%i)\n", parser->map.player_x, parser->map.player_y);
	printf("raw_map: %p\n", parser->raw_map);
	printf("└───────────────────────────┘\n");
}
void	print_elem_and_color(t_parser *parser)
{
	printf("┌──TEXTURES & COLORS──┐\n");
	printf("  north: %p\n", parser->elem.no);
	printf("  south: %p\n", parser->elem.so);
	printf("  east: %p\n", parser->elem.ea);
	printf("  west: %p\n", parser->elem.we);
	printf("  c: %X\n", parser->elem.c_color);
	printf("  f: %X\n", parser->elem.f_color);
	printf("  opp: %X\n", parser->elem.c_opposite);
	printf("└─────────────────────┘\n");
	printf("\n");
}
