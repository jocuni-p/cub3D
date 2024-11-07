/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 06:32:54 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/07 06:40:58 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* Frees all allocated elements in the textures struct */
void	textures_free(t_game *game)
{
	if (game->textures->text_n)
		free(game->textures->text_n);
	if (game->textures->text_s)
		free(game->textures->text_s);
	if (game->textures->text_e)
		free(game->textures->text_e);
	if (game->textures->text_w)
		free(game->textures->text_w);
	if (game->textures->img_n)
		free(game->textures->img_n);
	if (game->textures->img_s)
		free(game->textures->img_s);
	if (game->textures->img_e)
		free(game->textures->img_e);
	if (game->textures->img_w)
		free(game->textures->img_w);
	if (game->textures->img_w)
		free(game->textures->img_w);
}