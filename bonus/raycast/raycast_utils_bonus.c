/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:28:56 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/12/02 01:12:19 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

/**
 * Initializes the raycasting information for a given column. Calculates the
 * ray direction and grid position based on the camera plane and player
 * direction. Computes the delta distances for ray traversal.
 */
void	initialize_raycast_info(int column, t_game *game)
{
	t_player	*player;

	player = &game->player;
	reset_ray_values(game->ray);
	game->ray->camera_offset = 2 * column / (float)WIDTH - 1;
	game->ray->direction.x = player->dir.x + player->plane.x
		* game->ray->camera_offset;
	game->ray->direction.y = player->dir.y + player->plane.y
		* game->ray->camera_offset;
	game->ray->grid_x = (int)player->pos.x;
	game->ray->grid_y = (int)player->pos.y;
	game->ray->delta_dist_x = fabs(1 / game->ray->direction.x);
	game->ray->delta_dist_y = fabs(1 / game->ray->direction.y);
}

/**
 * Resets all raycasting-related values in the `t_ray` structure to their
 * default state.
 */
void	reset_ray_values(t_ray *ray)
{
	ray->camera_offset = 0;
	ray->direction.x = 0;
	ray->direction.y = 0;
	ray->grid_x = 0;
	ray->grid_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->wall_distance = 0;
	ray->wall_hit_x = 0;
	ray->side = 0;
	ray->wall_height = 0;
	ray->bottom_pixel = 0;
	ray->top_pixel = 0;
}

/**
 * Frees the memory allocated for the raycasting structure and sets its
 * pointer to NULL.
 */
void	ray_free(t_game *game)
{
	if (game->ray)
	{
		free (game->ray);
		game->ray = NULL;
	}
}

/**
 * Prepares the raycasting data for a column. Initializes ray information,
 * configures the DDA algorithm, executes the DDA to find a wall hit, and
 * computes wall intersection data for rendering.
 */
void	prepare_drawing_info(t_game *game, int column)
{
	initialize_raycast_info(column, game);
	configure_dda(game, game->ray);
	execute_dda(game, game->ray);
	compute_wall_intersections(game, game->ray);
}
