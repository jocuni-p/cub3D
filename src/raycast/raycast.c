/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:28:56 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/30 13:37:58 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	configure_dda(t_game *game, t_ray *ray)
{
	if (ray->direction.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos.x - ray->grid_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->grid_x + 1.0 - game->player.pos.x)
			* ray->delta_dist_x;
	}
	if (ray->direction.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos.y - ray->grid_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->grid_y + 1.0 - game->player.pos.y)
			* ray->delta_dist_y;
	}
}

void	execute_dda(t_game *game, t_ray *ray)
{
	int		has_hit;

	has_hit = 0;
	while (has_hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->grid_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->grid_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->grid_y < 0.25 || ray->grid_x < 0.25
			|| ray->grid_y > HEIGHT - 1.25 || ray->grid_x > WIDTH - 1.25)
			break ;
		else if (game->map_arr[ray->grid_y][ray->grid_x] == '1')
			has_hit = 1;
	}
}

void	compute_wall_intersections(t_game *game, t_ray *ray)
{
	t_player	*player;

	player = &game->player;
	if (ray->side == 0)
		ray->wall_distance = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->wall_distance = (ray->side_dist_y - ray->delta_dist_y);
	ray->wall_height = (int)(HEIGHT / ray->wall_distance);
	ray->bottom_pixel = -(ray->wall_height) / 2 + HEIGHT / 2;
	if (ray->bottom_pixel < 0)
		ray->bottom_pixel = 0;
	ray->top_pixel = ray->wall_height / 2 + HEIGHT / 2;
	if (ray->top_pixel >= HEIGHT)
		ray->top_pixel = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_hit_x = player->pos.y + ray->wall_distance * ray->direction.y;
	else
		ray->wall_hit_x = player->pos.x + ray->wall_distance * ray->direction.x;
	ray->wall_hit_x -= floor(ray->wall_hit_x);
}

int	execute_raycasting(t_game *game)
{
	int				column;
	mlx_texture_t	*texture;

	column = -1;
	while (++column < WIDTH)
	{
		prepare_drawing_info(game, column);
		if (game->ray->side == 0)
		{
			if (game->ray->step_x > 0)
				texture = game->textures.text_e;
			else
				texture = game->textures.text_w;
		}
		else
		{
			if (game->ray->step_y > 0)
				texture = game->textures.text_s;
			else
				texture = game->textures.text_n;
		}
		draw_wall(game, texture, column);
	}
	return (1);
}
