/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_creator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:01:35 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/12 12:48:15 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Reads lines from a file and stores them in a linked list. Opens the file
 * in read-only mode. Reads each line using `get_next_line` and creates a
 * new list node for it. Appends nodes to the end of the list. Frees memory
 * for the line buffer after processing. Handles errors for file access,
 * empty files, or memory allocation. Closes the file and sets the list's
 * starting pointer (`cub_ln0`) to the head of the list.
 */
int	lst_creator(t_parser *parser, char *filename)
{
	int		fd;
	char	*line;
	t_cub	*node;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (print_error(ERR_FD), 1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), print_error(ERR_EMPTY_FILE), 1);
	while (line != NULL)
	{
		node = lst_newnode(line);
		if (node == NULL)
		{
			free(line);
			close(fd);
			return (print_error(ERR_MEMORY), 1);
		}
		lstadd_back(&parser->cub, node);
		free(line);
		line = get_next_line(fd);
	}
	parser->cub_ln0 = parser->cub;
	return (close(fd), 0);
}
