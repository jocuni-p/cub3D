/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:14:48 by castorga          #+#    #+#             */
/*   Updated: 2024/05/27 15:15:33 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_dig2(int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		c = 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char	*ft_ltoa(int n)
{
	char	*ltoa;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = count_dig2(n);
	ltoa = (char *)ft_calloc(i + 1, sizeof(char));
	if (!ltoa)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		ltoa[0] = '-';
	}
	while (i > 0)
	{
		ltoa[i - 1] = (n % 10) + 48;
		n = n / 10;
		i--;
		if (i != 0 && ltoa[i - 1] == '-')
			return (ltoa);
	}
	return (ltoa);
}
