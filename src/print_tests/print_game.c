/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:23:14 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/30 14:43:32 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_game(t_game *game)
{
	printf("┌───────────────GAME──────────────┐\n");
	printf("  map size (w, h): (%i, %i)\n", game->map_w, game->map_h);
	printf("  player.pos: (%f,%f)\n", game->player.pos.x, game->player.pos.y);
	printf("  player.dir: (%f,%f)\n", game->player.dir.x, game->player.dir.y);
	printf("  p.orientation %c\n", game->player.orientation);
	printf("└─────────────────────────────────┘\n\n");
}
