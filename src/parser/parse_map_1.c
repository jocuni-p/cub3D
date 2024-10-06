/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:26:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/06 12:37:45 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*---Return 0 if str contains '1' and/or ' ' character, otherwise return 1*/
/*This function checks the first and last lines*/
int	is_firstline_valid(char *str)
{
	int	i;
	char	*trim_line;
	
	i = 0;
	remove_nl(str);
	trim_line = ft_strtrim(str, " ");//quito espacios para analizar el str
	if (trim_line[i] == '\0')
	{
		free(trim_line);
		return (1);
	}
	while(trim_line[i])
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
		else if ( str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
		{
			parser->map.player_qty++;//counts the number of players
			parser->map.player_view = str[i];//sets the player's view
			i++;
		}
		else
			return (1);
	}
	return (0);
}

int	parse_map_1(t_parser *parser)
{
	char	*trimmed_line;
	
	while (parser->cub->str[0] == '\n')//skips empty lines
		parser->cub = parser->cub->next;
	parser->map_firstline = parser->cub;//sets a pointer to the map first line
	if (is_firstline_valid(parser->cub->str))
		return (handle_error(ERR_MAP), 1);
	parser->cub = parser->cub->next;
	while (parser->cub)
	{
		remove_nl(parser->cub->str);
		if (parser->cub->str[0] == '\0')//if it's an empty line
			return (handle_error(ERR_MAP), 1);
		trimmed_line = ft_strtrim(parser->cub->str, " ");//quito espacios para analizar el str
		if (is_first_and_last_char_valid(trimmed_line))//si la linea empieza y acaba en 1  
			return (handle_error(ERR_MAP), 1);//OJO incluir aqui el free de trimmmed_line	
		if (is_middle_char_valid(trimmed_line, parser))//si contenido != 1, 0, E, N,S, W, " " -> INVALID
			return (handle_error(ERR_MAP), 1);//OJO incluir aqui el free de trimmmed_line
		if (parser->cub->next == NULL)//si es la ultima linea
			if (is_firstline_valid(trimmed_line))//cheks if the last map line is valid (same function than the first line) 
				return (handle_error(ERR_MAP), 1);//OJO incluir aqui el free de trimmmed_line
		free(trimmed_line);
		parser->cub = parser->cub->next;
	}
	return (0);
}
