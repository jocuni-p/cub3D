/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:48:43 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/29 12:31:19 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 The strlcpy() and strlcat() functions copy and concatenate strings with the
  same input parameters.
 strlcpy() and strlcat() take the full size of the destination buffer and
 guarantee NUL-termination if there is room.  Note that room for the NUL
 should be included in dstsize.
 strlcpy() copies up to dstsize - 1 characters from the string src to dst,
 NUL-terminating the result if dstsize is not 0.
 If the src and dst strings overlap, the behavior is undefined.
 Function return the total
 length of the string they tried to create.  For strlcpy() that means the
 length of src.
 If the return value is >= dstsize, the output string has been truncated.
 It is the caller's responsibility to handle this.*/

//#include<string.h>
//#include<stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}
/*
//dstsize - 1 es para dejar un byte para poder cerrar el string con el \0
int	main(void)
{
	char	src[] = "barbados";
	char	dst[] = "pilar";
	size_t	dstsize = 2;
	printf("src >%s<\ndst >%s<\ndstsize >%zu<\n", src, dst, dstsize);
	printf("dst >%s<\nft_strlcpy >%zu<\n", dst, ft_strlcpy(dst, src, dstsize));
	printf("dst >%s<\nstrlcpy >%zu<\n", dst, strlcpy(dst, src, dstsize));
	return (0);
}*/
