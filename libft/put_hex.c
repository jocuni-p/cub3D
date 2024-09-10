/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:07:54 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/12/21 10:42:20 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_dig(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

static char	*utohex(unsigned int n, char *hex)
{
	char	*str;
	int		i;

	i = count_dig(n) -1;
	str = (char *)ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (NULL);
	while (i >= 0 && str)
	{
		str[i] = hex[n % 16];
		n = n / 16;
		i--;
	}
	return (str);
}

int	put_hex(unsigned int n, char *hex)
{
	int		a;
	char	*s;

	a = 0;
	s = utohex(n, hex);
	if (!s)
	{
		free(s);
		return (-1);
	}
	a = put_s(s);
	if (a == -1)
	{
		free(s);
		return (-1);
	}
	free(s);
	return (a);
}
