/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:20:55 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 19:47:14 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_elements(t_game *game)
{
	printf("┌──────────────ELEMENTS────────────┐\n");
	printf("  no: %s\n", game->parser.elem.no);
	printf("  so: %s\n", game->parser.elem.so);
	printf("  we: %s\n", game->parser.elem.we);
	printf("  ea: %s\n", game->parser.elem.ea);
	printf("  c:  0x%X\n", game->parser.elem.c_color);
	printf("rgb_c[3]: %d,%d,%d\n", game->parser.elem.rgb_c[0],
		game->parser.elem.rgb_c[1], game->parser.elem.rgb_c[2]);
	printf("  op: 0x%X\n", game->parser.elem.c_opposite);
	printf("  f:  0x%X\n", game->parser.elem.f_color);
	printf("└──────────────────────────────────┘\n");
	printf("\n");
}
