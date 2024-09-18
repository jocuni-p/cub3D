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
int	inputfile_to_list(t_parser *parser, char *filename)
{
	int		fd;
	char	*line;
	t_cub	*node;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (handle_error(ERR_FD, NULL), 1);

	line = get_next_line(fd);
	if (line == NULL)
		return (handle_error(ERR_FILE, NULL), 1);
		
	while (line != NULL)
	{
		node = lst_newnode(line);//this malloc (p_malloc) is already protectec.
		lstadd_back(&parser->cub, node);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
