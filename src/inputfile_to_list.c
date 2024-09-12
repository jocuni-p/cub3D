/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputfile_to_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:01:35 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/12 12:48:15 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*----Copies every line from the input_filename into a list----*/
/*gets a line from filename, puts it in a node and adds the node to a list */
//OJO >>>con lo que entrega la funcion, porque ya pone la lista en la struct<<<<<
t_cub	**inputfile_to_list(t_parser *parser, char *filename)
{
	int		fd;
	char	*line;
	t_cub	*node;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (?????);//devolver senyal para saber que ha fallado 

	line = get_next_line(fd);
	if (line == NULL)
		return (????);//devolver senyal para saber que el mapa esta vacio
		
	while (line != NULL)
	{
		node = lst_newnode(line);
		lstadd_back(&parser->cub, node);
		line = get_next_line(fd);
//		lstadd_back(&(parser->cub), lst_newnode(get_next_line(fd)));
	}
	close(fd);
	return (?????)////devolver senyal para saber que ha ido bien
}