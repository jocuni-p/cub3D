/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:43:50 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/05/29 12:21:08 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdlib.h>
//#include<stdio.h>
//#include<string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	size_t	i;
	char	*join;

	i = 0;
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	join = (char *) malloc((len_1 + len_2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		join[len_1 + i] = s2[i];
		i++;
	}
	join[len_1 + i] = '\0';
	return (join);
}
/*
int	main(int ac, char **av)
{
	char	*result = NULL;

	if (ac != 0)
	{
		printf("s1 >%s<\ns2 >%s<\n", av[1], av[2]);
		result = ft_strjoin(av[1], av[2]);
		printf("join >%s<\n%p\n", result, result);
	}
	free(result);
	return (0);
}*/
