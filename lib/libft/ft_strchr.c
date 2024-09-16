/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joan <joan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:07:13 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/05/19 04:34:07 by joan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strchr() function locates the first occurrence of c (converted to a char)
 in the string pointed to by s.  The terminating null character is considered 
 to be part of the string; therefore if c is `\0', the functions locate the
  terminating `\0'.
 The function strchr() return a pointer to the located character, or NULL if 
 the character does not appear in the string.*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	c = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
