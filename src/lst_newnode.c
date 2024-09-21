/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_newnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:42:04 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/21 22:59:44 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*----Returns a malloced 't_cub' node initialized with the argument----*/
t_cub	*lst_newnode(char *str)
{
	t_cub	*new_node;

	new_node = (t_cub *)p_malloc(sizeof(t_cub));
	new_node->str = ft_strdup(str);
	new_node->next = NULL;
	return (new_node);
}
