/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:51:42 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/12 12:03:42 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

/*----Adds a node to the end of a 't_cub' list----*/
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
