/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr2d_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:14:18 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/01 23:54:27 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

/**
 * Calculates the size of a 2D array to represent the map. Determines the
 * maximum width and total height of the map from the linked list of lines.
 * Updates the game's map dimensions.
 */
int	arr2d_size(t_game *game)
{
	t_cub	*tmp;
	int		len;
	int		high;
	int		len_aux;

	len = 0;
	high = 1;
	tmp = game->parser.map_ln0;
	if (!tmp)
		return (1);
	len = ft_strlen(tmp->str);
	tmp = tmp->next;
	while (tmp)
	{
		len_aux = ft_strlen(tmp->str);
		if (len_aux > len)
			len = len_aux;
		tmp = tmp->next;
		high++;
	}
	game->map_w = len;
	game->map_h = high;
	return (0);
}

/**
 * Fills the 2D array with data from the linked list of map lines. Copies
 * each character from the list into the corresponding array position.
 */
int	arr2d_filler(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_arr[i] != NULL && game->parser.map_ln0 != NULL)
	{
		j = 0;
		while (game->parser.map_ln0->str[j] != '\0' && j < game->map_w)
		{
			game->map_arr[i][j] = game->parser.map_ln0->str[j];
			j++;
		}
		i++;
		game->parser.map_ln0 = game->parser.map_ln0->next;
	}
	return (0);
}

/**
 * Creates a 2D array to represent the map. Allocates memory for the array
 * based on the map's dimensions. Fills the array using `arr2d_filler`. Returns
 * 1 if any allocation fails or the map is invalid.
 */
int	arr2d_creator(t_game *game)
{
	int	i;

	i = 0;
	if (arr2d_size(game))
		return (print_error(ERR_MAP), 1);
	game->map_arr = (char **)malloc(sizeof(char *) * (game->map_h + 1));
	if (!game->map_arr)
		return (print_error(ERR_MAP), 1);
	while (i < game->map_h)
	{
		game->map_arr[i] = (char *)malloc(sizeof(char) * (game->map_w + 1));
		if (!game->map_arr[i])
			return (print_error(ERR_MAP), 1);
		ft_memset(game->map_arr[i], ' ', game->map_w);
		game->map_arr[i][game->map_w] = '\0';
		i++;
	}
	game->map_arr[i] = NULL;
	arr2d_filler(game);
	return (0);
}
