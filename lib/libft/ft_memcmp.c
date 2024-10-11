/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:56:52 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/05/31 11:36:14 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*The memcmp() function compares byte string s1 against byte string s2.
     Both strings are assumed to be n bytes long.
	 Returns zero if the two strings are identical, oth-
     erwise returns the difference between the first two differing bytes
     (treated as unsigned char values, so that `\200' is greater than `\0',
     for example).  Zero-length strings are always identical.*/

//#include<stdio.h>
//#include<string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *) s2;
	while (n > 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
		n--;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "\0los ";
	char	s2[] = "";
	size_t	n = 2;

	printf("ft_memcmp >%i<\n", ft_memcmp(s1, s2, n));
	printf("   memcmp >%i<\n", memcmp(s1, s2, n));
	return (0);
}*/
