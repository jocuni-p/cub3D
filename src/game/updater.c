/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:42:25 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/21 17:03:01 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

/*Contains all functions that must be repeated/updated every mlx loop*/
updater()
{

	event_listener();

//	raycast();
	
	if (minimap(mlx, game, parser))//Creates anddisplays a maze minimap in a corner of our window 
		return (error(), 1);//Hace falta un retorno error ??

	


	
}