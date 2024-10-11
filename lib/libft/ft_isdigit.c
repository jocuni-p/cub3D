/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:05:21 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/05/31 09:50:20 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*function tests for a decimal digit character. The value of the argument
 * must be representable as an unsigned char or the value of EOF. 
 * Return zero if the character tests false and return non-zero if 
 * the character tests true.*/

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
