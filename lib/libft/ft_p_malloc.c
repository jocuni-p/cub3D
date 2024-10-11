/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<<< HEAD:lib/libft/ft_p_malloc.c
/*   Created: 2024/09/12 14:27:37 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/12 14:33:37 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Protected malloc. Allocates 'size' bytes of mem and returns a pointer to it.
Exits properly if memory allocation fails.*/
void	*p_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		write(2, "Error: memory allocation failure\n", 33);
		exit (EXIT_FAILURE);
	}
	return (ptr);
}
========
/*   Created: 2024/09/09 12:38:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/11 14:30:24 by jocuni-p         ###   ########.fr       */
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
//	print_map_list(parser.map_firstline);//TEMPORAL
	init_game(&game, &parser);
	print_game_struct(&game);//TEMPORAL
	
//>>>>>>>>>>>GRAPHIC_PART MISSING<<<<<<<<<<<<<

	parser_free(&parser);
	printf("EXIT PROPERLY \U0001F44D\n\n");//TEMPORAL
	return (0);
}
>>>>>>>> 99f7258f561db33e0d72dbda14d27f8f79fe0fc0:src/main.c
