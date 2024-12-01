/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr2d_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:49:10 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 19:46:58 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*-------Prints the content of an char **------*/
void	arr2d_print(char **arr2d)
{
	int	i;
	int	j;

	if (arr2d == NULL)
	{
		printf("El array es NULL\n");
		return ;
	}
	i = 0;
	j = 0;
	printf("\n");
	while (arr2d[0][j++] != '\0')
		printf("-");
	printf("\n");
	while (arr2d[i] != NULL)
	{
		printf("%s|\n", arr2d[i]);
		i++;
	}
	j = 0;
	while (arr2d[0][j++] != '\0')
		printf("-");
	printf("\n\n");
}
