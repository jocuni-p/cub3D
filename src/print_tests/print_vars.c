/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:20:55 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/26 16:08:47 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_elem(t_game *game)
{
	printf("┌──────VARIABLES─────────┐\n");
//	printf("cub: %p\n", parser->cub);
//	printf("c: %s\n", parser->elem.c);
//	printf("rgb_c: %i,%i,%i\n", parser->elem.rgb_c[0], parser->elem.rgb_c[1], parser->elem.rgb_c[2]);
	printf("c_color: 0x%X\n", game->parser.elem.c_color);
//	printf("f: %s\n", parser->elem.f);
//	printf("rgb_f: %i,%i,%i\n", parser->elem.rgb_f[0], parser->elem.rgb_f[1], parser->elem.rgb_f[2]);
	printf("f_color: 0x%X\n", game->parser.elem.f_color);
//	printf("player qty: %i\n", parser->map.ply_qty);
//	printf("raw_map: %p\n", parser->raw_map);
	printf("└───────────────────────────┘\n");
}
void	print_elem_and_color(t_game *game)
{
	printf("┌──TEXTURES & COLORS──┐\n");
	printf("no: %s\n", game->parser.elem.no);
	printf("so: %s\n", game->parser.elem.so);
	printf("we: %s\n", game->parser.elem.we);
	printf("ea: %s\n", game->parser.elem.ea);
//	printf("  north: %p\n", parser->elem.no);
//	printf("  south: %p\n", parser->elem.so);
//	printf("  east: %p\n", parser->elem.ea);
//	printf("  west: %p\n", parser->elem.we);
	printf("  c: 0x%X\n", game->parser.elem.c_color);
	printf("  f: 0x%X\n", game->parser.elem.f_color);
	printf("  opp: 0x%X\n", game->parser.elem.c_opposite);
	printf("└─────────────────────┘\n");
	printf("\n");
}

void	print_variables(t_game *game)
{
	printf("┌──────────VARIABLES────────────┐\n");
	printf("  no: %s\n", game->parser.elem.no);
	printf("  so: %s\n", game->parser.elem.so);
	printf("  we: %s\n", game->parser.elem.we);
	printf("  ea: %s\n", game->parser.elem.ea);
	printf("  c:  0x%X\n", game->parser.elem.c_color);
	printf("  op: 0x%X\n", game->parser.elem.c_opposite);
	printf("  f:  0x%X\n", game->parser.elem.f_color);
	printf("  map size: %i x %i\n", game->map_w, game->map_h);
	printf("  pl_orig: (%i,%i)\n", game->pl_orig[0], game->pl_orig[1]);
	printf("  pl_view: %c\n", game->pl_view);
	printf("└───────────────────────────────┘\n");
	printf("\n");
}