/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:26:02 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/06/16 14:42:22 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*adds an element/node at the beginning of a list. No retorna nada.*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
