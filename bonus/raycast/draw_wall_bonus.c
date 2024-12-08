/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:28:56 by rzhdanov          #+#    #+#             */
/*   Updated: 2024/12/08 17:57:00 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

/**
 * Computes the x-coordinate of the texture for a wall slice. Adjusts the
 * value based on the ray's hit side and direction. Ensures the texture x
 * value stays within valid bounds.
 */
static void	set_texture_x(t_game *game, mlx_texture_t *texture,
							int *texture_x)
{
	*texture_x = (int)(game->ray->wall_hit_x * texture->width);
	if ((game->ray->side == 0 && game->ray->direction.x > 0)
		|| (game->ray->side == 1 && game->ray->direction.y < 0))
		*texture_x = texture->width - *texture_x - 1;
	if (*texture_x < 0)
		*texture_x = 0;
	if ((uint32_t) * texture_x >= texture->width)
		*texture_x = texture->width - 1;
}

/**
 * Calculates the brightness based on the distance and maximum distance.
 * Uses an inverse exponential formula to simulate brightness attenuation.
 * Ensures the brightness does not fall below a specified minimum value.
 *
 * Parameters:
 *  - distance: The distance to calculate brightness for.
 *  - max_distance: The maximum distance at which brightness is calculated.
 *  - min_brightness: The minimum allowable brightness.
 *
 * Returns the calculated brightness as a float.
 */
float	calculate_brightness(float distance, float max_distance,
					float min_brightness)
{
	float	brightness;

	if (max_distance < 0.0f)
		max_distance = 20.0f;
	if (min_brightness < 0.2f)
		min_brightness = 0.2f;
	brightness = 1.0 / (distance / max_distance + 1.0);
	brightness = brightness * brightness;
	if (brightness < min_brightness)
		brightness = min_brightness;
	return (brightness);
}

// The ugly int array inside is my way of addressing too many arguments issue 
// the components are as follows
// int			y; //i_a[0]
// int			d; //i_a[1]
// int			texture_x; //i_a[2]
// int			texture_y; //i_a[3]
// The normal version is commented out below

/**
 * Draws a vertical slice of a wall for the given column. Uses the raycasting
 * data to calculate the texture coordinates and fetches the pixel colors
 * from the texture. Maps these colors onto the screen using `mlx_put_pixel`.
 */
void	draw_wall(t_game *game, mlx_texture_t *texture, int column)
{
	int			i_a[4];
	uint32_t	color;
	uint8_t		*pixel;
	float		brightness;

	brightness = calculate_brightness(game->ray->wall_distance,
			game->max_distance, 0.2f);
	i_a[0] = game->ray->bottom_pixel;
	set_texture_x(game, texture, &i_a[2]);
	while (i_a[0] <= game->ray->top_pixel)
	{
		i_a[1] = i_a[0] * 2 - HEIGHT + game->ray->wall_height;
		i_a[3] = ((i_a[1] * texture->height) / game->ray->wall_height) / 2;
		if (i_a[3] < 0)
			i_a[3] = 0;
		if ((uint32_t)i_a[3] >= texture->height)
			i_a[3] = texture->height - 1;
		pixel = texture->pixels + (i_a[3] * texture->width + i_a[2])
			* texture->bytes_per_pixel;
		color = combiner_hex(pixel[0] * brightness, pixel[1]
				* brightness, pixel[2] * brightness, 255);
		mlx_put_pixel(game->img_ray, column, i_a[0], color);
		i_a[0]++;
	}
}

// void draw_wall(t_game *game, mlx_texture_t *texture, int column)
// {
//	 int i_a[4];
//	 uint32_t color;
//	 uint8_t *pixel;

//	 // Precompute the lighting factor based on the distance
//	 float distance = game->ray->wall_distance; 
// Assuming distance is stored in the ray struct
//	 float max_distance = 100.0f; // Define a maximum distance for lighting
//	 float lighting_factor = 1.0f - (distance / max_distance);
// 	lighting_factor = lighting_factor * lighting_factor;

//	 // Clamp lighting factor between 0 and 1
//	 if (lighting_factor < 0.0f)
//		 lighting_factor = 0.0f;
//	 else if (lighting_factor > 1.0f)
//		 lighting_factor = 1.0f;

//	 i_a[0] = game->ray->bottom_pixel;
//	 set_texture_x(game, texture, &i_a[2]);
//	 while (i_a[0] <= game->ray->top_pixel)
//	 {
//		 i_a[1] = i_a[0] * 2 - HEIGHT + game->ray->wall_height;
//		 i_a[3] = ((i_a[1] * texture->height) / game->ray->wall_height) / 2;
//		 if (i_a[3] < 0)
//			 i_a[3] = 0;
//		 if ((uint32_t)i_a[3] >= texture->height)
//			 i_a[3] = texture->height - 1;

//		 // Get the original pixel color
//		 pixel = texture->pixels + (i_a[3] * texture->width + i_a[2])
//					* texture->bytes_per_pixel;
//		 // Apply lighting to the RGB components
//		 uint32_t r = (uint32_t)(pixel[0] * lighting_factor);
//		 uint32_t g = (uint32_t)(pixel[1] * lighting_factor);
//		 uint32_t b = (uint32_t)(pixel[2] * lighting_factor);

//		 // Combine the modified color with alpha
//		 color = combiner_hex(r, g, b, 255);

//		 // Draw the pixel with the modified color
//		 mlx_put_pixel(game->img_ray, column, i_a[0], color);
//		 i_a[0]++;
//	 }
// }

// void	draw_wall(t_game *game, mlx_texture_t *texture, int column)
// {
// 	int			y;
// 	int			d;
// 	int			texture_x;
// 	int			texture_y;
// 	// int			i_a[4];
// 	uint32_t	color;
// 	uint8_t		*pixel;

// 	y = game->ray->bottom_pixel;
// 	set_texture_x(game,  texture, &texture_x);
// 	while (y <= game->ray->top_pixel)
// 	{
// 		d = y * 2 - HEIGHT + game->ray->wall_height;
// 		texture_y = ((d * texture->height) / game->ray->wall_height) / 2;
// 		if (texture_y < 0)
// 			texture_y = 0;
// 		if ((uint32_t)texture_y >= texture->height)
// 			texture_y = texture->height - 1;
// 		pixel = texture->pixels + (texture_y * texture->width + texture_x)
// 			* texture->bytes_per_pixel;
// 		color = combiner_hex(pixel[0], pixel[1], pixel[2], 255);
// 		mlx_put_pixel(game->img_ray, column, y, color);
// 		y++;
// 	}
// }
