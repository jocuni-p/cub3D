/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:07:50 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 15:49:14 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* In a list passed as parameter, frees every node, frees his content and 
finally points the list to NULL*/
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
