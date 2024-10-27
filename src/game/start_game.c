/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:47:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/27 19:59:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Exit the program as failure.
void error(void)
{
	ft_printf("MLX error code: %d\n", mlx_errno);
	ft_printf("%s", mlx_strerror(mlx_errno));//prints the error string that describes the error code
	exit(EXIT_FAILURE);//attention, first must be freed all mallocs from parsing part
}
int	start_game(t_game *game)
{
	mlx_t *mlx;
	
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	if (!mlx)
		return (error(), 1);
	if (init_game(mlx, game))
		 return (error(), 1);
	
//	printf("start_game\n");//DEBUG
	
//It is executed each frame, updated accordingly every keypress/movement 
	mlx_loop_hook(mlx, loop_updater, game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
	