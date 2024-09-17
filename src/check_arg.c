/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:55:20 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/17 16:11:47 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_arg(char *str)
{
	if (check_file_name(str))
		return (handle_error(ERR_ARG_NAME, NULL), 1);
	if (check_file_ext(str))
		return (handle_error(ERR_ARG_EX, NULL), 1);
	return (0);
}