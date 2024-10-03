/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:16:52 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/03 14:24:52 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*----Prints from the pointer to map----*/
void	print_map_list(t_cub *lst)
{
	printf  ("===============MAP PARSING 1============\n");
	while (lst)
	{
		printf("%s\n", lst->str);
		lst = lst->next;
	}
	printf("\n");
}