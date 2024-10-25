/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opposite_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:09:25 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/25 22:17:33 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	get_opposite_color(t_game *game)
{
	int	opposite;

	opposite = combiner_to_hexcolorformat(255 - game->parser.elem.rgb_c[0], \
	255 - game->parser.elem.rgb_c[1], 255 - game->parser.elem.rgb_c[2], 255);
	return (opposite);
}