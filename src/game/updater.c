/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:42:25 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/24 18:09:23 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Contains all functions that must be repeated/updated every mlx loop*/
void	updater(void *param)
{
	t_game *game = (t_game *)param;
	
//	event_listener(); ESTA FUNCION NO SE BIEN DONDE HA DE IR
	
//--------------------BACKGROUND--------------------------
	mlx_image_to_window(game->mlx, game->img_backgr, 0, 0);
//	va en la tercera capa

//--------------------RAYCASTING--------------------------
//	raycast(); Creates and manages all raycasting. It is updated every cicle/frame
//	mlx_image_to_window(game->mlx, game->img_raycasting, 0, 0);
// va en segunda capa

//---------------------MINIMAP----------------------------
//	minimap(game);
//	update_minimap();//SOLO SE REDIBUJA llamando a draw_minimap SI EL JUGADOR SE HA MOVIDO
	//probablemente debere poner un contador de pulsaciones para determinar si hubo movimiento???
	mlx_image_to_window(game->mlx, game->img_minimap, 0, 0);
//va en primera capa
	
}