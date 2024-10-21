/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:45:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/21 16:59:21 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_game(mlx_t *mlx, t_game *game, t_parser *parser)
{
	game->map = parser->raw_map;
	game->p_x = parser->map.player_x;
	game->p_y = parser->map.player_y;
	game->p_view = parser->map.player_view;
	game->game_img = mlx_new_image(mlx, 2000, 1000);
	if (!game->game_img)
		return (error(), 1);
//	game->no = parser->elem.no;
//	game->so = parser->elem.so;
//	game->ea = parser->elem.ea;
//	game->we = parser->elem.we;
//	game->c_col = parser->elem.c_color;
//	game->f_col = parser->elem.f_color;
}
