/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:27:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/27 19:04:13 by jocuni-p         ###   ########.fr       */
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
	arr2d_print(game->map_arr);//TEMPORAL ??
	return (0);
}
