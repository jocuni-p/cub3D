/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:55:20 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/11 10:27:10 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*Checks if the input is a valid name format*/
int	check_arg_name(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (str[i] == '.')
		{
			flag++;
			if (flag > 1)
				return (1);
		}
		if (str[i] == '/' && (str[i + 1] == '.' || str[i + 1] == ' '))
			return (1);
		if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57) \
		|| str[i] == '_' || str[i] == '/' || str[i] == '.')
			i++;
		else
			return (1);
	}
	return (0);
}

/*---Returns 0 if str contains ".cub"; if not or it is NULL, returns 1---*/
int	check_arg_ext(char *str)
{
	char	*ext;

	if (str == NULL)
		return (1);
	ext = ft_strrchr(str, '.');
	if (ext == NULL || ft_strlen(ext) != 4 || ft_strncmp(ext, ".cub", 4) != 0)
		return (1);
	return (0);
}

int	check_arg(char *str)
{
	if (check_arg_name(str))
		return (print_error(ERR_ARG_NAME), 1);
	if (check_arg_ext(str))
		return (print_error(ERR_ARG_EX), 1);
	return (0);
}
