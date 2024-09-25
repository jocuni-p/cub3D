/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:27:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/25 14:31:58 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//Take into account: to manage the printing messages if the function fails
//returns 0 for success or 1 otherwise
int	parse_cub(t_parser *parser, char *filename)
{
	if (check_arg(filename))
		return (1);
	if (inputfile_to_list(parser, filename))
		return (1);
	if (parse_elements(parser))//textures
		return (1);
	print_elem(parser);
//	if (parse_color(parser, parser->elem.c) || parse_color(parser, parser->elem.f))//colors
//		return (1);

//	if (parse_colors(parser))
//		return (1);
//	if (funcio flag que diu si ja tenim els 6 elements

//	parse_map (check, among others, the only 6 characters that can contain, the walls, ...)
//		funcion que me lleva directo al nodo donde empieza el mampa(while de 6 iteraciones)
//	liberar toda la lista parser->cub al acabar el parseo.
	return (0);
}
/*
FIRST IDEA ABOUT HOW TO DEVELOP PARSER:
Copy every line from arg_file.cub to a list.
while(line)
    si [0] es \n -> remove node -> continue
	remove the '\n' if it exist
    clean spaces on the beginning and the end with strtrim
    si hay algun ´tab' en la linea -> exit
    while(str[i] != ´\0´), 
    	if (str[0] == N && str[1] == O && str[2] == _   )
                   str + 3
                 
      		if (no_qty == 0) set whit 1 else ->exit
      		get the path
              set his var in the struct with the value
		if (str[i] == F && str[i+1] == _ && C_)
      get the color
else-> exit


Cuando ya tenga todas las variables parseadas y si son correctas,
el mapa parseado y formateado bien, habre de ir poniendo las variables
 finales en una struct t_data que le pasare a Roman.
 
 typedef struct s_data//IN PROGRESS
{
	char	**map;//already formated with rectangular shape
			


}			t_data;
*/