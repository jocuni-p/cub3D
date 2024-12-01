/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 06:32:54 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/30 18:54:41 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* Frees all mlx allocated textures */
void	textures_free(t_game *game)
{
	if (game->textures.text_n)
		mlx_delete_texture(game->textures.text_n);
	if (game->textures.text_s)
		mlx_delete_texture(game->textures.text_s);
	if (game->textures.text_e)
		mlx_delete_texture(game->textures.text_e);
	if (game->textures.text_w)
		mlx_delete_texture(game->textures.text_w);
}
