/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:38:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/27 12:13:45 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*A trick to return
return (ft_printf(ERR_FILE), free_parser(&parser), 1); */

#include "../include/cub3d.h"
//#include "../lib/libft.h"

int	main(int ac, char **av)
{
	t_parser	parser;
	
	if (ac != 2)
		return (handle_error(ERR_ARG), 1);//paso NULL hasta que no este mallocado algo que se deba liberar
//	init_parser(&parser);//creo que funcionaria bien con un memset
	ft_memset(&parser, 0, sizeof(parser));
	print_elem(&parser);//TEMPORAL
	if (parse_cub(&parser, av[1]))
		return (1);//parse_cub should manage the message to print if failed
		
//>>>>>>>>>>>GRAPHIC PART<<<<<<<<<<<<<
//	set_game//inits the mlx
//	mlx_loop(mlx);
//	mlx_terminate(mlx);//not sure if this is the proper way to finish ??
	printf("FLAG FINAL\n");
	return (0);
}
/*
HOW TO PROCEED:
- Check the correct number of arguments
- Check the correct extension of the argument
- PARSER elements
- Parser map
*/