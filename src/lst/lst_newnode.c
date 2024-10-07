/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_newnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:42:04 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/07 16:25:49 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*-Returns an allocated 't_cub' node initialized with the provided argument.-*/
t_cub	*lst_newnode(char *str)
{
	t_cub	*new_node;

	new_node = (t_cub *)malloc(sizeof(t_cub));
	if (!new_node)
		return (NULL);
	new_node->str = ft_strdup(str);
	new_node->next = NULL;
	return (new_node);
}
