/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:49:52 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/13 15:55:16 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Elimina de "s1" todos los caracteres "set" que encuentra al inicio y al final
del string hasta que topa con algun caracter diferente y se para. Retorna un 
puntero al nuevo string mallocado resultante o NULL si falla la reserva de 
memoria.*/

//#include<stdlib.h>
//#include<stdio.h>
#include "libft.h"
/*
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (unsigned char) c;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

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
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (!dst && !src)
		return (0);
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	prev;

	prev = 0;
	s1_len = ft_strlen(s1);
	while (s1[prev] && ft_strchr(set, s1[prev]))
		prev++;
	while (s1_len >= 1 && ft_strchr(set, s1[s1_len - 1]))
	{
		s1_len--;
	}
	return (ft_substr(s1, prev, (s1_len - prev)));
}
/*
int	main(void)
{
	char	s1[] = "aaaLes grands monstreseaa aa";
	char	set[] = "a";
	char	*final;

	printf("mem dir s1  >%p<\n", s1);
	printf("mem dir set >%p<\n", set);
	final = ft_strtrim(s1, set);
	printf("ft_strtrim  >%s<\n", final);
	printf("mem dir     >%p<\n", final);
	free(final);
	return (0);
}*/
