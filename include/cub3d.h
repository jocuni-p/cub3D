/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:01 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/25 19:57:10 by jocuni-p         ###   ########.fr       */
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


/*-----------------------------------------------------*/

# define WIDTH 1000
# define HEIGHT 500
# define TILE_SIZE 10


/*-----List containing all lines from filename.cub------*/
typedef struct s_cub
{
	char			*str;
	struct s_cub	*next;
}					t_cub;

/*-----Value of the elements----*/
typedef struct s_elem
{
	char		*no;//path to the texture(.xpm)
	char		*so;
	char		*we;
	char		*ea;
	char		*c;//color data before parse
	uint32_t	rgb_c[3];//rgb color values
	uint32_t	c_color;//color value converted to hexadecimal
	uint32_t	c_opposite;
	char		*f;
	uint32_t	rgb_f[3];
	uint32_t	f_color;
}				t_elem;

/*-----Map size and player------*/
typedef struct s_map
{
	int	w;
	int	h;
	int	ply_qty;
	int	ply_view;
	int	ply_x;
	int	ply_y;
}		t_map;

/*-------Parsing variables-------*/
typedef struct s_parser
{
	t_cub	*cub;//List containing every line from file.cub
	t_cub	*cub_ln0;
	t_cub	*map_ln0;//points to the first line after the elements
	t_elem	elem;
	t_map	map;//map infos
	char	**raw_map;//map before to be parsed
}			t_parser;


typedef struct s_game//It will be passed to the graphic part of cu3D
{
	t_parser	parser;
	char		**map_arr;//already parsed and formated to rectangular shape
	int			map_w;
	int			map_h;
	int			p_x;
	int			p_y;
	char		p_view;
	mlx_t		*mlx;
	mlx_image_t	*img_back;
	mlx_image_t	*img_ray;
	mlx_image_t	*img_mmap;
}			t_game;



/*-------------parse management--------------*/

int			check_arg_name(char *str);
int			check_arg_ext(char *str);
//void		init_game(t_game *game);
int			lst_creator(t_parser *parser, char *filename);
int			parse_cub(t_game *game, char *filename);
int			parse_elements(t_parser *parser);
int			check_element_chars(char *str);
int			set_element(t_parser *parser, char **elements);
int			parse_color(t_parser *parser, char *str, char c);
int			set_f(t_parser *parser, char *rgb_canal, int i);
int			set_c(t_parser *parser, char *rgb_canal, int i);
uint32_t	combiner_to_hexcolorformat(uint32_t r, uint32_t g, uint32_t b, uint32_t alpha);
int			flag_elem(t_parser *parser);
int			parse_map_1(t_parser *parser);
int			is_firstline_valid(char *str);
int			is_first_and_last_char_valid(char *str);
int			is_middle_char_valid(char *str, t_parser *parser);
int			is_map_properly_closed(t_parser *parser);
int			parse_map_2(t_parser *parser);
int 		arr2d_size(t_parser *parser);
int 		arr2d_filler(t_parser *parser);
int			arr2d_creator(t_parser *parser);
void		get_player_pos(t_parser *parser, int x, int y);
	
/*-------------lists management--------------*/

t_cub	*lst_newnode(char *str);
t_cub	*lstlast(t_cub *lst);
void	lstadd_back(t_cub **lst, t_cub *new);
void	print_error(char *str);
int		lst_size(t_cub *lst);
void 	lst_clear(t_cub **lst);

/*----------------------utils---------------------*/

int		arr2d_element_cnt(char **arr);
void	arr2d_free(char ***arr);
int		check_arg(char *str);
void	elem_free(t_game *game);
void	remove_nl(char *str);
int		get_opposite_color(t_parser *parser);
void	game_free(t_game *game);

/*-------------------------Game-------------------*/

int		start_game(t_game *game);
int		init_game(mlx_t *mlx, t_game *game);
void 	draw_img_background(t_game *game);
void	draw_img_minimap(t_game *game);
void 	draw_minimap_tile(mlx_image_t *img_mmap, uint32_t x, uint32_t y, uint32_t color);
void	draw_minimap_player(mlx_image_t *img_mmap, uint32_t x, uint32_t y, uint32_t color);
void	draw_minimap_frame(mlx_image_t *img_mmap, uint32_t x, uint32_t y, uint32_t color);
void 	error(void);//not 100% sure ???
void	updater(void *param);


/*---------TEMPORAL - Prints for testing----------*/

void	print_cub_list(t_cub *lst);
void	arr2d_print(char **arr2d);
void	print_elem(t_parser *parser);
void	print_map_list(t_cub *lst);
void	print_game_struct(t_game *game);
void	print_elem_and_color(t_parser *parser);


#endif