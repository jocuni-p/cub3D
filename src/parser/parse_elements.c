/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:34:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/02 21:24:57 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/**
 * Sets game elemen like textures and colors. Stores the values for North, 
 * South, West, and East directions if valid.Validates the element type
 * and its value. Parses colors for ceiling and floor. Frees memory on errors.
 * Returns 1 if an invalid or duplicate element is found.
 */
int	set_element(t_game *game, char **elemen)
{
	if ((ft_strcmp(elemen[0], "NO") == 0) && game->parser.elem.no == NULL)
		game->parser.elem.no = ft_strdup(elemen[1]);
	else if ((ft_strcmp(elemen[0], "SO") == 0) && game->parser.elem.so == NULL)
		game->parser.elem.so = ft_strdup(elemen[1]);
	else if ((ft_strcmp(elemen[0], "WE") == 0) && game->parser.elem.we == NULL)
		game->parser.elem.we = ft_strdup(elemen[1]);
	else if ((ft_strcmp(elemen[0], "EA") == 0) && game->parser.elem.ea == NULL)
		game->parser.elem.ea = ft_strdup(elemen[1]);
	else if ((ft_strcmp(elemen[0], "C") == 0) && game->parser.elem.c == NULL)
	{
		game->parser.elem.c = ft_strdup(elemen[1]);
		if (parse_color(game, game->parser.elem.c, 'c'))
			return (arr2d_free(&elemen), 1);
	}
	else if ((ft_strcmp(elemen[0], "F") == 0) && game->parser.elem.f == NULL)
	{
		game->parser.elem.f = ft_strdup(elemen[1]);
		if (parse_color(game, game->parser.elem.f, 'f'))
			return (arr2d_free(&elemen), 1);
	}
	else
		return (arr2d_free(&elemen), 1);
	return (arr2d_free(&elemen), 0);
}

/*--Returns the number of '/' characters found in the given string.--*/
static int	slash_counter(char *str)
{
	int	counter;

	counter = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == '/')
			counter++;
		str++;
	}
	return (counter);
}

/* Checks if every texture path contains only 2 '/' caracters*/
static int	slash_checker(t_game *game)
{
	if (slash_counter(game->parser.elem.no) == 2
		&& slash_counter(game->parser.elem.so) == 2
		&& slash_counter(game->parser.elem.we) == 2
		&& slash_counter(game->parser.elem.ea) == 2)
		return (2);
	return (0);
}

/**
 * Checks if all required elemen (4 textures, 2 colors) are set. Returns
 * 0 if all elemen are properly initialized; otherwise, returns 1.
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
 * Parses the configuration file's elemen section. Extracts textures and
 * colors and validates their formats. Sets a pointer to the map starting
 * line. Returns 1 on any error or invalid case.
 */
int	parse_elements(t_game *game)
{
	char	**elemen;

	while (game->parser.cub)
	{
		if (game->parser.cub->str[0] == '\n' && game->parser.cub->next)
		{
			game->parser.cub = game->parser.cub->next;
			continue ;
		}
		if (check_setted_elements(game) == 0 && slash_checker(game) == 2)
			return (0);
		remove_nl(game->parser.cub->str);
		elemen = ft_split(game->parser.cub->str, ' ');
		if (arr2d_element_cnt(elemen) != 2)
			return (arr2d_free(&elemen), print_error(ERR_ELEM), 1);
		if (set_element(game, elemen))
			return (print_error(ERR_ELEM), 1);
		if (game->parser.cub->next)
			game->parser.cub = game->parser.cub->next;
		if (game->parser.cub->next == NULL)
			return (print_error(ERR_ELEM), 1);
	}
	return (0);
}
