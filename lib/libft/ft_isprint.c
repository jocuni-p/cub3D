/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:17:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/05/31 09:57:24 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* function tests for any printing character, including space
     (` ').  The value of the argument must be representable as an unsigned
     char or the value of EOF. Returns zero if the character tests false and
     returns non-zero if the character tests true.*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
