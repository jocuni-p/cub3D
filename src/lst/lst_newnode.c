/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_newnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:42:04 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/01 23:46:37 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Creates a new linked list node of type `t_cub`. Allocates memory for the
 * node and initializes its `str` field with a copy of the provided string
 * using `ft_strdup`. Sets the `next` pointer to NULL. If memory allocation
 * fails for the node or the string, frees allocated memory and returns NULL.
 */
t_cub	*lst_newnode(char *str)
{
	t_cub	*new_node;

	new_node = (t_cub *)malloc(sizeof(t_cub));
	if (!new_node)
		return (NULL);
	new_node->str = ft_strdup(str);
	if (!new_node->str)
	{
		free (new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}
