/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:00:20 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/12 12:02:53 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

/*---Returns the last node of a 't_cub' list----*/
t_cub	*lstlast(t_cub *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}