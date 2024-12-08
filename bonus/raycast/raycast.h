/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:28:56 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/11/25 00:33:42 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* move this header to the common header in the main branch*/

#ifndef RAYCAST_H
# define RAYCAST_H
//# include "./MLX42/include/MLX42/MLX42.h"
# include "../include/cub3d.h"
# include "../../lib/MLX42/include/MLX42/MLX42.h"

# include <math.h> // cos, sin, hypot, fmod
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

# ifndef FOV
#  define FOV 60
# endif
# define PI 3.141592653589793
# define RAD(deg) ((deg) * PI / 180.0) // Not sure if it is allowed, got a function angle_in_radians if this cannot be used
# define MAX_DIST 1600 // Test the number, maybe too small. Also think about fog if distance is bigger.
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TILE_SIZE 64
# define VERTICAL 'v'
# define HORIZONTAL 'h'

/* STRUCTS */
typedef	struct s_intersection_parameters
{
	float	inter_x;
	float	inter_y;
	float	x_step;
	float	y_step;
	int		offset;
}	t_inter_param;

typedef struct s_coord //changed floats to float. probably reverse all to float with the new logic
{
	float			x;
	float			y;
}					t_coord;

typedef struct s_player //change this in the main header
{
	t_coord			pos;//(x,y) player's current position
	t_coord			dir;//(x,y) player's current direction
	t_coord			plane;//determina la proyección lateral de la cámara y 
//							permite simular una vista en 3D
	char			orientation;//initial orientation: N, S, E, W
	float			angle;		// Player's viewing angle (in radians)
	float			fov;
}					t_player;


// typedef struct	s_player
// {
// 	float	x;			// Player's X position
// 	float	y;			// Player's Y position
// 	float	angle;		// Player's viewing angle (in radians)
// 	float	fov;
// }	t_player;

typedef struct s_ray
{
	float	camera_offset;		// Camera position offset for the current ray
	t_coord	direction;			// Ray's coordinates
	int		grid_x;				// Current grid cell x-coordinate
	int		grid_y;				// Current grid cell y-coordinate
	int		step_x;				// Step direction in x-axis (+1 or -1)
	int		step_y;				// Step direction in y-axis (+1 or -1)
	float	side_dist_x;		// Distance to the next x-side of the grid
	float	side_dist_y;		// Distance to the next y-side of the grid
	float	delta_dist_x;		// Distance between x-sides of the grid
	float	delta_dist_y;		// Distance between y-sides of the grid
	float	wall_distance;		// Distance to the wall hit by the ray
	float	wall_hit_x;			// Exact x-coordinate of the wall hit
	int		side;				// 0 if the wall hit is vertical, 1 if horizontal
	int		wall_height;		// Height of the wall line to draw
	int		bottom_pixel;		// Starting pixel for the wall line
	int		top_pixel;			// Ending pixel for the wall line
}	t_ray;

// typedef struct	s_ray
// {
// 	float			distance;		// Distance from player to the wall
// 	float			angle;
// 	t_inter_param	*inter_param;
// }	t_ray;

/* Printing functions */
void 	print_inter_param(t_inter_param param);
void	print_ray_info(t_ray *ray);

/* Service functions */
float	normalize_angle(float angle);
float	angle_in_radians(float angle);

/* Struct initialization functions */
void	initialize_player(t_player *player, float x, float y, float angle);
void	initialize_array_of_rays(t_ray **rays, int array_size);
// void	reset_ray_values(t_player *player, t_ray *ray);
void	reset_ray_values(t_ray *ray);

/* Struct freeing functions */
void	free_array_of_rays(t_ray **rays, int array_size);

/* Ray casting functions */

#endif