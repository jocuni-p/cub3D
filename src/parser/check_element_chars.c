/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_chars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:09:10 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/22 18:40:19 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Returns 1 if it is found on *str any invalid character, otherwise returns 0*/
int	check_element_chars(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '/' \
			|| str[i] == '.' || str[i] == ' ' || str[i] == ',')
			i++;
		else
			return (1);
	}
	return (0);
}