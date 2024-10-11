/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:23:39 by joan              #+#    #+#             */
/*   Updated: 2024/09/16 16:37:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La funcion get_next_line lee, una linea a cada llamada, hasta llegar al
final del archivo al que apunta el "file descriptor". La linea devuelta 
termina con el caracter '\n' excepto si se llego al final y este no termina 
en '\n'. Si no hay nada mas que leer o ocurrio un error devuelve "NULL".
Toma como argumento un fd (file descriptor).*/

void	my_free(char **str)
{
	if (*str != NULL && str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

static char	*fd_reader(int fd, char *stack)
{
	char	*buff;
	int		bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
	{
		my_free(&stack);
		return (NULL);
	}
	buff[0] = '\0';
	bytes = 1;
	while (bytes > 0 && !(strchr_len(stack, '\n')))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1 || (bytes == 0 && str_len(stack) == 0))
			my_free(&stack);
		if (bytes > 0)
		{
			buff[bytes] = '\0';
			stack = str_join(stack, buff);
		}
	}
	my_free(&buff);
	return (stack);
}

static char	*str_extract(char *stack)
{
	char	*line;
	size_t	len;

	len = strchr_len(stack, '\n');
	if (len > 0)
	{
		line = sub_str(stack, 0, len);
		return (line);
	}
	line = str_join(NULL, stack);
	return (line);
}

static char	*clean_stack(char *stack)
{
	char	*new_stack;
	size_t	start;

	start = strchr_len(stack, '\n');
	if (start > 0)
	{
		new_stack = sub_str(stack, start, str_len(stack));
		my_free(&stack);
		stack = NULL;
		if (str_len(new_stack) == 0)
			my_free(&new_stack);
		return (new_stack);
	}
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stack = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		my_free(&stack);
		return (NULL);
	}
	stack = fd_reader(fd, stack);
	if (stack == NULL)
		return (NULL);
	line = str_extract(stack);
	if (!strchr_len(line, '\n'))
	{
		my_free(&stack);
		return (line);
	}
	stack = clean_stack(stack);
	return (line);
}
