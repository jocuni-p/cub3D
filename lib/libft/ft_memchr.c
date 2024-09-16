/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:39:48 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/07/06 12:03:06 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*The memchr() function locates the first occurrence of character c (converted
 * to an unsigned char) in the first n bytes of the string pointed by s.
	 The function returns a pointer to the byte located, or NULL if
     no such byte exists within n bytes.*/

//#include<stdio.h>
//#include<string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*f;
	size_t			i;

	i = 0;
	f = (unsigned char *) s;
	c = (unsigned char) c;
	while (n > i)
	{
		if (f[i] == c)
			return (&f[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s[] = "Las 3x5 cars del *Un@~0  ";
	char	str[] = "Las 3x5 cars del *Un@~0  ";
	char	s1[] = "/|\x12\xff\x09\0\x42\042\0\42|\\";
	char	s2[] = "/|\x12\xff\x09\0\x42\042\0\42|\\";
	int		c;
	size_t	n;

	c = 48;
	n = 100;
	printf("*s >%s<\nc = %d\nn = %zu\n", s, c, n);
	printf("ft_memchr >%s<\n", (unsigned char *)ft_memchr(s, c, n));
	printf("   memchr >%s<\n", (unsigned char *)memchr(str, c, n));
	printf("*s1 es >%s<\nc = %d\nn = %zu\n", s1, c, n);
	printf("ft_memchr >%s<\n", (unsigned char *)ft_memchr(s1, '\0', 12));
	printf("   memchr >%s<\n", (unsigned char *)memchr(s2, '\0', 12));
	return (0);
}*/
