/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:17:06 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/10 11:40:19 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<string.h>
//#include<stdio.h>
//#include<stdlib.h>
#include "libft.h"
/*
char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dup = (char *) malloc(len * sizeof(char));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, len);
	return (dup);
}*/
/*ALTERNATIVA*/
/*The strdup() function allocates sufficient memory for a copy of the 
string s1, does the copy, and returns a pointer to it.*/

char	*ft_strdup(char *s1)
{
	char	*dup;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	dup = malloc(len * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, len);
	return (dup);
}
/*
int	main(void)
{
	char	s1[] = "42Barcelona";
	char	*temp1 = ft_strdup(s1);
	char	*temp2 = strdup(s1);

	printf("s1        >%p<  >%s<\n", s1, s1);
	printf("ft_strdup >%p<  >%s<\n", temp1, temp1);
	printf("   strdup >%p<  >%s<\n", temp2, temp2);
//	free(temp1);
//	free(temp2);
	return (0);
}*/
