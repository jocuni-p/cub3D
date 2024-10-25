/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:13:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/25 18:03:56 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Frees all allocated elements in the struct elem */
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