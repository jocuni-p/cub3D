/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:47:29 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/06/27 16:53:44 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Itera la lista ’lst’ y aplica la función ’f’ al contenido de cada nodo.
 * Crea una lista resultante de la aplicación correcta y sucesiva de la
 * función ’f’ sobre cada nodo. La función ’del’ se utiliza para eliminar el
 * contenido de un nodo, si hace falta.
 * Retorna: la nueva lista o NULL si falla la lista. */

#include "libft.h"
//#include<stdio.h>
/*
t_list  *ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}

t_list  *ft_lstnew(void *content)
{
    t_list  *node1;

    node1 = (t_list *)malloc(sizeof(t_list));
    if (!node1)
        return (NULL);
    node1->content = content;
    node1->next = NULL;
    return (node1);
}

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    while (lst)
    {
        f(lst->content);
        lst = lst->next;
    }
}

void    ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!*lst)
        *lst = new;
    else
    {
        new->next = *lst;
        *lst = new;
    }
}

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *aux;

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

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *aux;

    if (*lst)
    {
        aux = ft_lstlast(*lst);
        aux->next = new;
    }
    else
            *lst = new;
}

void	del(void *a)
{
	a = 0;
}

void *f(void *x)
{
  int *a = (int *)x;
  *a = *a + 1;
  return (x);
}

void	g(void *x)
{
		int	*a = (int *)x;
		printf("%d\n", *a);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	t_list	*tmp;

	if (!lst)
		return (0);
	newlst = 0;
	while (lst)
	{
		tmp = f(lst->content);
		newnode = ft_lstnew(tmp);
		if (!newnode)
		{
			free(tmp);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}
/*
int	main(void)
{
	int	a = 5;
	int	b = 11;
	int	c = 300;

	t_list	*nodo1;
	t_list	*nodo2;
	t_list	*nodo3;
	t_list	*lst;
	t_list	*newlst;

//	int	*content_a = &a;
//	int	*content_b = &b;
//	int	*content_c = &c;

	nodo1 = ft_lstnew(&a);
	nodo2 = ft_lstnew(&b);
	nodo3 = ft_lstnew(&c);

	ft_lstadd_front(&lst, nodo1);
	ft_lstadd_back(&lst, nodo2);
	ft_lstadd_back(&lst, nodo3);
	ft_lstiter(lst, g);
	printf("\n");
	newlst = ft_lstmap(lst, f, del);
	ft_lstiter(newlst, g);
	free(nodo1);
	free(nodo2);
	free(nodo3);
//	free(lst); no se libera porque no fue alojado en ningun momento
	free(newlst);
}*/
