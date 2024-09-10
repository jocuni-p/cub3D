/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joan <jocuni-p@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:16:25 by joan              #+#    #+#             */
/*   Updated: 2023/12/21 10:43:30 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_u(unsigned int n)
{
	int				j;
	int				count;
	int				c;
	char			str[20];

	j = 0;
	count = 0;
	c = 0;
	if (n == 0)
		str[j++] = '0';
	while (n > 0)
	{
		str[j++] = (n % 10) + '0';
		if (n < 10)
			break ;
		n /= 10;
	}
	count = j;
	while (j--)
	{
		c = put_c(str[j]);
		if (c == -1)
			return (-1);
	}
	return (count);
}
