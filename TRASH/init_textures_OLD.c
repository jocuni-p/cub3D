/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:05:40 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/07 21:44:20 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_textures(t_game *game)
{
	// Try to load the file
	game->textures.text_n = mlx_load_png(game->parser.elem.no);

	game->textures.text_s = mlx_load_png(game->parser.elem.so);
	game->textures.text_e = mlx_load_png(game->parser.elem.ea);
	game->textures.text_w = mlx_load_png(game->parser.elem.we);
	if (!game->textures.text_n || !game->textures.text_s ||
		!game->textures.text_e || !game->textures.text_w)
		return (1);
	// Convert texture to a displayable image
	game->textures.img_n = mlx_texture_to_image(game->mlx,
													game->textures.text_n);
	game->textures.img_s = mlx_texture_to_image(game->mlx,
													game->textures.text_s);
	game->textures.img_e = mlx_texture_to_image(game->mlx,
													game->textures.text_e);
	game->textures.img_w = mlx_texture_to_image(game->mlx,
													game->textures.text_w);
	if (!game->textures.img_n || !game->textures.img_s ||
		!game->textures.img_e || !game->textures.img_w)
        return (1);
	return (0);
}

