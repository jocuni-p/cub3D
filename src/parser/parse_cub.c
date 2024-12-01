/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:27:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 16:28:16 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*Manage all parsing parts of the project*/
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
