/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:58:35 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/06 18:13:50 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*tests for any character for which isupper(3) or islower(3) is true. 
 * The value of the argument must be representable as an unsigned char or 
 * the value of EOF. Returns zero if the character tests false and
     returns non-zero if the character tests true.*/

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
