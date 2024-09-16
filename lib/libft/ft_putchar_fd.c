/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joan <jocuni-p@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:48:03 by joan              #+#    #+#             */
/*   Updated: 2023/06/11 00:39:30 by joan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Esta funcion utiliza la función 'write' de la biblioteca <unistd.h> para
escribir el carácter 'c' en el descriptor de archivo especificado por 'fd'.
La función 'write' toma como argumentos el descriptor de archivo (fd), un
puntero al carácter (&c) y la longitud del buffer (en este caso, 1 porque solo
se está escribiendo un carácter).
Notese que le pasamos el char c a traves de su direccion, no como un
caracter, sino como un puntero.*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
