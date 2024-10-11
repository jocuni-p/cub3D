/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:01:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/06/09 14:16:25 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>

// Funcion auxiliar para probar la funcion ft_strmapi
char uppercase(unsigned int index, char c)
{
    if (index % 2 == 0 && (c >= 97 && c <= 122))
        return (c - 32); // Convierte a mayuscula si el indice es par
    else
        return (c); // Mantiene el caracter original si el indice es impar
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*c;
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(s);
	c = (char *)malloc((len + 1) * sizeof(char));
	if (!c)
		return (NULL);
	i = 0;
	while (s[i])
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
/*
int main(void)
{
    char    s[12] = "su lfamina";
    char    *result = ft_strmapi(s, uppercase);
    printf("*s       >%s<\n", s);
    printf("*result  >%s<\n", result);
    free(result);
    return (0);
}*/
