/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joan <jocuni-p@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:16:19 by joan              #+#    #+#             */
/*   Updated: 2023/06/11 00:42:11 by joan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La función 'write' toma como argumentos el descriptor de archivo (fd), un
puntero y la longitud del buffer.
La función write espera un puntero a una cadena de caracteres cuando se
utiliza el formato write(fd, buffer, length). Al pasar "\n" como argumento, se
está pasando un puntero a un string que contiene el carácter de salto de línea.
Por eso no le pasamos el argumento como un caracter '\n'. */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
