/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cub_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:47:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/27 12:18:12 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*----Prints a t_cub list----*/
void	print_cub_list(t_cub *lst)
{
	printf  ("===============LIST ELEMENTS======\n");
	while (lst)
	{
		printf("%s", lst->str);
		lst = lst->next;
	}
	printf("\n");
}