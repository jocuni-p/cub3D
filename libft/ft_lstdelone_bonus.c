/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:54:18 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/06/16 14:37:54 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Libera/borra la memoria del contenido de un nodo utilizando una funcion
 * externa, ademas de liberar el nodo. No devuelve nada*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
