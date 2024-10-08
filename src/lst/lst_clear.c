/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:07:50 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/08 15:34:53 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* Elimina y libera cada nodo de una lista y finalmente pone la lista a NULL*/
void lst_clear(t_cub **lst)
{
    t_cub *aux;

    // Mientras la lista no esté vacía
    while (*lst)
    {
        aux = *lst;            // Guardamos el nodo actual
        *lst = (*lst)->next;   // Avanzamos al siguiente nodo

        // Liberamos el string si no es NULL
        if (aux->str != NULL)
        {
            free(aux->str);
            aux->str = NULL;
        }

        // Liberamos el nodo actual
        free(aux);
    }

    *lst = NULL;  // Finalmente, apuntamos la lista a NULL
}
