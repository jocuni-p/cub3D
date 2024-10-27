/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_updater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:42:25 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/27 20:08:08 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Contains all functions that must be repeated/updated every mlx loop*/
void	loop_updater(void *param)
{
	t_game *game = (t_game *)param;
	
	event_listener(game);
	
//--------------------BACKGROUND--------------------------
//Esta imagen no deberia actualizarse aqui porque siempre es igual
//	mlx_image_to_window(game->mlx, game->img_back, 0, 0);
//	va en la tercera capa

//--------------------RAYCASTING--------------------------
//	raycast(); Creates and manages all raycasting. It is updated every cicle/frame
//	mlx_image_to_window(game->mlx, game->img_ray, 0, 0);
// va en segunda capa

//---------------------MINIMAP----------------------------
//	minimap(game);
//	update_minimap();//SOLO SE REDIBUJA llamando a draw_minimap SI EL JUGADOR SE HA MOVIDO
//	probablemente debere poner un contador de pulsaciones para determinar si hubo movimiento???
	mlx_image_to_window(game->mlx, game->img_mmap, 0, 0);
//va en primera capa
	
}