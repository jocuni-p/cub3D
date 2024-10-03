/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:38:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/03 14:30:27 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*A trick to save lines:
return (ft_printf(ERR_FILE), free_parser(&parser), 1); */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_parser	parser;

	if (ac != 2)
		return (handle_error(ERR_ARG), 1);	
	ft_memset(&parser, 0, sizeof(parser));//Initializes all parser' vars to 0
	if (parse_cub(&parser, av[1]))
		return (1);//manage the message to print if failures
	print_map_list(parser.map_firstline);//TEMPORAL

	
//>>>>>>>>>>>GRAPHIC_PART MISSING<<<<<<<<<<<<<

	printf("EXIT PROPERLY\n");
	return (0);
}
