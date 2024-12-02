/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:51:42 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/01 23:47:44 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Adds a new node to the end of a linked list of type `t_cub`. If the list
 * is not empty, finds the last node using `lstlast` and sets its `next`
 * pointer to the new node. If the list is empty, sets the new node as the
 * first node in the list.
 */
void	lstadd_back(t_cub **lst, t_cub *new)
{
	t_cub	*aux;

	if (*lst)
	{
		aux = lstlast(*lst);
		aux->next = new;
	}
	else
		*lst = new;
}
