/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr2d_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:49:10 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/22 18:46:25 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*-------JUST TO TEST THE PROGRAM CONSTRUCTION-REMOVE BEFORE EVALUATION-------*/
void	arr2d_print(char **arr2d)
{
	int	i;

	i = 0;
	if (arr2d == NULL)
	{
		printf("El array es NULL\n");
		return ;
	}
	while (arr2d[i] != NULL)
	{
		printf("%s\n", arr2d[i]);
		i++;
	}
	printf("---\n");
}