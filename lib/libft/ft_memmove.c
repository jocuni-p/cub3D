/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:49:28 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/07/06 11:40:46 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*function copies len bytes from string src to string dst.
     The two strings may overlap; the copy is always done in a non-destructive
     manner. Returns the original value of dst.*/

//#include<string.h>
//#include<stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst1;
	const char	*src1;

	dst1 = (char *)dst;
	src1 = (const char *)src;
	if (dst1 > src1)
	{
		while (len--)
			dst1[len] = src1[len];
		return (dst);
	}
	return (ft_memcpy(dst1, src1, len));
}
/*
int	main(void)
{
    char    a[] = "1tie";
    char    b[] = "------";
    char    a1[] = "1tie";
    char    b1[] = "------";
    size_t  len = 5;

    printf("*a >%s< %p\n", a, a);
    printf("*b >%s< %p\n", b, b);
    printf("*a1 >%s< %p\n", a1, a1);
    printf("*b1 >%s< %p\n", b1, b1);
    printf("len = %zu\n", len);
    printf("ft_memmove >%s< %p\n", (char *)ft_memmove(b, a, len),\
	(char *)ft_memmove(b, a, len));
    printf("   memmove >%s< %p\n", (char *)memmove(b1, a1, len),\
	(char *)memmove(b1, a1, len));
    return (0);
}*/
// %p ens mostra la direccio de memoria
//%s ens mostra el contingut de la dir de memoria
