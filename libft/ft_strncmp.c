/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:37:02 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 12:31:54 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strcmp() and strncmp() functions lexicographically compare the 
null-terminated strings s1 and s2.
The strncmp() function compares not more than n characters.  Because strncmp() 
is designed for comparing strings rather than binary data, characters that 
appear after a `\0' character are not compared.
RETURN VALUES
The strcmp() and strncmp() functions return an integer greater than, equal to, 
or less than 0, according as the string s1 is greater than, equal to, or less 
than the string s2.  The comparison is done using unsigned characters, so that 
`\200' is greater than `\0'. */

#include "libft.h"
//#include<stdio.h>
//#include<string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	printf("ft_strncmp >%i<\n", ft_strncmp("\200", "\0", 1));
	printf("   strncmp >%i<\n", strncmp("\200", "\0", 1));
	printf("ft_strncmp >%i<\n", ft_strncmp("Hola mid", "Holjfjej", 4));
    printf("   strncmp >%i<\n", strncmp("Hola mid", "Holjfjej", 4));
	return (0);
}*/
