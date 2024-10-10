/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:23:14 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/10 13:34:14 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_game(t_game *game)
{
	ft_printf("====GAME STRUCT VALUES====\n");
	ft_printf("map: %p\n", game->map);
	ft_printf("p_x: %i\n", game->p_x);
	ft_printf("p_y: %i\n", game->p_y);
	ft_printf("p_view: %c\n", game->p_view);
	ft_printf("\n");
}