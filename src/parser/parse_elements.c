/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:34:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/01 19:10:11 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Compares the input texture path with the expected one. Return 1 if are
 different*/
 /*
int	check_element_path(t_game *game)
{
	printf("holi\n");//DEBUG
	if (game->parser.elem.no && ft_strcmp(game->parser.elem.no, "./textures/brick_n.png") != 0)
		return (1);
	else if (game->parser.elem.so && ft_strcmp(game->parser.elem.so, "./textures/brick_s.png") != 0)
		return (1);
	else if (game->parser.elem.ea && ft_strcmp(game->parser.elem.ea, "./textures/brick_e.png") != 0)
		return (1);
	else if (game->parser.elem.we && ft_strcmp(game->parser.elem.we, "./textures/brick_w.png") != 0)
		return (1);
	else	
		return (0);
}
*/

/*Returns 1 if any invalid character is found, otherwise returns 0*/
/*
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
}*/

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
		printf("NO: %s\n", game->parser.elem.no);//DEBUG
		printf("SO: %s\n", game->parser.elem.so);//DEBUG
		printf("EA: %s\n", game->parser.elem.ea);//DEBUG
		printf("WE: %s\n", game->parser.elem.we);//DEBUG

		printf(GREEN "texturas seteadas\n");//DEBUG
		if (ft_strcmp(game->parser.elem.no, "./textures/brick_n.png") == 0 \
		&& ft_strcmp(game->parser.elem.so, "./textures/brick_s.png") == 0 \
		&& ft_strcmp(game->parser.elem.ea, "./textures/brick_e.png") == 0 \
		&& ft_strcmp(game->parser.elem.we, "./textures/brick_w.png") == 0)
		{
			printf(GREEN "texturas con paths correctos\n");//DEBUG
			return (0);
		}
	}
	printf(RED "texturas no todas seteadas\n");//DEBUG
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
		if (check_setted_elements(game) == 0)//checks if all elem.var are already setted. 
			return (0);
		remove_nl(game->parser.cub->str);
//		if (check_element_chars(game->parser.cub->str))
//			return (print_error(ERR_ELEM), 1);
		elements = ft_split(game->parser.cub->str, ' ');
		if (arr2d_element_cnt(elements) != 2)
			return (arr2d_free(&elements), print_error(ERR_ELEM), 1);
		if (set_element(game, elements))//NEW ADDED
			return (print_error(ERR_ELEM), 1);
		game->parser.cub = game->parser.cub->next;
		if (game->parser.cub == NULL)//if there isn't any map on the file.cub.
			return (print_error(ERR_ELEM), 1);
		printf("linea seteada\n");//DEBUG
	}
//	if (check_element_path(game))
//		return (print_error(ERR_ELEM), 1);
	return (0);
}
