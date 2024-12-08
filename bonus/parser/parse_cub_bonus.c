/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:27:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/01 23:55:54 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"
/**
 * Manages all parsing tasks for the `.cub` configuration file. Validates
 * arguments, parses elements, maps, and creates a 2D array representation
 * of the map. Clears memory after processing. Returns 1 on any error.
 */
int	parse_cub(t_game *game, char *filename)
{
	if (check_arg(filename))
		return (1);
	if (lst_creator(&game->parser, filename))
		return (1);
	if (parse_elements(game))
		return (1);
	if (parse_map_1(game))
		return (1);
	if (arr2d_creator(game))
		return (1);
	lst_clear(&game->parser.cub_ln0);
	if (parse_map_2(game))
		return (1);
	return (0);
}
