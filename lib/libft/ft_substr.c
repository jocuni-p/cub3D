/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:24:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/06/01 11:03:41 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Reserva, con malloc, y devuelve una substring de la string ’s’.
La substring empieza desde el índice ’start’ y tiene una longitud máxima len*/

//#include<stdlib.h>
//#include<stdio.h>
//#include<string.h>
#include "libft.h"

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
}
/*
int	main(void)
{
//		return (NULL);
//	char			*s = NULL;
//	char			*s = "";
	unsigned int	start = 0;
//	unsigned int	start = 10;
//	unsigned int	start = 100;
//	size_t			len = 0;
	size_t			len = 2;
//	size_t			len = 10;
//	size_t			len = 100;
	char	s[] = "La vuelta de, ciclismo 43 es para pro-fesionales";
	char	*result = ft_substr(s, start, len);

	printf("ft_substr >%p<\n", result);
	free(result);
	return (0);
//if (1): si no existe s, retorna NULL
//if (2): si start es mayor que len, retorna un puntero a reserva mem vacio
//if (3): si longitud de s, a partir de start, es menor que len, reserva mem + 1
//if (4): si falla malloc con la reserva de mem, retorna NULL
}*/
