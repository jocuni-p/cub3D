/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:56:46 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/28 17:00:15 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*---Returns 0 if str contains ".cub"; if not or it is NULL, returns 1---*/
int	check_file_ext(char *str)
{
	char	*ext;

	if (str == NULL)
		return (1);
	ext = ft_strrchr(str, '.');
	if (ext == NULL || ft_strlen(ext) != 4 || ft_strncmp(ext, ".cub", 4) != 0)
		return (1);
	return (0);
}