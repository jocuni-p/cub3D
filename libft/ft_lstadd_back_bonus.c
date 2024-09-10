/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:38:01 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/12/16 10:22:42 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Afageix el node 'new' al final de la llista 'lst' y no retorna res.
 * 'lst' es el punter al primer node de la llista. */

//#include<stdio.h>
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (*lst)
	{
		aux = ft_lstlast(*lst);
		aux->next = new;
	}
	else
		*lst = new;
}
/*
int	main(void)
{
	t_list	**head;//puc crear el **head o treballar amb un *tmp per no perdre
				   //la primera adresa de la llista
	t_list	*node1;
//	t_list	*tmp;
	t_list	*node2;
	t_list	*node3;
	t_list	*nodenew;

	node1 = (t_list *)malloc(sizeof(t_list));
	if (!node1) //En el main per provar la funcio no cal asegurar el malloc
		return (0);
	node1->content = ft_strdup("soynode1");
	head = &node1;//el '&' es per que el 'head' es doble punter i el node1
				  //punter sencill 
//	tmp = node1;

	node2 = (t_list *)malloc(sizeof(t_list));
	if (!node2)
		return (0);
	node2->content = ft_strdup("soynode2");
	node1->next = node2;
//	tmp->next = node2;
//	tmp = tmp->next;

	node3 = (t_list *)malloc(sizeof(t_list));
	if (!node2)
		return (0);
	node3->content = ft_strdup("soynode3");
	node3->next = NULL;
	node2->next = node3;
//	tmp->next = node3;

	nodenew = (t_list *)malloc(sizeof(t_list));
	if (!nodenew)
		return (0);
	nodenew->content = ft_strdup("soynew");
	nodenew->next = NULL;

	printf("Antes lstadd_back, ult nodo >%s<\n", ft_lstlast(*head)->content);
	ft_lstadd_back(&node1, nodenew);
	printf("after lstadd_back, ult nodo >%s<\n", ft_lstlast(*head)->content);
	free(node1);
	free(node2);
	free(node3);
	free(nodenew);
	return (0);
}*/
