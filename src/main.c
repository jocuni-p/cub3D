/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:38:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/11 18:45:04 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*A trick to return
return (ft_printf(ERR_FILE), free_parser(&parser), 1); */

#include "../inc/cub3d.h"


int	main(int ac, char **av)
{
	t_parser	parser;
	
	if (ac != 2)
		return (ft_printf(ERR_ARG), 1);
	if (check_file_ext(av[1]));//maybe could be moved inside parser
		return (ft_printf(ERR_EX), 1);
	init_parser(&parser, av[1]);//maybe could be moved inside parser
	

	if (parse_cub(&parser, av[1]));//OJO: manage the return if it fails
		return (1);//parse_cub will manage the message to print if failed
//		parse_elements
//		parse_map (check, among others, the only 6 characters that can contain)


	set_game//inits the mlx

	
	mlx_loop(mlx);
	mlx_terminate(mlx);//not sure if this is the proper way to finish ??
	return (0);
}
