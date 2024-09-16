/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:00:47 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/16 15:21:13 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//>>>>>>>>>>>>>>>>PENDING TO WRITE - DRAFT COPY<<<<<<<<<<<<<<<<<<<<<<
/*------Frees all t_parser struct memory-----*/
void	parser_free(t_parser **parser)
{
	if (parser != NULL)
		tok_free(tok);
}

void	tok_free(t_tok **lst)
{
	t_tok	*aux;

	aux = (*lst);
	if (lst == NULL || (*lst) == NULL)
		return ;
	while (aux != NULL)
	{
		if (aux->str != NULL)
		{
			free(aux->str);
			aux->str = NULL;
		}
		aux->type = NULL_TYPE;
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}
