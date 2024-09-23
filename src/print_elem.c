/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:20:55 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/23 11:27:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_elem(t_parser *parser)
{
	printf("no: %s\n", parser->elem.no);
	printf("so: %s\n", parser->elem.so);
	printf("we: %s\n", parser->elem.we);
	printf("ea: %s\n", parser->elem.ea);
	printf("c: %s\n", parser->elem.c);
	printf("f: %s\n", parser->elem.f);	
}