/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:23:48 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/07/06 12:28:52 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*function writes len bytes of value c (converted to an
     unsigned char) to the string b. Returns its first argument.*/

//#include<string.h>
//#include<stdio.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*a;

	i = 0;
	a = b;
	c = (unsigned char) c;
	while (len > 0)
	{
		a[i] = c;
		i++;
		len--;
	}
	return (a);
}
/*
int	main(void)
{
	char	b[6];
	char	a[6];
	int		c;
	size_t	len;

	c = 52;
	len = 4;
	printf("ft_memset>%s<\n", (unsigned char *)ft_memset(a, 52, 4));
	printf("   memset>%s<\n", (unsigned char *)memset(b, c, len));
	return (0);
}*/
