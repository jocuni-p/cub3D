/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 06:32:54 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/07 21:53:43 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* Frees all allocated elements in the textures struct */
void	textures_free(t_game *game)
{
	if (game->textures.text_n)
		mlx_delete_texture(game->textures.text_n);
//		free(game->textures.text_n);
	if (game->textures.text_s)
		mlx_delete_texture(game->textures.text_n);
//		free(game->textures->text_s);
	if (game->textures.text_e)
		mlx_delete_texture(game->textures.text_n);
//		free(game->textures->text_e);
	if (game->textures.text_w)
		mlx_delete_texture(game->textures.text_n);
//		free(game->textures->text_w);

//ATTENTION:	IF mlx_terminate DO NOT FREES THE MEMORY ALLOCATED 
//				FROM mlx_image_t IMAGES UNCOMMENT THE CODE BELLOW

//	if (game->textures->img_n)
//		free(game->textures->img_n);
//	if (game->textures->img_s)
//		free(game->textures->img_s);
//	if (game->textures->img_e)
//		free(game->textures->img_e);
//	if (game->textures->img_w)
//		free(game->textures->img_w);
}
