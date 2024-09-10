/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:08:33 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/07/06 12:36:15 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* strlcat concatena la cadena src a continuacion de la cadena dst de forma
 segura, de manera que no se exceda el tamanyo maximo del buffer de dst.
 dstsize nos dice el espacio de memoria (NO del len de dst) que contiene dst
 Se terminara con el caracter NULL a menos que dstsize sea 0 o la cadena dst 
 original sea mas larga que dstsize. En la practica esto no deberia de pasar 
 si no es que dstsize es incorrect o que dst no es una cadena adecuada.*/

//#include<stdio.h>
//#include<string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	unsigned int	len_dst;
	unsigned int	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	while ((len_dst + i + 1) < dstsize && src[i])
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
/*
int	main(void)
{
	char	src[] = "baroloca";
	char 	src2[] = "baroloca";
	char	dst[] = "pilaNN";
	char	dst2[] = "pilaNN";
	size_t	rtno;
	size_t	rtnm;
	size_t	dstsize = 10;
//El dstsize ha d'incloure espai pels 2 strings + el '\0'
	printf("src >%s<\ndst >%s<\ndstsize >%zu<\n\n", src, dst, dstsize);
	rtnm = ft_strlcat(dst,src,dstsize);
	printf("ft_strlcat >%s< >%zu<\n\n", dst, rtnm);
	rtno = strlcat(dst2, src2, dstsize);
	printf("   strlcat >%s< >%zu<\n", dst2, rtno);
	return (0);
}*/
