/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:06:12 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/06/28 16:17:52 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*The calloc() function contiguously allocates enough space for count
     objects that are size bytes of memory each and returns a pointer to the
     allocated memory.  The allocated memory is filled with bytes of value
     zero by ft_bzero function.
	 Return a pointer to allocated memory.  If there is an error, they return
	 a NULL pointer.*/

//#include<stdio.h>
//#include<stdlib.h>
#include "libft.h"

/*
void    *ft_calloc(size_t count, size_t size)
{
    int *array;

    array = (int *) malloc(count * size);
    if (array == NULL)
        return (NULL);
    ft_bzero(array, (count * size));
    return ((void *)array);
}*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	array = malloc(count * size);
	if (!array)
		return (NULL);
	ft_bzero(array, (count * size));
	return (array);
}
/*
int	main(void)
{
	printf("ft_calloc >%p<\n", ft_calloc(25, 1));
	printf("ft_calloc >%s<\n", ft_calloc(25, 1));
	printf("   calloc >%p<\n", calloc(20, 1));
	printf("   calloc >%s<\n", calloc(20, 1));
	return (0);
}*/
