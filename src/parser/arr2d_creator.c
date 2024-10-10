/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr2d_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:14:18 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/10 17:03:44 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*Calculates an array of strings size according the measures of our map*/
int	arr2d_size(t_parser *parser)
{
	t_cub	*tmp;
	int		len;
	int		high;
	int		len_aux;

	len = 0;
	high = 1;
	tmp = parser->map_firstline;
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
	parser->map.w = len;
	parser->map.h = high;
//	printf("map size = %i x %i\n\n", len, high);//TEMPORAL
	return (0);
}

/*Fills every element of the array*/
int	arr2d_filler(t_parser *parser)
{
	int	i;
	int	j;

	i = 0;
	while (parser->raw_map[i] != NULL && parser->map_firstline != NULL)
	{
		j = 0;
		while (parser->map_firstline->str[j] != '\0' && j < parser->map.w)
		{
			parser->raw_map[i][j] = parser->map_firstline->str[j];
			j++;
		}
		i++;
		parser->map_firstline = parser->map_firstline->next;
	}
	return (0);
}

/*Transfers map from a list into a 2D matrix*/
int	arr2d_creator(t_parser *parser)
{
	int	i;

	i = 0;
	if (arr2d_size(parser))
		return (handle_error(ERR_MAP), 1);
	parser->raw_map = (char **)malloc(sizeof(char *) * parser->map.h + 1);
	if (!parser->raw_map)
		return (handle_error(ERR_MAP), 1);		
	while (i < parser->map.h)
	{
		parser->raw_map[i] = (char *)malloc(sizeof(char) * parser->map.w + 1);
		if (!parser->raw_map[i])
			return (handle_error(ERR_MAP), 1);
		ft_memset(parser->raw_map[i], ' ', parser->map.w);
		parser->raw_map[i][parser->map.w] = '\0';
		i++;
	}
	parser->raw_map[i] = NULL;
	arr2d_filler(parser);
	return (0);
}
