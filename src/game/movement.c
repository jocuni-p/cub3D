/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:19:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/27 20:03:06 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	event_listener(t_game *game)
{
	if(mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);//+ salir limpiamente del programa
/*		
	if(mlx_is_key_down(game->mlx, MLX_KEY_W))
		move();//mueve ply_pix_pos
//		move(scene, scene->player.dir.y, -scene->player.dir.x, SPEED);
	if(mlx_is_key_down(game->mlx, MLX_KEY_S))
		move();
	if(mlx_is_key_down(game->mlx, MLX_KEY_A))
		move();
	if(mlx_is_key_down(game->mlx, MLX_KEY_D))
		move();
		
	if(mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
//		rotate();
	if(mlx_is_key_down(mlx, MLX_KEY_RIGHT))
//		rotate();
*/
}