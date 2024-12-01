/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr2d_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:14:18 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 16:26:53 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Calculates an array of strings size according the measures of our map*/
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

/*Fills every element of the array*/
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

/*Transfers map from a list into a 2D matrix*/
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
