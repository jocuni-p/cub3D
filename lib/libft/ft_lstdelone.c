/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:54:18 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/12 14:52:35 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Libera/borra la memoria del content de un nodo utilizando una funcion
externa, ademas de liberar el nodo. No devuelve nada.
OJO: No tiene en cuenta si el nodo forma parte de una lista, porque en ese 
caso, quedaria rota.*/
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
