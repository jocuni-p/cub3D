/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:26:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 16:42:37 by rzhdanov         ###   ########.fr       */
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
int	is_middle_char_valid(char *str, t_game *game)
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
			game->parser.ply_qty++;
			game->player.orientation = str[i];
			i++;
		}
		else
			return (1);
	}
	return (0);
}

static void	skip_new_lines(t_game *game)
{
	while (game->parser.cub->str[0] == '\n')
		game->parser.cub = game->parser.cub->next;
	game->parser.map_ln0 = game->parser.cub;
}

/*Parses since the next line of elements til the end of file.cub*/
int	parse_map_1(t_game *game)
{
	char	*trimmed_line;

	skip_new_lines(game);
	if (game->parser.map_ln0 == NULL
		|| is_firstline_valid(game->parser.cub->str))
		return (print_error(ERR_MAP), 1);
	game->parser.cub = game->parser.cub->next;
	while (game->parser.cub)
	{
		remove_nl(game->parser.cub->str);
		if (game->parser.cub->str[0] == '\0')
			return (print_error(ERR_MAP), 1);
		trimmed_line = ft_strtrim(game->parser.cub->str, " ");
		if (is_first_and_last_char_valid(trimmed_line))
			return (free(trimmed_line), print_error(ERR_MAP), 1);
		if (is_middle_char_valid(trimmed_line, game))
			return (free(trimmed_line), print_error(ERR_MAP), 1);
		if (game->parser.cub->next == NULL)
			if (is_firstline_valid(trimmed_line))
				return (free(trimmed_line), print_error(ERR_MAP), 1);
		free(trimmed_line);
		game->parser.cub = game->parser.cub->next;
	}
	return (0);
}
