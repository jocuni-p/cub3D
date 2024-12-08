/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr2d_element_cnt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:49:27 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/02 01:20:31 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

/**
 * Counts the number of elements in a 2D character array (`char **arr`).
 * Returns the count of non-NULL elements. Returns 0 if the array is NULL.
 */
int	arr2d_element_cnt(char **arr)
{
	int	cnt;

	cnt = 0;
	if (arr != NULL)
	{
		while (arr[cnt] != NULL)
			cnt++;
		return (cnt);
	}
	return (0);
}
