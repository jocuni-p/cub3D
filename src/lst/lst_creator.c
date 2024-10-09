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
		return (handle_error(ERR_FD), 1);
	while ((line = get_next_line(fd)) != NULL)
	{
		node = lst_newnode(line);
		if (node == NULL)
		{
			close(fd);
			return (handle_error(ERR_MEMORY), 1);
		}
		lstadd_back(&parser->cub, node);
		free(line);
	}
	return (close(fd), 0);
}
