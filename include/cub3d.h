/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:01 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/12/03 01:14:47 by rzhdanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h> // for ´open´
# include <stdbool.h>
# include <math.h> //for 'cos' and 'sin'

/*------------------Colors--------------------*/
# define RED "\033[0;91m"
# define DARK_RED "\033[0;31m"
# define RES "\033[0m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define ORANGE "\033[38;5;209m"
# define DEF_COLOR "\033[0;39m"
# define TRANSPARENT 0x00000000
# define BLACK 0x000000FF

/*-------------------Error messages--------------------*/

# define ERR_ARG "Invalid argument number\n"
# define ERR_ARG_NAME "Invalid argument name\n"
# define ERR_ARG_EX "Invalid argument extension\n"
# define ERR_FD "Error\nInvalid file descriptor\n"
# define ERR_EMPTY_FILE "Error:\nArgument file is empty\n"
# define ERR_FILE "Error\nInvalid file data\n"
# define ERR_ELEM "Error\nInvalid elements data\n"
# define ERR_MAP "Error\nInvalid map data\n"
# define ERR_MEMORY "Error\n Memory failure\n"
# define ERR_IMG "Error\nImage not found\n"
# define ERR_GRAPH "Error\nGraphic failure\n"
# define ERR_PATH "Error\nPath/file to the texture is invalid\n"

/*-------------------game const params------------------*/
# define WIDTH 2000
# define HEIGHT 1000
# define MINIMAP_TILE_SIZE 15
# define SPEED 0.1f
# define ROTATION_SPEED 0.0005f

/*-----List containing all lines from filename.cub------*/
typedef struct s_cub
{
	char			*str;
	struct s_cub	*next;
}					t_cub;

/*-----Elements----*/
typedef struct s_elem
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*c;
	uint32_t		rgb_c[3];
	uint32_t		c_color;
	uint32_t		c_opposite;
	char			*f;
	uint32_t		rgb_f[3];
	uint32_t		f_color;
}					t_elem;

/*-------Parsing-------*/
typedef struct s_parser
{
	t_cub			*cub;
	t_cub			*cub_ln0;
	t_cub			*map_ln0;
	t_elem			elem;
	int				ply_qty;
}					t_parser;

