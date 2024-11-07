/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:05:40 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/02 16:35:50 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_textures(t_game *game)
{
	// Try to load the file
	game->textures->text_n = mlx_load_png(game->parser.elem.no);
	game->textures->text_s = mlx_load_png(game->parser.elem.so);
	game->textures->text_e = mlx_load_png(game->parser.elem.ea);
	game->textures->text_w = mlx_load_png(game->parser.elem.we);
	if (!game->textures->text_w || !game->textures->text_e ||
		!game->textures->text_s || !game->textures->text_w)
		return (game_free(game));
	// Convert texture to a displayable image
	game->textures->img_n = mlx_texture_to_image(game->mlx,
													game->textures->text_n);
	game->textures->img_s = mlx_texture_to_image(game->mlx,
													game->textures->text_s);
	game->textures->img_e = mlx_texture_to_image(game->mlx,
													game->textures->text_e);
	game->textures->img_w = mlx_texture_to_image(game->mlx,
													game->textures->text_w);
	if (!game->textures->img_n || !game->textures->img_s ||
		!game->textures->img_e || !game->textures->img_w)
        return (game_free(game));
}

int	textures_test(t_game *game)
{
	mlx_texture_t	*text_n;//Declaration of a texture
	mlx_texture_t	*text_s;
	mlx_texture_t	*text_e;
	mlx_texture_t	*text_w;
	mlx_image_t 	*img_n;//Declaration of an image
	mlx_image_t 	*img_s;
	mlx_image_t 	*img_e;
	mlx_image_t 	*img_w;

	// Try to load the file
	text_n = mlx_load_png(game->parser.elem.no);
	text_s = mlx_load_png(game->parser.elem.so);
	text_e = mlx_load_png(game->parser.elem.ea);
	text_w = mlx_load_png(game->parser.elem.we);
	if (!text_w || !text_e || !text_s || !text_w)
    	return (1);

	// Convert texture to a displayable image
	img_n = mlx_texture_to_image(game->mlx, text_n);
	img_s = mlx_texture_to_image(game->mlx, text_s);
	img_e = mlx_texture_to_image(game->mlx, text_e);
	img_w = mlx_texture_to_image(game->mlx, text_w);
	if (!img_n || !img_s || !img_e || !img_w)
        return (1);

/*========= THIS PART IS JUST FOR TESTING ==========*/
	// Display the image
	if (mlx_image_to_window(game->mlx, img_w, 1100, 300) < 0)
        return (1);
	if (mlx_image_to_window(game->mlx, img_n, 1200, 400) < 0)
        return (1);
	if (mlx_image_to_window(game->mlx, img_s, 1300, 500) < 0)
        return (1);
	if (mlx_image_to_window(game->mlx, img_e, 1400, 600) < 0)
        return (1);
		
	return (0);
}
