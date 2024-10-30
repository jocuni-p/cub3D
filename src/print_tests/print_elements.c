/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:20:55 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/30 14:43:35 by jocuni-p         ###   ########.fr       */
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
	printf("  op: 0x%X\n", game->parser.elem.c_opposite);
	printf("  f:  0x%X\n", game->parser.elem.f_color);
//	printf("  player initial orientation: %c\n", game->player.orientation);
	printf("└──────────────────────────────────┘\n");
	printf("\n");
}
