/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:38:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/08 17:19:20 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_game		*game;

	if (ac != 2)
		return (print_error(ERR_ARG), 1);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (print_error(ERR_MEMORY), 1);
	ft_memset(game, 0, sizeof(t_game));
	if (parse_cub(game, av[1]))
		return (game_free(game), 1);
	if (start_game(game))
		return (1);
	game_free(game);
	return (0);//probably the program never is gonna finish here
}


/*There are 3 different images into the game window:
	-The background image, drawing half ceiling and half floor, displayed into the last window layer
	-The raycasting image, drawing the walls in the right perspective, displayed into the medium layer
	-The minimap image, drawing a top-left small square map, displayed into the first layer */