/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:38:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/15 14:56:38 by jocuni-p         ###   ########.fr       */
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
	init_game(&game, &parser);
	print_game_struct(&game);//TEMPORAL
	
	if (start_game(&game))

	parser_free(&parser);
//	printf("EXIT PROPERLY \U0001F44D\n\n");//TEMPORAL
	return (0);
}
