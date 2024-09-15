/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:38:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/14 12:36:53 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*A trick to return
return (ft_printf(ERR_FILE), free_parser(&parser), 1); */

#include "./inc/cub3d.h"


int	main(int ac, char **av)
{
	t_parser	parser;
	
	if (ac != 2)
		return (msg_printf(ERR_ARG), 1);
	if (check_file_ext(av[1]));//maybe could be moved inside parser
		return (msg_printf(ERR_EX), 1);
	init_parser(&parser, av[1]);//maybe could be moved inside parser
	

	if (parse_cub(&parser, av[1]));
		return (1);//parse_cub will manage the message to print if failed


	set_game//inits the mlx

	
	mlx_loop(mlx);
	mlx_terminate(mlx);//not sure if this is the proper way to finish ??
	return (0);
}
/*
HOW TO PROCEED:
- Check the correct number of arguments
- Check the correct extension of the argument
PARSER
Initialize to 0 my var struct
Copy every line from arg_file.cub to a list.
while(line)
    limpio de espacios inicio y  fin con strtrim
    si [0] es \n -> continue
    si hay algun ´tab' en la linea -> exit
    while(str[i] != ´\0´), 
          if (str[i] == N && str[i+1] == O && str[i+2] == _   )
                   str + 3
                 
      if (no_qty == 0) set whit 1 else ->exit
      get the path
              set his var in the struct with the value
if (str[i] == F && str[i+1] == _ && C_)
      get the color
else-> exit
  
NOTES: 
tabs: I going to manage the ´tab´ in the input file as an INVALID argument 
space: think about how to manage it in the map*/