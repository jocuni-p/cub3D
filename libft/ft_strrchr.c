/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:01:34 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/07/06 12:37:42 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*function locates the last occurrence of c (converted to a
     char) in the string pointed to by s.  The terminating null character is
     considered to be part of the string; therefore if c is `\0', the func-
     tions locate the terminating `\0'.
     The function strrchr() return a pointer to the located
     character, or NULL if the character does not appear in the string.*/

#include "libft.h"
//#include<stdio.h>
//#include<string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	c = (unsigned char) c;
	i = ft_strlen (s);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	if (c == '\0')
		return ((char *)&s['\0']);
	return (NULL);
}
/*
int	main(void)
{
	const char	s[] = "	z5g8HI u*_8^5$3[{-las";
	int			c = 646464 ;

	printf("   strrchr >%s<\n", strrchr(s, c));
	printf("ft_strrchr >%s<\n", ft_strrchr(s, c));
	return (0);
}*/
