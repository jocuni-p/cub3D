/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:27:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/06 13:35:04 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//Be sure to handle and manage error messages appropriately in case the function fails.
//returns 0 for success or 1 otherwise
int	parse_cub(t_parser *parser, char *filename)
{
	if (check_arg(filename))
		return (1);
	if (lst_creator(parser, filename))
		return (1);
//	print_cub_list(parser->cub);//>>>>>>>>>>>>>>TEMPORAL
//	print_elem(parser);//>>>>>>>>>>>>>>>>>>>>>>>TEMPORAL
	if (parse_elements(parser))//textures & colors
		return (1);
//	print_elem(parser);//>>>>>>>>>>>>>>>>>>>>>>>TEMPORAL
//	printf("map_pointer>>>%s\n", parser->cub->str);//TEMPORAL
	if (parse_map_1(parser))
		return (1);
	if (arr2d_creator(parser))
		return (1);
	print_elem(parser);//TEMPORAL
	arr2d_print(parser->raw_map);//TEMPORAL
	if (parse_map_2(parser))
		return (1);
	return (0);	
}
//>>>>>>>GESTIONAR TODOS RETURN -> LOS HANDLE ERROR>>>>>>>>>>>>>>>
