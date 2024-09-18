/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:27:37 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/12 14:33:37 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Protected malloc. Allocates 'size' bytes of mem and returns a pointer to it.
Exits properly if memory allocation fails.*/
void	*p_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		write(2, "Error: memory allocation failure\n", 33);
		exit (EXIT_FAILURE);
	}
	return (ptr);
}