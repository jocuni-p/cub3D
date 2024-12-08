/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:08:38 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/01 23:47:04 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

/**
 * Counts the number of nodes in a linked list of type `t_cub`. Iterates
 * through the list, incrementing a counter for each node. Returns the total
 * count of nodes. If the list is empty, returns 0.
 */
int	lst_size(t_cub *lst)
{
	int	size;

	size = 0;
	if (lst != 0)
	{
		while (lst != 0)
		{
			lst = lst->next;
			size++;
		}
	}
	return (size);
}
