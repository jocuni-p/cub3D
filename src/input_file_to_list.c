/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file_to_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:01:35 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/11 18:53:55 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

/*----Puts in a list every line from the input filename----*/
t_list	**input_file_to_list(t_parser *parser, char *filename)
{
	int		fd;
	char	*line;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (?????);

	line = get_next_line(fd);
	while (line != NULL)
	{
		newnode: 
			mallocar su length
			asignarle un valor con ft_strlcpy
			next->NULL
		listaddback(listname, newnode)

		line = get_next_line(fd);
	}
	
	close(fd);
	
}