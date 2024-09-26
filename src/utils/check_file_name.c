/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:12:09 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/18 12:00:53 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_file_name(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i] && str[i] != '.')
	{
		if ((str[i] >= 97 && str[i] <= 122) \
		|| (str[i] >= 48 && str[i] <= 57) || str[i] == '_' || str[i] == '/') 
			i++;
		else
			return (1);
	}
	return (0);
}