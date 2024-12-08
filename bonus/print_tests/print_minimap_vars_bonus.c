/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap_vars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:22:07 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 19:49:13 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	print_minimap_vars(t_game *game)
{
	printf("--------MINIMAP_VARS-------\n");
	printf("start_col: %d, end_col: %d\n", game->mmap.start_col,
		game->mmap.end_col);
	printf("start_row: %d, end_row: %d\n", game->mmap.start_row,
		game->mmap.end_row);
	printf("map_offset_x: %d, map_offset_y: %d\n", game->mmap.map_offset_x,
		game->mmap.map_offset_y);
	printf("pl_screen_x: %d, pl_screen_y: %d\n", game->mmap.pl_screen_x,
		game->mmap.pl_screen_y);
	printf("player.pos: (%f, %f)\n\n\n", game->player.pos.x,
		game->player.pos.y);
}
