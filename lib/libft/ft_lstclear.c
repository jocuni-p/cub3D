/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:38:36 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/06/16 17:24:29 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Elimina y libera el nodo ’lst’ dado y todos los consecutivos de ese nodo,
 * utilizando la función ’del’ y free(3).
Al final, el puntero a la lista debe ser NULL.

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	aux = *lst;
	while (aux != NULL)
	{
		aux = aux->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	*lst = NULL;
}*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	aux = *lst;
	while (aux)
	{
		*lst = aux->next;
		del(aux->content);
		free(aux);
		aux = *lst;
	}
	*lst = NULL;
}
