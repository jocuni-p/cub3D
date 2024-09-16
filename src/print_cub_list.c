/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cub_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:47:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/16 16:55:17 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*----Prints a t_cub list----*/
void	print_cub_list(t_cub *lst)
{
	printf("\n");
	while (lst)
	{
		printf("%s\n", lst->str);
		lst = lst->next;
	}
	printf("\n");
}