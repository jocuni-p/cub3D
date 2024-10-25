/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:38:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/25 20:05:37 by jocuni-p         ###   ########.fr       */
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
		
//	print_game_struct(&game);//TEMPORAL
	print_elem_and_color(&game->parser);//TEMPORAL
	
	if (start_game(game))
	
//	printf("main\n");//DEBUG
	game_free(game);//this free + 'exit' must be called when 'esc' or 'close window' are pressed
//	printf("EXIT PROPERLY \U0001F44D\n\n");//TEMPORAL
	return (0);//probably the program never is gonna finish here
}



/*There will be 3 different images into the game window:
	-The background image, drawing half ceiling and half floor, displayed into the last window layer
	-The raycasting image, drawing the walls in the right perspective, displayed into the medium layer
	-The minimap image, drawing a top-left small square map, displayed into the first layer */

/*NOTE: It is pending to decide if the minimap image has to have a surrounding frame or not.*/