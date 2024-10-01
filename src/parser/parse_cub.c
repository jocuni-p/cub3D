/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:27:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/30 17:22:21 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//Be sure to handle and manage error messages appropriately in case the function fails.
//returns 0 for success or 1 otherwise
int	parse_cub(t_parser *parser, char *filename)
{
	if (check_arg(filename))
		return (1);
	if (inputfile_to_list(parser, filename))
		return (1);
	if (parse_elements(parser))//textures & colors
		return (1);
	print_elem(parser);//TEMPORAL
	printf("pointer to the map: %s\n", parser->aux->str);
//	if (parse_map(parser))
//		return (1);
	return (0);	
}