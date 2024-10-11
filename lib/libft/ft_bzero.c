/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:18:08 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/05/31 10:09:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*function writes n zeroed bytes to the string s.  If n is
     zero, bzero() does nothing.*/

//#include<strings.h>
//#include<stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*a;
	int		i;

	i = 0;
	a = s;
	while (n > 0)
	{
		a[i] = 0;
		i++;
		n--;
	}
}
/*
int	main(void)
{
	char	s[] = "hola mundo";
	char	f[] = "hola mundo";
	size_t	n;

	n = 8;
	printf("  antes *s contiene>%s<\n", s);
	ft_bzero(s, n);
	printf("despues *s contiene>%s<\n", s);
	printf("   bzero>%s<\n", bzero(f, n));
	return (0);
}*/
