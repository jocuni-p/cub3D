/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:38:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/10 13:32:16 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_parser	parser;
	t_game		game;

	if (ac != 2)
		return (handle_error(ERR_ARG), 1);
	init_parser(&parser);
	if (parse_cub(&parser, av[1]))
		return (parser_free(&parser), 1);
//	print_map_list(parser.map_firstline);//TEMPORAL
	init_game(&game, &parser);
	print_game(&game);
//>>>>>>>>>>>GRAPHIC_PART MISSING<<<<<<<<<<<<<

	printf("EXIT PROPERLY \U0001F44D\n\n");
	parser_free(&parser);
	return (0);
}
