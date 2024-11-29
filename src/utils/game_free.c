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

/*------Frees parser' allocated resources-----*/
void	parser_free(t_game *game)
{
	lst_clear(&game->parser.cub_ln0);
	elem_free(game);
}

/*------Frees game' allocated resources-----*/
void	game_free(t_game *game)
{
	parser_free(game);
	arr2d_free(&game->map_arr);
	textures_free(game);
	ray_free(game);
	//free(game);
}
