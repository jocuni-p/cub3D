/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:28:56 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/04 11:44:51 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* move this header to the common header in the main branch*/

#ifndef RAYCAST_H
# define RAYCAST_H
//# include "./MLX42/include/MLX42/MLX42.h"

# include <math.h> // cos, sin, hypot, fmod
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# ifndef FOV
#  define FOV 60
# endif
# define PI 3.1415926535
# define RAD(deg) ((deg) * PI / 180.0) // Not sure if it is allowed, got a function angle_in_radians if this cannot be used
# define MAX_DIST 1600 // Test the number, maybe too small. Also think about fog if distance is bigger.
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TILE_SIZE 64

typedef struct	s_player
{
	double	x;			// Player's X position
	double	y;			// Player's Y position
	double	angle;		// Player's viewing angle (in radians)
	double	fov;
}	t_player;

typedef struct	s_ray
{
	double	angle;
	double	direction_x;
	double	direction_y;
	int		map_x;			// coordinate for the map grid
	int		map_y;			// coordinate for the map grid
	double	delta_dist_x;
	double	delta_dist_y;
	int		changed_x_position;
	int		changed_y_position;
	int		map_step_x;
	int		map_step_y;
	double	side_dist_x;	// distance to next intersection on x axis
	double	side_dist_y; 	// distance to next intersection on y axis
	double	distance;		// Distance from player to the wall
}	t_ray;

void	print_ray_info(t_ray *ray);
double	angle_in_radians(double angle);
void	initialize_player(t_player *player, double x, double y, double angle);
double	normalize_angle(double angle);
void	initialize_ray(t_player *player, t_ray *ray);
float	cast_one_ray(t_player *player, t_ray *ray, char **map);
void	cast_all_rays(t_player *player, t_ray **rays, char **map);
void	set_ray_side_distances_and_steps(t_player *player, t_ray *ray);
void	free_array_of_rays(t_ray **rays, int array_size);
void	initialize_array_of_rays(t_ray **rays, int array_size);
void	print_ray_data(t_ray *ray);

#endif