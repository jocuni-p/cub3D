/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:27:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/11 18:49:16 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

static void	init_parser(t_parser *parser)
{
	parser->cub = NULL;
	parser->elem.no = NULL;	
	parser->elem.so = NULL;
	parser->elem.we = NULL;
	parser->elem.ea = NULL;
	parser->elem.c = NULL;
	parser->elem.f = NULL;
	parser->raw_map = NULL;
	parser->player_x = 0;
	parser->player_y = 0;
	parser->player_view = 0;
}

//this function has to manage the printing message if fails
int	parse_cub(t_parser *parser, char *filename)//return 0 for success or 1 otherwise
{
	
	input_file_to_list(parser, filename);

//		parse_elements
//		parse_map (check, among others, the only 6 characters that can contain)
}