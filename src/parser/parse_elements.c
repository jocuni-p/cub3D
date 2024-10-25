/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:34:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/25 22:23:27 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Returns 1 if any invalid character is found, otherwise returns 0*/
int	check_element_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '/' \
			|| str[i] == '.' || str[i] == ' ' || str[i] == ',')
			i++;
		else
			return (1);
	}
	return (0);
}

/*Sets elem.variables with his value. If a duplicate or non valid 
element is found returns 1. Finally, 'elements' is freed. */
int	set_element(t_game *game, char **elements)
{
	if ((ft_strcmp(elements[0], "NO") == 0) && game->parser.elem.no == NULL)
		game->parser.elem.no = ft_strdup(elements[1]);
	else if ((ft_strcmp(elements[0], "SO") == 0) && game->parser.elem.so == NULL)
		game->parser.elem.so = ft_strdup(elements[1]);
	else if ((ft_strcmp(elements[0], "WE") == 0) && game->parser.elem.we == NULL)
		game->parser.elem.we = ft_strdup(elements[1]);
	else if ((ft_strcmp(elements[0], "EA") == 0) && game->parser.elem.ea == NULL)
		game->parser.elem.ea = ft_strdup(elements[1]);
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

/*---Returns 0 if all elements are set; otherwise, returns 1.----*/
int	flag_elem(t_game *game)
{
	if (game->parser.elem.no != NULL && game->parser.elem.so != NULL \
		&& game->parser.elem.we != NULL && game->parser.elem.ea != NULL \
		&& game->parser.elem.c_color != 0 && game->parser.elem.f_color != 0)
		return (0);
	return (1);
}

/*----Parses only the elements (4 textures + 2 colors) and sets a pointer to 
the map starting line. Returns 1 if some invalid case is found---*/
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
		if (!flag_elem(game))//checks if all elem.variables are already setted. 
			return (0);
		remove_nl(game->parser.cub->str);
		if (check_element_chars(game->parser.cub->str))
			return (print_error(ERR_ELEM), 1);
		elements = ft_split(game->parser.cub->str, ' ');
		if (arr2d_element_cnt(elements) != 2)
			return (arr2d_free(&elements), print_error(ERR_ELEM), 1);
//		arr2d_print(elements);//TEMPORAL
		if (set_element(game, elements))
			return (print_error(ERR_ELEM), 1);
		game->parser.cub = game->parser.cub->next;
		if (game->parser.cub == NULL)//if there isn't any map on the file.cub.
			return (print_error(ERR_ELEM), 1);
	}
	return (0);
}
