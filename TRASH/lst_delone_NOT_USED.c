/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:45:15 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/17 12:14:05 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"


//>>>>>>>>>>>>>>>>>>>ATENTION, IN PROGRESS<<<<<<<<<<<<<<<<<< 
/* What is more useful, to pass the node or its content as argument to
 the function??? */
 
/*----Removes a node from a list----*/
void	lst_delone(t_cub **lst, char *content_to_del, void (*del)(void*))
{
	t_cub	*current;
	t_cub	*prev;

	current = *lst;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->str, content_to_del) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*lst = current->next;
			del(current->str);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}