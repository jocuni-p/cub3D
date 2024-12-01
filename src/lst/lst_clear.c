/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:07:50 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/01 23:45:47 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Frees all nodes in a linked list. Iterates through the list, freeing the
 * content of each node (if not NULL) and the node itself. Sets the list
 * pointer to NULL after all nodes are cleared. Ensures proper cleanup of
 * dynamically allocated memory.
 */
void	lst_clear(t_cub **lst)
{
	t_cub	*aux;

	aux = NULL;
	while (*lst)
	{
		aux = *lst;
		*lst = (*lst)->next;
		if (aux->str != NULL)
		{
			free(aux->str);
			aux->str = NULL;
		}
		free(aux);
	}
	*lst = NULL;
}
