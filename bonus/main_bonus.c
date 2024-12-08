/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:38:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/02 19:14:46 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

/**
 * The entry point of the program. Validates the command-line arguments
 * and initializes the game structure. Parses the `.cub` configuration file
 * and starts the game if parsing succeeds. Frees allocated resources on
 * failure or program exit. Returns 0 on successful execution, otherwise 1.
 *
 * Notes:
 * - Accepts exactly one command-line argument: the `.cub` file.
 * - Initializes three images in the game:
 *   - Background: Ceiling and floor, rendered on the last layer.
 *   - Raycasting: Walls, rendered on the middle layer.
 *   - Minimap: A small top-left map, rendered on the first layer.
 */
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
	game_free(game);
	free(game);
	return (0);
}
