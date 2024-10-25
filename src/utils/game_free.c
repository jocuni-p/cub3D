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

/*------Frees all t_parser struct memory-----*/
void	game_free(t_game *game)
{
	lst_clear(&game->parser.cub_ln0);
	elem_free(game);
	arr2d_free(&game->parser.raw_map);
}
