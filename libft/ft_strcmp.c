/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:51:50 by castorga          #+#    #+#             */
/*   Updated: 2024/05/29 12:30:04 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strcmp() function lexicographically compare the null-terminated strings
 s1 and s2.
RETURN VALUES
The strcmp() function return an integer greater than, equal to, or less than 0,
 according as the string s1 is greater than, equal to, or less than the string
  s2.  The comparison is done using unsigned characters, so that 
`\200' is greater than `\0'. */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (2);
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	if (str1[i] > str2[i])
		return (1);
	else if (str1[i] == str2[i])
		return (0);
	else
		return (-1);
}
/*
int	main(void)
{
	printf("%d\n", ft_strcmp("hola", "hola"));
	printf("%d\n", ft_strcmp("hola", "hombre"));
	printf("%d\n", ft_strcmp("hola", " "));
	printf("----------\n");
	printf("%d\n", strcmp("hola", "hola"));
	printf("%d\n", strcmp("hola", "hombre"));
	printf("%d\n", strcmp("hola", " "));
}
*/