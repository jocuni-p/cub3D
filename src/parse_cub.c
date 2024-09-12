/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:27:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/12 12:59:44 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

/*----Sets to 0 all struct variables----*/ 
void	init_parser(t_parser *parser)
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

//Take into account: to manage the printing messages if the function fails
int	parse_cub(t_parser *parser, char *filename)//return 0 for success or 1 otherwise
{
	
	inputfile_to_list(parser, filename);

//		parse_elements
//		parse_map (check, among others, the only 6 characters that can contain)
}
/*NOTES: 
tabs: I am gonna manage the ´tab´ in the input file as an invalid argument 
space: think about how to manage it in the map*/