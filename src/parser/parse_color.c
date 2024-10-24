/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:52:20 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/23 16:19:52 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*Encodes to one hexadecimal the four diferent color parameters*/
uint32_t	combiner_to_hexcolorformat(uint32_t r, uint32_t g, uint32_t b, uint32_t alpha)
{
	return (r << 24 | g << 16 | b << 8 | alpha);
}

/*Set ceiling' rgb values*/
int	set_c(t_parser *parser, char *rgb_canal, int i)
{
	uint32_t	nbr;

	nbr = (uint32_t)ft_atoi(rgb_canal);
	if (nbr < 0 || nbr > 255)
		return (1);
	if (i == 0)
		parser->elem.rgb_c[0] = nbr;
	if (i == 1)
		parser->elem.rgb_c[1] = nbr;
	if (i == 2)
	{
		parser->elem.rgb_c[2] = nbr;
		parser->elem.c_color = combiner_to_hexcolorformat(\
			parser->elem.rgb_c[0], parser->elem.rgb_c[1], \
			parser->elem.rgb_c[2], 255);
		parser->elem.c_opposite = get_opposite_color(parser);
	}
	return (0);
}

/*Set floor' rgb values*/
int	set_f(t_parser *parser, char *rgb_canal, int i)
{
	uint32_t	nbr;

	nbr = (uint32_t)ft_atoi(rgb_canal);
	if (nbr < 0 || nbr > 255)
		return (1);
	if (i == 0)
		parser->elem.rgb_f[0] = nbr;
	if (i == 1)
		parser->elem.rgb_f[1] = nbr;
	if (i == 2)
	{
		parser->elem.rgb_f[2] = nbr;
		parser->elem.f_color = combiner_to_hexcolorformat(\
			parser->elem.rgb_f[0], parser->elem.rgb_f[1], \
			parser->elem.rgb_f[2], 255);
	}
	return (0);
}

/*Set the elem.f_color and elem.c_color variables to hexadecimal value, 
if it fails return 1*/
int	parse_color(t_parser *parser, char *str, char c)
{
	int		i;
	int		j;
	char	**rgb_canals;

	i = 0;
	rgb_canals = ft_split(str, ',');
	if (arr2d_element_cnt(rgb_canals) != 3)
		return (arr2d_free(&rgb_canals), 1);
	while (rgb_canals[i])
	{
		j = 0;
		while (rgb_canals[i][j])
		{
			if (!ft_isdigit(rgb_canals[i][j++]))
				return (arr2d_free(&rgb_canals), 1);
		}
		if ((c == 'c' && set_c(parser, rgb_canals[i], i)) \
		|| (c == 'f' && set_f(parser, rgb_canals[i], i)))
			return (arr2d_free(&rgb_canals), 1);
		i++;
	}
	return (arr2d_free(&rgb_canals), 0);
}

/*
int	parse_color(t_parser *parser, char *str, char c)
{
	int		i;
	int		j;
	char	**rgb_canals;

	i = 0;
	rgb_canals = ft_split(str, ',');
	if (arr2d_element_cnt(rgb_canals) != 3)
		return (arr2d_free(&rgb_canals), 1);
	while(rgb_canals[i])
	{
		j = 0;
		while (rgb_canals[i][j])
		{
			if (!ft_isdigit(rgb_canals[i][j]))
				return (arr2d_free(&rgb_canals), 1);
			j++;
		}
		if (c == 'c')
		{
			if (set_c(parser, rgb_canals[i], i))
				return (arr2d_free(&rgb_canals), 1);
		}
		else
		{
			if (set_f(parser, rgb_canals[i], i))
				return (arr2d_free(&rgb_canals), 1);
		}
		i++;
	}
	return (arr2d_free(&rgb_canals), 0);
}
*/