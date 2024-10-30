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

/*----Copies every line from filename into a list----*/
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
