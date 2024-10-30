/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:47:05 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/19 14:08:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*>>>>>>>>>>>>>>>>>>NOT USED AT THE MOMENT<<<<<<<<<<<<<<<<<*/

/*---Returns 1 if a '\t' is found in str, otherwise returns 0----*/
int	check_tab(char *str)
{
	if(ft_strchr(str, '\t'))
		return (1);
	return (0);
}