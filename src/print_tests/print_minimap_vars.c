/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap_vars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:22:07 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/30 10:59:59 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_minimap_vars(t_game *game)
{
	printf("--------MINIMAP_VARS-------\n");//DEBUG
	printf("start_col: %d, end_col: %d\n", game->mmap.start_col,
	 game->mmap.end_col);//DEBUG
	printf("start_row: %d, end_row: %d\n", game->mmap.start_row,
	 game->mmap.end_row);//DEBUG
	printf("map_offset_x: %d, map_offset_y: %d\n", game->mmap.map_offset_x,
	 game->mmap.map_offset_y);//DEBUG
	printf("pl_screen_x: %d, pl_screen_y: %d\n", game->mmap.pl_screen_x,
	 game->mmap.pl_screen_y);//DEBUG
//	printf("pl_orig_pos: (%d, %d)\n\n\n", game->pl_orig[0], game->pl_orig[1]);//DEBUG
	printf("player.pos: (%f, %f)\n\n\n", game->player.pos.x, game->player.pos.y);//DEBUG
}