/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:45:07 by joan              #+#    #+#             */
/*   Updated: 2024/05/30 12:30:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La variable miembro ’content’ se inicializa con el contenido del parámetro
 ’content’. La variable ’next’, con NULL.
 Cuando dejamos de usarlo hay que liberar la memeoria alojada por el  malloc.
 Retorna el nuevo nodo.*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
