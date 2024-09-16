/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:22:37 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/05/31 10:50:41 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*function converts a lower-case letter to the corresponding
     upper-case letter.  The argument must be representable as an unsigned
     char or the value of EOF.
	 If the argument is a lower-case letter, the toupper() function returns
     the corresponding upper-case letter if there is one; otherwise, the argu-
     ment is returned unchanged.*/

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
		return (c);
	}
	return (c);
}
