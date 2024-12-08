/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:55:20 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/02 01:21:20 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"
/**
 * Checks if the input filename has a valid name format. Ensures it contains
 * only valid characters and avoids invalid patterns. Returns 1 if invalid.
 */
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

/**
 * Validates the file extension of the input filename. Ensures the file ends
 * with `.cub`. Returns 1 if the extension is missing or invalid.
 */
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

/**
 * Validates the input filename. Checks both the name format and file extension.
 * Returns 1 if either validation fails.
 */
int	check_arg(char *str)
{
	if (check_arg_name(str))
		return (print_error(ERR_ARG_NAME), 1);
	if (check_arg_ext(str))
		return (print_error(ERR_ARG_EX), 1);
	return (0);
}
