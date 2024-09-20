/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr2d_element_cnt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:49:27 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/20 14:57:48 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Returns the num of elements has a 2D_array (char **str)*/
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
