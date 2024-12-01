/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:00:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/25 17:38:17 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Frees all resources allocated in the parser, including the map and elements.
 * Clears the linked list and element values.
 */
void	parser_free(t_game *game)
{
	lst_clear(&game->parser.cub_ln0);
	elem_free(game);
}

/**
 * Frees all dynamically allocated resources in the game structure. Handles
 * parser data, 2D map array, textures, and raycasting data.
 */
void	game_free(t_game *game)
{
	parser_free(game);
	arr2d_free(&game->map_arr);
	textures_free(game);
	ray_free(game);
}
