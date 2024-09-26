/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr2d_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:30:58 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/20 15:36:01 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Frees all elements of **arr2d and finally the main pointer as well.*/
void	arr2d_free(char **arr)
{
	size_t	i;

	if (arr == NULL)
		return ;
	i = 0;
	if (arr != NULL)
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
		arr = NULL;
	}
}