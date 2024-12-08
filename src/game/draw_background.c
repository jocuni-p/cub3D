/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:19:53 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/26 13:06:56 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
 * Draws the screen background. Fills the upper half with the ceiling color.
 * Fills the lower half with the floor color.
 *
 * Parameters:
 *  - t_game *game: Game structure with image and color data.
 *
 * Implementation:
 *  - Loops through each pixel. Uses `mlx_put_pixel` to set colors.
 *  - Ceiling color: `game->parser.elem.c_color`.
 *  - Floor color: `game->parser.elem.f_color`.
 */

// void	draw_ceiling(t_game *game)
// {
// 	return ;
// }

// static void	draw_floor(t_game *game)
// {
// 	return ;
// }

void draw_background(t_game *game)
{
    int 	y;
    int 	x;
	// float	distance;
	// float	max_distance;
	float	brightness;

    y = 0;
    while (y < HEIGHT >> 1)
    {
        x = 0;
        while (x < WIDTH)
        {
			// distance = (float)(y);
            // Calculate lighting factor based on distance
            // max_distance = (float)(HEIGHT / 2);
            // brightness = 1.0f - ((float)y / max_distance);
			brightness = calculate_brightness((float) y, (float) (HEIGHT / 2),
							0.2f);
            // Make the effect more pronounced
            // brightness = brightness * brightness;
            // // Clamp lighting factor between 0 and 1
            // if (brightness < 0.0f)
            //     brightness = 0.0f;
            // else if (brightness > 1.0f)
            //     brightness = 1.0f;

            // Apply lighting to ceiling color
            uint32_t r = (uint32_t)(((game->parser.elem.c_color >> 24) & 0xFF) * (brightness));
            uint32_t g = (uint32_t)(((game->parser.elem.c_color >> 16) & 0xFF) * (brightness));
            uint32_t b = (uint32_t)(((game->parser.elem.c_color >> 8) & 0xFF) * (brightness));
            uint32_t color = combiner_hex(r, g, b, 255);

            mlx_put_pixel(game->img_back, x, y, color);
            x++;
        }
        y++;
    }
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            // Calculate lighting factor based on distance
            float distance = (float)(y - HEIGHT / 2);
            float max_distance = (float)(HEIGHT / 2);
            float brightness = 1.0f - (distance / max_distance);

            // Make the effect more pronounced
            brightness = brightness * brightness;

            // Clamp lighting factor between 0 and 1
            if (brightness < 0.0f)
                brightness = 0.0f;
            else if (brightness > 1.0f)
                brightness = 1.0f;

            // Apply lighting to floor color
            uint32_t r = (uint32_t)(((game->parser.elem.f_color >> 24) & 0xFF) * (1.0f - brightness));
            uint32_t g = (uint32_t)(((game->parser.elem.f_color >> 16) & 0xFF) * (1.0f - brightness));
            uint32_t b = (uint32_t)(((game->parser.elem.f_color >> 8) & 0xFF) * (1.0f - brightness));
            uint32_t color = combiner_hex(r, g, b, 255);

            mlx_put_pixel(game->img_back, x, y, color);
            x++;
        }
        y++;
    }
}

// void	draw_background(t_game *game)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (y < HEIGHT >> 1)
// 	{
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			mlx_put_pixel(game->img_back, x, y, game->parser.elem.c_color);
// 			x++;
// 		}
// 		y++;
// 	}
// 	while (y < HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			mlx_put_pixel(game->img_back, x, y, game->parser.elem.f_color);
// 			x++;
// 		}
// 		y++;
// 	}
// }
