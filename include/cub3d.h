/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:01 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/26 18:17:07 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>// for ´open´
//# include <math.h>//check with Roman if it is needed

/*------------------Colors--------------------*/
# define RED "\033[1;31m"
# define DARK_RED "\033[0;31m"
# define RES "\033[0m"

/*-------------------Error messages--------------------*/

# define ERR_ARG "Invalid argument number\n"
# define ERR_ARG_NAME "Invalid argument name\n"
# define ERR_ARG_EX "Invalid argument extension\n"
# define ERR_FD "Error:\nInvalid file descriptor\n"
# define ERR_EMPTY_FILE "Error:\nArgument file is empty\n"
# define ERR_FILE "Error:\nInvalid file data\n"
# define ERR_ELEM "Error:\nInvalid elements data\n"
# define ERR_MAP "Error:\nInvalid map data\n"
# define ERR_MEMORY "Error:\n Memory failure\n"
# define ERR_IMG "Error;\nImage not found\n"
# define ERR_GRAPH "Error;\nGraphic failure\n"


/*-------------------macros----------------------------*/
# define WIDTH 1000
# define HEIGHT 500
# define TILE_SIZE 10


/*-----List containing all lines from filename.cub------*/
typedef struct s_cub
{
	char			*str;
	struct s_cub	*next;
}					t_cub;

/*-----Elements value----*/
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

/*-------Parsing vars-------*/
typedef struct s_parser
{
	t_cub			*cub;//List containing every line from file.cub
	t_cub			*cub_ln0;//pointer to the first line of filename.cub
	t_cub			*map_ln0;//points to the first line after the elements
	t_elem			elem;
	int				ply_qty;//
}					t_parser;

/*---------minimap----------*/
typedef struct s_mmap
{
	uint32_t		x;
	uint32_t		y;
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
}					t_mmap;

/*------------Game vars----------*/
typedef struct s_game//It will be passed to the graphic part of cu3D
{
	t_parser		parser;
	char			**map_arr;//already parsed and formated to rectangular shape
	int				map_w;
	int				map_h;
	int				pl_orig[2];//player starting pos in map_array( [0] = x, [1] = y)
	int				pl_curr[2];//player current pos in map_arr
	char			pl_view;
	mlx_t			*mlx;
	mlx_image_t		*img_back;
	mlx_image_t		*img_ray;
	mlx_image_t		*img_mmap;
	t_mmap			mmap;
}					t_game;


/*-------------parse management--------------*/

int			check_arg_name(char *str);
int			check_arg_ext(char *str);
int			lst_creator(t_parser *parser, char *filename);
int			parse_cub(t_game *game, char *filename);
int			parse_elements(t_game * game);
int			check_element_chars(char *str);
int			set_element(t_game * game, char **elements);
int			parse_color(t_game * game, char *str, char c);
int			set_f(t_game * game, char *rgb_canal, int i);
int			set_c(t_game * game, char *rgb_canal, int i);
uint32_t	combiner_hex(uint32_t r, uint32_t g, uint32_t b, uint32_t alpha);
int			flag_elem(t_game * game);
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

/*----------------------utils---------------------*/

int			arr2d_element_cnt(char **arr);
void		arr2d_free(char ***arr);
int			check_arg(char *str);
void		elem_free(t_game *game);
void		remove_nl(char *str);
int			get_opposite_color(t_game * game);
void		game_free(t_game *game);

/*-------------------------Game-------------------*/

int			start_game(t_game *game);
int			init_game(mlx_t *mlx, t_game *game);
void 		draw_background(t_game *game);
void		draw_minimap(t_game *game);
void 		draw_minimap_tile(mlx_image_t *img_mmap, uint32_t x, uint32_t y, uint32_t color);
void		draw_minimap_player(mlx_image_t *img_mmap, uint32_t x, uint32_t y, uint32_t color);
void		draw_minimap_frame(mlx_image_t *img_mmap, uint32_t x, uint32_t y, uint32_t color);
void 		error(void);//not 100% sure ???
void		updater(void *param);


/*---------TEMPORAL - Prints for testing----------*/

void		print_cub_list(t_cub *lst);
void		arr2d_print(char **arr2d);
void		print_map_list(t_cub *lst);
void		print_game_struct(t_game *game);
void		print_variables(t_game *game);
void		print_minimap_vars(t_game *game);


#endif