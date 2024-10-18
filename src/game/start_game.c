/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:47:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/18 12:18:40 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Exit the program as failure.
void error(void)
{
	ft_printf("MLX error code: %d\n", mlx_errno);
	ft_printf("%s", mlx_strerror(mlx_errno));//prints the error string that describes the error code
	exit(EXIT_FAILURE);
}
int	start_game(t_game *game, t_parser *parser)
{
	mlx_t *mlx;
	
//	mlx_set_setting(MLX_MAXIMIZED, true);//Maximizes the window to fullscreen size
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	if (!mlx)
		return (error(), 1);
	event_listen(mlx,)
	if (minimap(mlx, game, parser))//Creates and Displays a maze minimap in a corner of our window 
		return (error(), 1);

//>>>>>>>>>>>>GRAPHIC PART<<<<<<<<<<<<<<
//	mlx_close_window(mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
	