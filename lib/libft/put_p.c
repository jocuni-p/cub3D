/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:52:32 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/12/21 10:43:00 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_dig(unsigned long n)
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

static char	*utohex(unsigned long n, char *hex)
{
	char	*s;
	int		i;

	i = count_dig(n) -1;
	s = (char *)ft_calloc(i + 2, sizeof(char));
	if (!s)
		return (NULL);
	while (i >= 0 && s)
	{
		s[i] = hex[n % 16];
		n = n / 16;
		i--;
	}
	return (s);
}

int	put_p(void *pnt, char *hex)
{
	int				a;
	char			*s;
	unsigned long	n;

	a = 0;
	n = (unsigned long)pnt;
	s = utohex(n, hex);
	if (!s)
		return (-1);
	if (!pnt)
		s[0] = '0';
	a = put_s("0x");
	if (a != -1)
	{
		a = put_s(s);
		if (a != -1)
		{
			free(s);
			return (a + 2);
		}
	}
	free(s);
	return (-1);
}
