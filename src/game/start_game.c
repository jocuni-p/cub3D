/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:47:00 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/22 19:50:20 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Exit the program as failure.
void error(void)
{
	ft_printf("MLX error code: %d\n", mlx_errno);
	ft_printf("%s", mlx_strerror(mlx_errno));//prints the error string that describes the error code
	exit(EXIT_FAILURE);//attention must be freed all mallocs from parsing part
}
int	start_game(t_game *game, t_parser *parser)
{
	mlx_t *mlx;
	
//	mlx_set_setting(MLX_MAXIMIZED, false);//Maximizes the window to fullscreen size
	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	if (!mlx)
		return (error(), 1);
		
	if (init_game(mlx, game, parser))
		 return (error(), 1);
	
	print_game_struct(game);//TEMPORAL
	
//		ft_printf("retorno de mlx_image_to_window = %d\n", ret);//TEMPORAL
//		return (error(), 1);
//starts the loop_hook that will be repeated continously every frame. It returns a boolean.
//It is executed each frame and updates the functions inside 'updater'
	mlx_loop_hook(game->mlx, updater, game);
//		return (error(), 1);
	mlx_image_to_window(game->mlx, game->game_img, 0, 0);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
	