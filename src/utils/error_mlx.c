/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:12:21 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/08 17:28:46 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Exit the program properly when a mlx failure is found.
void error_mlx(t_game *game)
{
//	ft_printf(RED "Error\n");
	ft_printf("MLX error code: %d\n", mlx_errno);
	ft_printf("%s\n", mlx_strerror(mlx_errno));//prints the error string that describes the error code
	game_free(game);
	mlx_terminate(game->mlx);
	exit(EXIT_FAILURE);
}
