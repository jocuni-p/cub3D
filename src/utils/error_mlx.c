/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:12:21 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 19:01:25 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Exit the program properly when a mlx failure is found.
void	error_mlx(t_game *game)
{
	if (mlx_errno != 0)
	{
		ft_printf("Error\nMLX error code: %d\n", mlx_errno);
		ft_printf("%s\n", mlx_strerror(mlx_errno));
	}
	game_free(game);
	mlx_terminate(game->mlx);
	exit(EXIT_FAILURE);
}
