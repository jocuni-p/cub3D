/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:12:21 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/31 19:45:00 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Exit the program properly when a mlx failure is found.
void error_mlx(t_game *game)
{
	ft_printf(RED "Error\n");
//	ft_printf("MLX error code: %d\n", mlx_errno);
	ft_printf(RED "%s\n", mlx_strerror(mlx_errno));//prints the error string that describes the error code
	game_free(game);
	exit(EXIT_FAILURE);
}
