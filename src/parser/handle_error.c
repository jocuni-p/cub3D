/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:27:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/20 21:12:54 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*------Prints an error message and frees the parser struct-----*/
//void	handle_error(char *str, t_parser *parser)
void	handle_error(char *str)
{
	write(2, str, ft_strlen(str));//prints the error message
//	if (parser != NULL)
		return ;//eliminar aixo quan tingui el parser_free
//		parser_free(parser);//PENDING TO WRITE, frees the 'parser' struct
}
