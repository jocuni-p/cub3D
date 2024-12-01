/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:34:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/01 23:56:53 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Parses and sets directional texture paths in the game's parser structure.
 * Stores the values for North, South, West, and East directions if valid.
 */
static void	set_elements_directions(t_game *game, char **elements)
{
	if ((ft_strcmp(elements[0], "NO") == 0)
		&& game->parser.elem.no == NULL)
		game->parser.elem.no = ft_strdup(elements[1]);
	else if ((ft_strcmp(elements[0], "SO") == 0)
		&& game->parser.elem.so == NULL)
		game->parser.elem.so = ft_strdup(elements[1]);
	else if ((ft_strcmp(elements[0], "WE") == 0)
		&& game->parser.elem.we == NULL)
		game->parser.elem.we = ft_strdup(elements[1]);
	else if ((ft_strcmp(elements[0], "EA") == 0)
		&& game->parser.elem.ea == NULL)
		game->parser.elem.ea = ft_strdup(elements[1]);
}

/**
 * Sets game elements like textures and colors. Validates the element type
 * and its value. Parses colors for ceiling and floor. Frees memory on errors.
 * Returns 1 if an invalid or duplicate element is found.
 */
int	set_element(t_game *game, char **elements)
{
	if ((ft_strcmp(elements[0], "NO") == 0)
		|| (ft_strcmp(elements[0], "SO") == 0)
		|| (ft_strcmp(elements[0], "WE") == 0)
		|| (ft_strcmp(elements[0], "EA") == 0))
		set_elements_directions(game, elements);
	else if ((ft_strcmp(elements[0], "C") == 0) && game->parser.elem.c == NULL)
	{
		game->parser.elem.c = ft_strdup(elements[1]);
		if (parse_color(game, game->parser.elem.c, 'c'))
			return (arr2d_free(&elements), 1);
	}
	else if ((ft_strcmp(elements[0], "F") == 0) && game->parser.elem.f == NULL)
	{
		game->parser.elem.f = ft_strdup(elements[1]);
		if (parse_color(game, game->parser.elem.f, 'f'))
			return (arr2d_free(&elements), 1);
	}
	else
		return (arr2d_free(&elements), 1);
	return (arr2d_free(&elements), 0);
}

/**
 * Checks if all required elements (4 textures, 2 colors) are set. Returns
 * 0 if all elements are properly initialized; otherwise, returns 1.
 */
int	check_setted_elements(t_game *game)
{
	if (game->parser.elem.no != NULL && game->parser.elem.so != NULL \
		&& game->parser.elem.we != NULL && game->parser.elem.ea != NULL \
		&& game->parser.elem.c_color != 0 && game->parser.elem.f_color != 0)
		return (0);
	return (1);
}

/**
 * Parses the configuration file's elements section. Extracts textures and
 * colors and validates their formats. Sets a pointer to the map starting
 * line. Returns 1 on any error or invalid case.
 */
int	parse_elements(t_game *game)
{
	char	**elements;

	while (game->parser.cub)
	{
		if (game->parser.cub->str[0] == '\n')
		{
			game->parser.cub = game->parser.cub->next;
			continue ;
		}
		if (check_setted_elements(game) == 0)
			return (0);
		remove_nl(game->parser.cub->str);
		elements = ft_split(game->parser.cub->str, ' ');
		if (arr2d_element_cnt(elements) != 2)
			return (arr2d_free(&elements), print_error(ERR_ELEM), 1);
		if (set_element(game, elements))
			return (print_error(ERR_ELEM), 1);
		game->parser.cub = game->parser.cub->next;
		if (game->parser.cub == NULL)
			return (print_error(ERR_ELEM), 1);
	}
	return (0);
}
