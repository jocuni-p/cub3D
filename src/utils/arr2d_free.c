/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr2d_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:30:58 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/08 16:53:06 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Frees all elements  of a char **arr, passed as reference, and the main
 pointer is freed and pointed to NULL.*/
void	arr2d_free(char ***arr)
{
	size_t	i;

	i = 0;
	if (*arr == NULL)
		return ;
	while ((*arr)[i] != NULL)
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
	return ;
}
/*del meu minishell*/
/*Frees all elements of an **arr2d included the main pointer as well.*/
/*
void	free_arr2d(char **array_strings)
{
	size_t	i;

	if (array_strings == NULL)
		return ;
	i = 0;
	if (array_strings != NULL)
	{
		while (array_strings[i] != NULL)
		{
			free(array_strings[i]);
			array_strings[i] = NULL;
			i++;
		}
		free(array_strings);
		array_strings = NULL;
	}
}
*/