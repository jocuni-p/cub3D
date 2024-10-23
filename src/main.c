/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:38:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/23 16:22:02 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_parser	parser;
	t_game		game;

	if (ac != 2)
		return (print_error(ERR_ARG), 1);
	init_parser(&parser);
	if (parse_cub(&parser, av[1]))
		return (parser_free(&parser), 1);
//	print_game_struct(&game);//TEMPORAL
	print_elem_and_color(&parser);//TEMPORAL
	if (start_game(&game, &parser))

	parser_free(&parser);//this free + 'exit' must be called when 'esc' or 'close window' are pressed
//	printf("EXIT PROPERLY \U0001F44D\n\n");//TEMPORAL
	return (0);//probably the program never is gonna finish here
}

/*There will be 3 different images into the game window:
	-The background image, drawing half ceiling and half floor, displayed into the last window layer
	-The raycasting image, drawing the walls in the right perspective, displayed into the medium layer
	-The minimap image, drawing a top-left small square map, displayed into the first layer */