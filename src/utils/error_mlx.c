/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:12:21 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/29 22:42:22 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Exit the program properly when a mlx failure is found.
void error_mlx(t_game *game)
{
	if (mlx_errno != 0)
	{
		ft_printf("Error\nMLX error code: %d\n", mlx_errno);//prints the MLX error code
		ft_printf("%s\n", mlx_strerror(mlx_errno));//prints a string that describes the error code
	}
	game_free(game);
	mlx_terminate(game->mlx);
	exit(EXIT_FAILURE);
}