/*Bresenham's algorithm for drawing lines on a pixel grid.*/
typedef struct s_bresenham
{
	int				x;
	int				y;
	int				end_x;
	int				end_y;
	int				d_x;
	int				d_y;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_bresenham;

/*---------minimap----------*/
typedef struct s_mmap
{
	uint32_t		x;
	uint32_t		y;
	int				row;
	int				col;
	int				map_offset_x;
	int				map_offset_y;
	int				start_col;
	int				end_col;
	int				start_row;
	int				end_row;
	uint32_t		pl_screen_x;
	uint32_t		pl_screen_y;
	t_bresenham		bres;
}					t_mmap;

typedef struct s_coord
{
	float			x;
	float			y;
}					t_coord;

/*------------player--------*/
typedef struct s_player
{
	t_coord			pos;
	t_coord			orig_pos;
	t_coord			dir;
	t_coord			orig_dir;
	t_coord			plane;
	char			orientation;
	float			speed;
	float			rotation_speed;
	bool			is_running;
}					t_player;

/*------------ray--------*/
typedef struct s_ray
{
	float	camera_offset;
	t_coord	direction;
	int		grid_x;
	int		grid_y;
	int		step_x;
	int		step_y;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	wall_distance;
	float	wall_hit_x;
	int		side;
	int		wall_height;
	int		bottom_pixel;
	int		top_pixel;
}	t_ray;

/*------------textures--------*/
typedef struct s_textures
{
	mlx_texture_t	*text_n;
	mlx_texture_t	*text_s;
	mlx_texture_t	*text_e;
	mlx_texture_t	*text_w;
	mlx_image_t		*img_n;
	mlx_image_t		*img_s;
	mlx_image_t		*img_e;
	mlx_image_t		*img_w;
}				t_textures;

/*------------game----------*/
typedef struct s_game
{
	t_parser		parser;
	char			**map_arr;
	int				map_w;
	int				map_h;
	float			sensitivity;
	t_player		player;	
	mlx_t			*mlx;
	mlx_image_t		*img_back;
	mlx_image_t		*img_ray;
	mlx_image_t		*img_mmap;
	t_mmap			mmap;
	t_textures		textures;
	bool			is_moving;
	t_ray			*ray;
}					t_game;

/*-------------parse management--------------*/

int			check_arg_name(char *str);
int			check_arg_ext(char *str);
int			lst_creator(t_parser *parser, char *filename);
int			parse_cub(t_game *game, char *filename);
int			parse_elements(t_game *game);
int			set_element(t_game *game, char **elements);
int			parse_color(t_game *game, char *str, char c);
int			set_f(t_game *game, char *rgb_canal, int i);
int			set_c(t_game *game, char *rgb_canal, int i);
uint32_t	combiner_hex(uint32_t r, uint32_t g, uint32_t b, uint32_t alpha);
int			check_setted_elements(t_game *game);
int			parse_map_1(t_game *game);
int			is_firstline_valid(char *str);
int			is_first_and_last_char_valid(char *str);
int			is_middle_char_valid(char *str, t_game *game);
int			is_map_properly_closed(t_game *game);
int			parse_map_2(t_game *game);
int			arr2d_size(t_game *game);
int			arr2d_filler(t_game *game);
int			arr2d_creator(t_game *game);
void		get_player_pos(t_game *game, int x, int y);

/*-------------lists management--------------*/

t_cub		*lst_newnode(char *str);
t_cub		*lstlast(t_cub *lst);
void		lstadd_back(t_cub **lst, t_cub *new);
void		print_error(char *str);
int			lst_size(t_cub *lst);
void		lst_clear(t_cub **lst);

/*-------------------utils-----------------*/

int			arr2d_element_cnt(char **arr);
void		arr2d_free(char ***arr);
int			check_arg(char *str);
void		elem_free(t_game *game);
void		remove_nl(char *str);
int			get_opposite_color(t_game *game);
void		parser_free(t_game *game);
void		game_free(t_game *game);
void		error_mlx(t_game *game);

/*--------------------Game-------------------*/

int			start_game(t_game *game);
int			init_game(t_game *game);
void		init_player_values(t_game *game);
void		reset_player_direction(t_game *game);
void		set_direction_north(t_game *game);
void		set_direction_south(t_game *game);
void		set_direction_east(t_game *game);
void		set_direction_west(t_game *game);
int			init_textures(t_game *game);
void		draw_background(t_game *game);
void		loop_updater(void *param);
void		event_listener(t_game *game);
void		clear_image(mlx_image_t *img, uint32_t color);
void		move(t_game *game, float dir_x, float dir_y, float move_speed);
void		rotate(t_game *game, float angle);
void		teleport_to_original_position(t_game *game);
void		process_movement(t_game *game);
void		try_to_move_forward(t_game *game);
void		try_to_move_backward(t_game *game);
void		try_to_strafe(t_game *game);
void		try_to_teleport(t_game *game);
void		try_to_rotate(t_game *game);
void		try_to_run(t_game *game);
void		sprint_on(t_game *game);
void		sprint_off(t_game *game);
void		rotate_with_mouse(t_game *game);
void		scroll_hook(double xoffset, double yoffset, void *param);
void		mouse_button_hook(mouse_key_t button, action_t action,
				modifier_key_t mods, void *param);

/*------------------Raycasting---------------*/

//functions from ./raycast.c
void		reset_ray_values(t_ray *ray);
void		ray_free(t_game *game);
void		prepare_drawing_info(t_game *game, int column);
void		initialize_raycast_info(int column, t_game *game);
void		configure_dda(t_game *game, t_ray *ray);
void		execute_dda(t_game *game, t_ray *ray);
void		compute_wall_intersections(t_game *game, t_ray *ray);
int			execute_raycasting(t_game *game);
void		draw_wall(t_game *game, mlx_texture_t *texture, int column);
void		render_frame(t_game *game);

/*------------------minimap------------------*/
void		draw_minimap(t_game *game);
void		draw_minimap_tile(mlx_image_t *img_mmap, uint32_t x,
				uint32_t y, uint32_t color);
void		draw_minimap_only_visible_tiles(t_game *game);
void		draw_minimap_frame(mlx_image_t *img_mmap, uint32_t x,
				uint32_t y, uint32_t color);
void		draw_minimap_player(t_game *game, uint32_t color);
void		draw_minimap_direction_line(t_game *game, uint32_t color);
void		set_bresenham_values(t_game *game);
void		update_bresenham_values(t_game *game);

/*--------------Textures---------------*/

int			init_textures(t_game *game);
void		textures_free(t_game *game);

/*---------- Prints for debug----------*/

//void		print_cub_list(t_cub *lst);
void		arr2d_print(char **arr2d);
//void		print_map_list(t_cub *lst);
void		print_game_info(t_game *game);
void		print_elements(t_game *game);
void		print_minimap_vars(t_game *game);
#endif
