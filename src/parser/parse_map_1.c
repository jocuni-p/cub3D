/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:26:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/11 10:27:10 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*---Return 0 if str contains '1' and/or ' ' character, otherwise return 1*/
/*The function works equally for the first or the last lines*/
int	is_firstline_valid(char *str)
{
	int		i;
	char	*trim_line;

	i = 0;
	remove_nl(str);
	trim_line = ft_strtrim(str, " ");
	if (trim_line[i] == '\0')
	{
		free(trim_line);
		return (1);
	}
	while (trim_line[i])
	{
		if (trim_line[i] == '1')
			i++;
		else if (trim_line[i] == ' ')
			i++;
		else
		{
			free(trim_line);
			return (1);
		}
	}
	free(trim_line);
	return (0);
}

/*Return 0 if str began and finish with char '1', otherwise return 1*/
int	is_first_and_last_char_valid(char *str)
{
	if (str[0] == '1' && str[ft_strlen(str) - 1] == '1')
		return (0);
	else
		return (1);
}

/*Return 0 if str contents 1/0/' '/N/S/W or E, otherwise return 1*/
int	is_middle_char_valid(char *str, t_parser *parser)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '1' || str[i] == '0')
			i++;
		else if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' \
		|| str[i] == 'E')
		{
			parser->map.player_qty++;
			parser->map.player_view = str[i];
			i++;
		}
		else
			return (1);
	}
	return (0);
}

/*Parses since the next line of elements til the end of file.cub*/
int	parse_map_1(t_parser *parser)
{
	char	*trimmed_line;

	while (parser->cub->str[0] == '\n')
		parser->cub = parser->cub->next;
	parser->map_firstline = parser->cub;//sets a pointer to the map first line
	if (parser->map_firstline == NULL || is_firstline_valid(parser->cub->str))
		return (print_error(ERR_MAP), 1);
	parser->cub = parser->cub->next;
	while (parser->cub)
	{
		remove_nl(parser->cub->str);
		if (parser->cub->str[0] == '\0')//if it's an empty line
			return (print_error(ERR_MAP), 1);
		trimmed_line = ft_strtrim(parser->cub->str, " ");//remove ' ' from beginning and from end
		if (is_first_and_last_char_valid(trimmed_line))
			return (free(trimmed_line), print_error(ERR_MAP), 1);
		if (is_middle_char_valid(trimmed_line, parser))
			return (free(trimmed_line), print_error(ERR_MAP), 1);
		if (parser->cub->next == NULL)//if it is the last line
			if (is_firstline_valid(trimmed_line))//cheks if the last map line is valid 
				return (free(trimmed_line), print_error(ERR_MAP), 1);
		free(trimmed_line);
		parser->cub = parser->cub->next;
	}
	return (0);
}
