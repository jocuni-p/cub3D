/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:01:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/07/06 11:03:47 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*"atoi" proviene de "ASCII to integer"
 * The atoi() function converts the initial portion of the string pointed to
     by str to int representation.
	 La función atoi recibe como argumento una cadena de caracteres y devuelve
	 el valor numérico correspondiente. Funciona leyendo los caracteres de la
	 cadena hasta encontrar el primer dígito (se ignoran los caracteres
	 comprendidos en isspace y se maneja el signo), luego interpreta todos los
	 caracteres siguientes como dígitos numéricos hasta que se encuentra un
	 carácter no numérico. Todos los caracteres no numéricos después del primer
	 dígito se ignoran.
*/
//#include<stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	flag;

	i = 0;
	nbr = 0;
	flag = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		flag++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	if (flag == 1)
		nbr = -nbr;
	return (nbr);
}
/*
int	main(void)
{
	char	str[] = "    	-24las 24horas"; 

	printf("input >%s<\n", str);
	printf("output >%d<\n", ft_atoi(str));
	return (0);
}*/
