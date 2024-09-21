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

#include "../include/cub3d.h"

/*----Copies every line from filename into a list----*/
/*Gets a line from filename(fd), puts it in a node and adds the node to the end
 of a list */
 /*
int	inputfile_to_list(t_parser *parser, char *filename)
{
	int		fd;
	char	*line;
	t_cub	*node;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (handle_error(ERR_FD), 1);

	line = get_next_line(fd);
	if (line == NULL)
		return (handle_error(ERR_FILE), 1);
	while (line != NULL)
	{
		if (line[0] == '\0')//si la linea esta vacia, salta a la siguiente linea
		{
			free(line);//no estoy seguro
			line = get_next_line(fd);
			continue;
		}
		node = lst_newnode(line);//this malloc (p_malloc) is already protectec.
		lstadd_back(&parser->cub, node);
		free(line);//no estoy seguro si he de liberarla ????
		line = get_next_line(fd);
	}
	close(fd);
	print_cub_list(parser->cub);//TEMPORAL
	return (0);
}
*/

int	inputfile_to_list(t_parser *parser, char *filename)
{
	int		fd;
	char	*line;
	t_cub	*node;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (handle_error(ERR_FD), 1);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[0] == '\0')//si la linea esta vacia, salta a la siguiente linea
		{
			free(line);//no estoy seguro
			continue;
		}
		node = lst_newnode(line);//this malloc (p_malloc) is already protectec.
		if (node == NULL)
		{
			free(line);
//			free (toda la lista)
			close(fd);
			return (handle_error(ERR_MEMORY), 1);
		}
		lstadd_back(&parser->cub, node);
		free(line);
	}
	close(fd);
	print_cub_list(parser->cub);//TEMPORAL
	return (0);
}
