/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:38:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/08 17:02:39 by jocuni-p         ###   ########.fr       */
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
	{
//CREO QUE LO OPTIMO ES PONER EL LST_CLEAR AQUI (Y NO EN CADA FUNCION)
//		lst_clear(&parser.cub);//guardarme un cop tinc la llista un punter a l'inici 
		parser_free(&parser);
		return (1);//manage the message to print if failures
	}
//	print_map_list(parser.map_firstline);//TEMPORAL

	
//>>>>>>>>>>>GRAPHIC_PART MISSING<<<<<<<<<<<<<
//	lst_clear(&parser.cub);
	parser_free(&parser);
	printf("EXIT PROPERLY \U0001F44D\n\n");
	return (0);
}
