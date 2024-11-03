/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:34:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/03 17:27:46 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

/*Return 0 if all elements are setted with correct path; otherwise returns 1*/
int	check_setted_elements(t_game *game)
{
	if (game->parser.elem.no != NULL && game->parser.elem.so != NULL \
		&& game->parser.elem.we != NULL && game->parser.elem.ea != NULL \
		&& game->parser.elem.c_color != 0 && game->parser.elem.f_color != 0)
	{
		if ((ft_strcmp(game->parser.elem.no, "./textures/brick_n.png") == 0 \
		|| ft_strcmp(game->parser.elem.no, "textures/brick_n.png") == 0) \
		&& (ft_strcmp(game->parser.elem.so, "./textures/brick_s.png") == 0 \
		|| ft_strcmp(game->parser.elem.so, "textures/brick_s.png") == 0) \
		&& (ft_strcmp(game->parser.elem.ea, "./textures/brick_e.png") == 0 \
		|| ft_strcmp(game->parser.elem.ea, "textures/brick_e.png") == 0) \
		&& (ft_strcmp(game->parser.elem.we, "./textures/brick_w.png") == 0 \
		|| ft_strcmp(game->parser.elem.we, "textures/brick_w.png") == 0))
			return (0);
		return (2);
	}
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
		if (check_setted_elements(game) == 0)//checks if all elements are already setted properly 
			return (0);
		if (check_setted_elements(game) == 2)//if texture path is invalid 
			return (print_error(ERR_PATH), 1);
		remove_nl(game->parser.cub->str);
		elements = ft_split(game->parser.cub->str, ' ');
		if (arr2d_element_cnt(elements) != 2)
			return (arr2d_free(&elements), print_error(ERR_ELEM), 1);
		if (set_element(game, elements))
			return (print_error(ERR_ELEM), 1);
		game->parser.cub = game->parser.cub->next;
		if (game->parser.cub == NULL)//if there isn't any map on the file.cub.
			return (print_error(ERR_ELEM), 1);
	}
	return (0);
}
