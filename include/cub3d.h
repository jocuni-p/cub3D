/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:01 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/10/03 12:36:14 by jocuni-p         ###   ########.fr       */
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
# include <math.h>//not sure if to be needed

/*-------------------Error messages--------------------*/

# define ERR_ARG "Invalid argument number\n"
# define ERR_ARG_NAME "Invalid argument name\n"
# define ERR_ARG_EX "Invalid argument extension\n"
# define ERR_FD "Error:\nInvalid file descriptor\n"
# define ERR_FILE "Error:\nInvalid file data\n"
# define ERR_ELEM "Error:\nInvalid file element data\n"
# define ERR_MAP "Error:\nInvalid file map data\n"
# define ERR_MEMORY "Error:\n Memory failure\n"
//# define ERR_IMG "Error;\nImage not found\n"

/*-----List containing all file.cub lines------*/
typedef struct s_cub
{
	char			*str;//each line from file.cub
	struct s_cub	*next;
}					t_cub;

typedef struct s_elem
{
	char		*no;//path to the texture(.xpm)
	char		*so;
	char		*we;
	char		*ea;
	char		*c;//color data before parse
	int			rgb_c[3];//rgb values, seteo inicial a -1
	uint32_t	c_color;//color value converted to hexadecimal
	char		*f;
	int			rgb_f[3];
	uint32_t	f_color;
}			t_elem;


typedef struct s_parser
{
	t_cub	*cub;//List containing every line from file.cub
	t_cub	*map_firstline;//points to the first line after the elements
	t_elem	elem;
	char	**raw_map;//map before to be parsed
//	int		player_x;
//	int		player_y;
//	char	player_view;
}			t_parser;

typedef struct s_data//IN PROGRESS-It will be passed to the graphic part of cu3D
{
	char	**map;//already formated with rectangular shape
	int		player_x;
	int		player_y;
	char	player_view;	
}			t_data;



/*-------------parse management--------------*/

//void	init_parser(t_parser *parser);
int		check_arg(char *str);
int		check_file_name(char *str);
int		check_file_ext(char *str);
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

/*-------------arrays management------------*/

int		arr2d_element_cnt(char **arr);
void	arr2d_free(char **arr);


/*-------------lists management--------------*/

t_cub	*lst_newnode(char *str);
t_cub	*lstlast(t_cub *lst);
void	lstadd_back(t_cub **lst, t_cub *new);
//void	lst_delone(t_cub **lst, char **node_to_del, void (*del)(void*));
//void	handle_error(char *str, t_parser *parser);
void	handle_error(char *str);
int		lst_size(t_cub *lst);


/*------------my prints to test program behabior------------*/

void	print_cub_list(t_cub *lst);
void	arr2d_print(char **arr2d);
void	print_elem(t_parser *parser);

/*----------------------utils---------------------*/

void	remove_nl(char *str);

#endif