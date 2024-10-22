/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:42:25 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/22 18:59:02 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Contains all functions that must be repeated/updated every mlx loop*/
void	updater(void *param)
{
	t_game *game = (t_game *)param;
//	ft_printf("Updating frame...\n");  // Debug
//	event_listener();
//	raycast();
	if (minimap(game))
		exit (EXIT_FAILURE);//rOJO: revisar esta salida de error
}