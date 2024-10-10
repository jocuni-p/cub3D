/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:27:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/10 17:04:17 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*Manage all parsing parts of the project*/
int	parse_cub(t_parser *parser, char *filename)
{
	if (check_arg(filename))
		return (1);
	if (lst_creator(parser, filename))
		return (1);
//	print_cub_list(parser->cub);//TEMPORAL
	if (parse_elements(parser))
		return (1);
//	printf("map_pointer>>>%s\n", parser->cub->str);//TEMPORAL
	if (parse_map_1(parser))
		return (1);
	if (arr2d_creator(parser))
		return (1);
	if (parse_map_2(parser))
		return (1);
	print_elem(parser);//TEMPORAL
	arr2d_print(parser->raw_map);//TEMPORAL
	return (0);
}
