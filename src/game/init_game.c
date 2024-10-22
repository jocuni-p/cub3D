/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:45:44 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/22 19:23:05 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_game(mlx_t *mlx, t_game *game, t_parser *parser)
{
	game->map = parser->raw_map;
	game->p_x = parser->map.player_x;
	game->p_y = parser->map.player_y;
	game->p_view = parser->map.player_view;
	game->mlx = mlx;
	game->game_img = mlx_new_image(mlx, 1000, 500);//Main image creation
	if (!game->game_img)
		return (error(), 1);
//	game->no = parser->elem.no;
//	game->so = parser->elem.so;
//	game->ea = parser->elem.ea;
//	game->we = parser->elem.we;
	game->c_col = parser->elem.c_color;
	game->f_col = parser->elem.f_color;
	game->c_col_opposite = get_opposite_color(parser);
	return (0);
	
}
