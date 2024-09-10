/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:36:04 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/06/08 10:08:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Reserva, utilizando malloc, un array de strings resultante de separar la
 * string 's' en substrings utilizando el caracter 'c' como delimitador. El
 * array de strings se cierra con un puntero NULL.*/

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
#include "libft.h"

static int	ft_counter(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (!s || *s == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static char	**ft_free(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

static char	**process(const char *s, char c, char **arr_str)
{
	int	i;
	int	num;
	int	start;

	i = -1;
	num = 0;
	while (num < ft_counter(s, c) && i++ >= -1)
	{
		if (s[i] != c && s[i])
		{
			start = i;
			num++;
			while (s[i] != c && s[i] != '\0')
				i++;
			arr_str[num - 1] = ft_substr(s, (unsigned int)start, i - start);
			if (!arr_str[num - 1])
				return (ft_free(arr_str, num - 2));
		}
	}
	return (arr_str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_str;

	if (!s)
		return (NULL);
	arr_str = (char **)ft_calloc((ft_counter(s, c) + 1), sizeof(char *));
	if (!arr_str)
		return (NULL);
	arr_str = process(s, c, arr_str);
	return (arr_str);
}
/*
int	main(void)
{
	char	s[] = "       sssss             q      ";
	char	c = ' ';
	char	**split;
	int		i = 0;

	split = ft_split(s, c);
	printf("split=%p\n", *split);
	while (split[i])
	{
		printf("%i   >%s<\n", i, split[i]);
		i++;
	}
	ft_free(split, i);
	return (0);
}*/
