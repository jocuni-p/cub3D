/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:23:14 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/24 23:29:55 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_game_struct(t_game *game)
{
	printf("map size: (%i, %i)\n", game->map_w, game->map_h);//DEBUG
	printf("┌──────GAME───────────┐\n");
	printf("  map: %p\n", game->map_arr);
	printf("  map size: %i x %i\n", game->map_w, game->map_h);
	printf("  p_x: %i\n", game->p_x);
	printf("  p_y: %i\n", game->p_y);
	printf("  p_view: %c\n", game->p_view);
	printf("└─────────────────────┘\n\n");
}