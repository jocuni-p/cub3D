/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:55:11 by jocuni-p          #+#    #+#             */
/*   Updated: 2023/05/31 09:55:19 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*function tests for an ASCII character, which is any charac-
     ter between 0 and octal 0177 inclusive.*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
