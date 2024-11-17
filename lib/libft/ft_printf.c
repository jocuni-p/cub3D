/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:49:21 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/17 19:10:54 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(char const *fmt, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		len_tmp;

	i = 0;
	len = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		len_tmp = 0;
		if (fmt[i] == '%')
		{
			len_tmp = sel_fmt(fmt, i, args);
			i++;//OJO aqui
		}
		else
			len_tmp = put_c(fmt[i]);
		if (len_tmp < 0)
		{
			va_end(args);
			return (-1);
		}
		len += len_tmp;
		i++;
	}
	va_end(args);
	return (len);
}
