/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr2d_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:49:10 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/26 18:26:38 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*-------JUST TO TEST THE PROGRAM CONSTRUCTION-REMOVE BEFORE EVALUATION-------*/
void	arr2d_print(char **arr2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (arr2d == NULL)
	{
		printf("El array es NULL\n");
		return ;
	}
	while (arr2d[0][j++] != '\0')
		write(1, "-", 1);
	write(1, "\n", 1);
	while (arr2d[i] != NULL)
	{
		printf("%s", arr2d[i]);
		printf("|\n");
		i++;
	}
	j = 0;
	while (arr2d[0][j++] != '\0')
		write(1, "-", 1);
	write(1, "\n", 1);
	printf("\n");
}
