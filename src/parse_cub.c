/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:27:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/16 15:52:20 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//Take into account: to manage the printing messages if the function fails
//returns 0 for success or 1 otherwise
int	parse_cub(t_parser *parser, char *filename)
{
	if (inputfile_to_list(parser, filename));
		return (1);
		
//	parse_elements

//	parse_map (check, among others, the only 6 characters that can contain)

	return (0);
}
/*
FIRST IDEA ABOUT HOW TO DEVELOP PARSER:
Copy every line from arg_file.cub to a list.
while(line)
    limpio de espacios inicio y fin con strtrim
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

*/