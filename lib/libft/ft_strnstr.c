/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:04:02 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/05/31 13:12:12 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	 The strnstr() function locates the first occurrence of the null-termi-
     nated string needle in the null-terminated string haystack, where not
	 more than len char-
     acters are searched.  Characters that appear after a `\0' character are
     not searched.
Return: If needle is an empty string, haystack is returned; if needle occurs
     nowhere in haystack, NULL is returned; otherwise a pointer to the first
     character of the first occurrence of needle is returned.*/

//#include<stdio.h>
//#include<string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = (char *)haystack;
	if (needle[0] == '\0')
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i] && str[i] == needle[j] && needle[j] && i < len)
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return (&str[i - j]);
		i = i + 1 - j;
	}
	return (NULL);
}
/*
int	main(void)
{
    char	haystack[] = "abbabbd";
    char	needle[] = "bbd";
    size_t	len = 3;
	printf("ft_strnstr>%s<\n\n", ft_strnstr(haystack, needle, len));
	printf("strnstr>%s<%zu\n", strnstr(haystack, needle, len), len);
	return (0);
}*/
