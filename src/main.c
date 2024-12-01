/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:38:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/01 21:48:36 by jocuni-p         ###   ########.fr       */
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
	{
		game_free(game);
		free(game);
		return (1);
	}
	if (start_game(game))
	{
		game_free(game);
		free(game);
		return (1);
	}
	return (0);
}
