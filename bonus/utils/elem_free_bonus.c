/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:13:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/02 01:21:38 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

/**
 * Frees all dynamically allocated elements in the `elem` structure of the
 * game's parser. Handles textures and colors.
 */
void	elem_free(t_game *game)
{
	if (game->parser.elem.no)
		free(game->parser.elem.no);
	if (game->parser.elem.so)
		free(game->parser.elem.so);
	if (game->parser.elem.we)
		free(game->parser.elem.we);
	if (game->parser.elem.ea)
		free(game->parser.elem.ea);
	if (game->parser.elem.c)
		free(game->parser.elem.c);
	if (game->parser.elem.f)
		free(game->parser.elem.f);
}
