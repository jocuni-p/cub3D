/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:56:46 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/11 15:17:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*------Argument extension name validator-----*/
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