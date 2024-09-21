/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:34:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/21 22:42:30 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_elements(t_parser *parser)
{
	t_cub 	*aux;
	char	**elements;
	
	aux = parser->cub;
	while(aux)
	{
		if (aux->str == NULL)
		{
			aux = aux->next;
			continue;
		}
		remove_nl(aux->str);
		if (check_valid_chars(aux->str))
//			return (handle_error(ERR_FILE), parser_free(parser)), 1);
			return (handle_error(ERR_FILE), 1);
		elements = ft_split(aux->str, ' ');//retorna un char ** con 2 elementos mallocados
		if (arr2d_element_cnt(elements) != 2)//checks if the array contains only 2 elements
		{
			arr2d_free(elements);
//			return (handle_error(ERR_FILE), parser_free(parser)), 1);
			return (handle_error(ERR_FILE), 1);
		}
		if (set_element(parser, elements))//gets the content of each element
//			return (handle_error(ERR_FILE), parser_free(parser)), 1);
			return (handle_error(ERR_FILE), 1);
		aux = aux->next;
	}
	return (0);
}

/*--MY PROCEEDING TO PARSE THE ELEMENTS
-Once all input_file lines are in a list
-Remove the '\0'
-Put every word of the line in a char **arr via split
-If **arr has different than 2 elements -> INVALID -> Error
-With a strcmp I check if the arr[first element] == "NO" && if his var_name is not set yet (NULL)
-I set (with strdup) the var_name with the content of arr[second element] and free the **arr
-Elements 'F' and 'C' must to be parsed deeper. With a split + atoi I'll know if the number of 
elements is correct and get every individual color.
-  


-At this moment I should have all elements data in my struct.
*/
