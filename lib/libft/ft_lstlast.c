/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:15:03 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/06/15 16:20:48 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Devuelve el ultimo nodo de una lista
//#include<stdio.h>
#include "libft.h"
/*
typedef struct  s_list
{
        int				content;
        struct s_list   *next;
}                       t_list;*/

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int main(void)
{
    t_list  node1, node2, node3, node4;
    t_list *head;
	t_list	*view;;

    head = &node1;
    node1.content = 1;
    node1.next = &node2;
    node2.content = 2;
    node2.next = &node3;
    node3.content = 3;
    node3.next = &node4;
    node4.content = 4;
    node4.next = NULL;
//	printf("nodo2 contiene >%d<\n", node2.content);
	view = ft_lstlast(head);
    printf("El ultimo nodo contiene %d \n", view->content);
    return (0);
}*/
