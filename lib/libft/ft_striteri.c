/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:20:19 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/06/10 19:59:56 by joan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*A cada carácter de la string ’s’, aplica la función ’f’ dando como
parámetros el índice de cada carácter dentro de ’s’ y la dirección del propio
carácter, que podrá modificarse si es necesario.
No retorna nada.
En cada iteracion lo que cambia es la direccion de memoria a la que se apunta.
En cada iteracion la funcion se ejecuta en una direccion diferente que va
 moviendose segun el indice al que mire. Es importante notar que se iteran 
 direcciones de memoria y no indices en un array.*/
/*
#include<stdio.h>

// Funcion auxiliar para probar la funcion ft_striteri
void	uppercase(unsigned int index, char *c)
{
		c[index] = c[index] - 32;
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int main(void)
{
    char    s[7] = "abcdef";

	printf("*s antes de striteri  >%s<\n", s);
	ft_striteri(s, uppercase);
	printf("*s despues striteri   >%s<\n", s);
	s[6] = '\0';
	printf("cerramos el array con un nul   >%s<\n", s);
    return (0);
}*/
