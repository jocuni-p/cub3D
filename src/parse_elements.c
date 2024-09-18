/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:34:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/18 18:42:12 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_elements(t_parser *parser)
{
	t_cub 	*aux;
	char	*trimmed_line;
	
	aux = parser->cub;
	while(aux)
	{
		if (ft_strchr(aux->str, '\t'))//if a tab is found the program finishes
			return (handle_error(ERR_FILE, parser_free(parser)), 1);
		remove_nl(aux->str);
//		if (!aux->str)//la linea esta vacia
//		eliminar el nodo quizas no hace falta, basta con saltarlo si esta vacio
		trimmed_line = ft_strtrim(aux->str, " ");//returns a new malloced str
		//OJO liberar la linea y sustituir por la nueva mallocada
		free(aux->str);
		aux->str = trimmed_line;	
		
			
		printf("%i\n", aux1->content);//ELIMINAR
		else
		aux = aux->next;
	}
	
}
/*
while(line)
v   si [0] es \n -> remove node -> continue
v	remove the '\n' 
v   si hay algun ´tab' en la linea -> exit
v    clean spaces on the beginning and at the end with strtrim
    while(str[i] != ´\0´), 
    	if (str[0] == N && str[1] == O && str[2] == _   )
                   str + 3
                 
      		if (no_qty == 0) set whit 1 else ->exit
      		get the path
              set his var in the struct with the value
		if (str[i] == F && str[i+1] == _ && C_)
      get the color
else-> exit
*/
