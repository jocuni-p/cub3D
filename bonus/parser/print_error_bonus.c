/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:27:30 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/09 15:30:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

/*------Prints an error message-----*/
void	print_error(char *str)
{
	int	i;

	i = write(2, str, ft_strlen(str));
	(void)i;
}
