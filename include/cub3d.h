/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:01 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/10 16:31:10 by jocuni-p         ###   ########.fr       */
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
//# define ERR_IMG "Error;\nImage not found\n"


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
	int			rgb_c[3];//rgb color values
	uint32_t	c_color;//color value converted to hexadecimal
	char		*f;
	int			rgb_f[3];
	uint32_t	f_color;
}				t_elem;

/*-----Map size and player------*/
typedef struct s_map
{
	int	w;
	int	h;
	int	player_qty;
	int	player_view;
	int	player_x;
	int	player_y;
}		t_map;

/*-------Parsing variables-------*/
typedef struct s_parser
{
	t_cub	*cub;//List containing every line from file.cub
	t_cub	*cub_firstline;
	t_cub	*map_firstline;//points to the first line after the elements
	t_elem	elem;
	t_map	map;//map infos
	char	**raw_map;//map before to be parsed
}			t_parser;


typedef struct s_data//It will be passed to the graphic part of cu3D
{
	char	**map;//already formated with rectangular shape
	int		p_x;
	int		p_y;
	char	p_view;
//	char	*no;
//	char	*so;
//	char	*ea;
//	char 	*we;
//	uint32_t	c_col;
//	uint32_t	f_col;	
}			t_game;



/*-------------parse management--------------*/

int		check_arg_name(char *str);
int		check_arg_ext(char *str);
void	init_parser(t_parser *parser);
int		lst_creator(t_parser *parser, char *filename);
int		parse_cub(t_parser *parser, char *filename);
int		parse_elements(t_parser *parser);
int		check_element_chars(char *str);
int		set_element(t_parser *parser, char **elements);
int		parse_color(t_parser *parser, char *str, char c);
int		set_f(t_parser *parser, char *rgb_canal, int i);
int		set_c(t_parser *parser, char *rgb_canal, int i);
int		encoder_to_hexcolorformat(int r, int g, int b, int alpha);
int		flag_elem(t_parser *parser);
int		parse_map_1(t_parser *parser);
int		is_firstline_valid(char *str);
int		is_first_and_last_char_valid(char *str);
int		is_middle_char_valid(char *str, t_parser *parser);
int		is_map_properly_closed(t_parser *parser);
int		parse_map_2(t_parser *parser);
void	parser_free(t_parser *parser);
void	elem_free(t_parser *parser);
int 	arr2d_size(t_parser *parser);
int 	arr2d_filler(t_parser *parser);
int		arr2d_creator(t_parser *parser);
void	get_player_pos(t_parser *parser, int x, int y);

/*-------------lists management--------------*/

t_cub	*lst_newnode(char *str);
t_cub	*lstlast(t_cub *lst);
void	lstadd_back(t_cub **lst, t_cub *new);
void	handle_error(char *str);
int		lst_size(t_cub *lst);
void 	lst_clear(t_cub **lst);

/*----------------------utils---------------------*/

int		arr2d_element_cnt(char **arr);
void	arr2d_free(char ***arr);
int		check_arg(char *str);
void	remove_nl(char *str);

/*-------------------------Game-------------------*/

void	init_game(t_game *game, t_parser *parser);







/*---------TEMPORAL - Prints for testing----------*/

void	print_cub_list(t_cub *lst);
void	arr2d_print(char **arr2d);
void	print_elem(t_parser *parser);
void	print_map_list(t_cub *lst);
void	print_game(t_game *game);



#endif