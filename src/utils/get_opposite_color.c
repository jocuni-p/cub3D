/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opposite_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:09:25 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/30 19:01:32 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_opposite_color(t_game *game)
{
	int	opposite;

	opposite = combiner_hex(255 - game->parser.elem.rgb_c[0], \
	255 - game->parser.elem.rgb_c[1], 255 - game->parser.elem.rgb_c[2], 255);
	return (opposite);
}
