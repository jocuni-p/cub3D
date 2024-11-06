/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:01 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/11/06 18:27:43 by jocuni-p         ###   ########.fr       */
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
# include <fcntl.h>// for ´open´
# include <stdbool.h>
# include <math.h>//for 'cos' and 'sin'

/*------------------Colors--------------------*/
# define RED "\033[0;91m"
# define DARK_RED "\033[0;31m"
# define RES "\033[0m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define ORANGE "\033[38;5;209m"
# define DEF_COLOR "\033[0;39m"
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
	char			*no;//path to the texture(.xpm)
	char			*so;
	char			*we;
	char			*ea;
	char			*c;//color data before parse
	uint32_t		rgb_c[3];//rgb color values
	uint32_t		c_color;//color value converted to hexadecimal
	uint32_t		c_opposite;
	char			*f;
	uint32_t		rgb_f[3];
	uint32_t		f_color;
}					t_elem;

/*-------Parsing-------*/
typedef struct s_parser
{
	t_cub			*cub;//List containing every line from file.cub
	t_cub			*cub_ln0;//pointer to the first line of filename.cub
	t_cub			*map_ln0;//points to the first line after the elements
	t_elem			elem;
	int				ply_qty;
}					t_parser;

/*---Bresenham's algorithm---*/
//Bresenham's algorithm for drawing lines on a pixel grid.
typedef struct s_bresenham
{
	int				x;//initial line's point 
	int				y;
	int				end_x;//final line's point
	int				end_y;
	int				d_x;//distance diference between axis x and y
	int				d_y;
	int				sx;//determine the increment direction to the final point
	int				sy;
	int				err;//helps to decide if move towards x or y
	int				e2;
}					t_bresenham;


/*---------minimap----------*/
typedef struct s_mmap
{
	uint32_t		x;//coor de tile del minimap
	uint32_t		y;//coor de tile del minimap
	int				row;
	int				col;
	int				map_offset_x;//Map shift to center minimap on the player
	int				map_offset_y;//Map shift to center minimap on the player
	int				start_col;//Limit of tiles that can be seen on the minimap
	int				end_col;//Limit of tiles that can be seen on the minimap
	int				start_row;//Limit of tiles that can be seen on the minimap
	int				end_row;//Limit of tiles that can be seen on the minimap
	uint32_t		pl_screen_x;// Player pos in minimap img center
	uint32_t		pl_screen_y;// Player pos in minimap img center
	t_bresenham		bres;//Bresenham's algorithm
}					t_mmap;

/*-------coordinates expressed in double type------*/
typedef struct s_coord
{
	float			x;
	float			y;
}					t_coord;

/*------------player--------*/
typedef struct s_player
{
	t_coord			pos;//(x,y) coordenada de donde esta ahora
	t_coord			dir;//(x,y) define el vector de direccion (donde mira)
	t_coord			plane;//determina la proyección lateral de la cámara y 
//							permite simular una vista en 3D
	char			orientation;//starting orientation: N, S, E, W
}					t_player;

/*------------game----------*/
typedef struct s_game//This will be passed to the raycast
{
	t_parser		parser;//parser data
	char			**map_arr;//map cells formated 
	int				map_w;//map size
	int				map_h;//map size
	t_player		player;	
	mlx_t			*mlx;//instance to MLX42 library
	mlx_image_t		*img_back;//instance of background image
	mlx_image_t		*img_ray;//instance to walls(raycasting) image
	mlx_image_t		*img_mmap;//instance to minimap image
	t_mmap			mmap;//minimap data
	bool			is_moving;
	
}					t_game;


/*-------------parse management--------------*/

int			check_arg_name(char *str);
int			check_arg_ext(char *str);
int			lst_creator(t_parser *parser, char *filename);
int			parse_cub(t_game *game, char *filename);
int			parse_elements(t_game * game);
//int			check_element_chars(char *str);
//int			check_element_path(t_game *game);
int			set_element(t_game * game, char **elements);
int			parse_color(t_game * game, char *str, char c);
int			set_f(t_game * game, char *rgb_canal, int i);
int			set_c(t_game * game, char *rgb_canal, int i);
uint32_t	combiner_hex(uint32_t r, uint32_t g, uint32_t b, uint32_t alpha);
int			check_setted_elements(t_game * game);
int			parse_map_1(t_game * game);
int			is_firstline_valid(char *str);
int			is_first_and_last_char_valid(char *str);
int			is_middle_char_valid(char *str, t_game * game);
int			is_map_properly_closed(t_game * game);
int			parse_map_2(t_game * game);
int 		arr2d_size(t_game * game);
int 		arr2d_filler(t_game * game);
int			arr2d_creator(t_game * game);
void		get_player_pos(t_game * game, int x, int y);
	
/*-------------lists management--------------*/

t_cub		*lst_newnode(char *str);
t_cub		*lstlast(t_cub *lst);
void		lstadd_back(t_cub **lst, t_cub *new);
void		print_error(char *str);
int			lst_size(t_cub *lst);
void 		lst_clear(t_cub **lst);

/*-------------------utils-----------------*/

int			arr2d_element_cnt(char **arr);
void		arr2d_free(char ***arr);
int			check_arg(char *str);
void		elem_free(t_game *game);
void		remove_nl(char *str);
int			get_opposite_color(t_game * game);
void		game_free(t_game *game);
void 		error_mlx(t_game *game);

/*--------------------Game-------------------*/

int			start_game(t_game *game);
int			init_game(mlx_t *mlx, t_game *game);
void 		draw_background(t_game *game);
void		loop_updater(void *param);
void		event_listener(t_game *game);
void		move(t_game *game, float dir_x, float dir_y, float move_speed);

/*------------------minimap------------------*/
void		draw_minimap(t_game *game);
void 		draw_minimap_tile(mlx_image_t *img_mmap, uint32_t x, uint32_t y, uint32_t color);
void		draw_minimap_only_visible_tiles(t_game *game);
void		draw_minimap_frame(mlx_image_t *img_mmap, uint32_t x, uint32_t y, uint32_t color);
//void		draw_minimap_player(t_game *game, uint32_t color);
void		draw_minimap_player(t_game *game, uint32_t color);
void		draw_minimap_direction_line(t_game *game, uint32_t color);
void		set_bresenham_values(t_game *game);

/*------------------Raycasting---------------*/

//void		draw_raycasting(t_game *game);



/*------------TEXTURES TEMPORAL TEST--------*/

int			textures_test(t_game *game);



/*---------- Prints for debug----------*/

void		print_cub_list(t_cub *lst);
void		arr2d_print(char **arr2d);
void		print_map_list(t_cub *lst);
void		print_game_info(t_game *game);
void		print_elements(t_game *game);
void		print_minimap_vars(t_game *game);


#endif