/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_nl_to_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:37:15 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/01 15:39:01 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "   "
>>>>>>>>>>>>OJO. PROVAR ANTES DE PONER EN LIBFT>>>>>>>>>>>>>>>>>>>
//Elimina el caracter '\n' en todas las lineas de una lista
void	rem_nl_to_lst(t_parser *parser)
{
	t_cub	*tmp;
	tmp = parser->aux;
	while (tmp)
	{
		remove_nl(tmp->str);
		tmp = tmp->next;
	}
}