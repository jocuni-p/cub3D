/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:01 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/22 14:53:21 by jocuni-p         ###   ########.fr       */
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
# define ERR_MEMORY "Error:\n Memory failure\n"
//# define ERR_MAP "Error:\nInvalid map\n"
//# define ERR_IMG "Error;\nImage not found\n"

/*-----List containing all file.cub lines------*/
typedef struct s_cub
{
	char			*str;//each line from file.cub
	struct s_cub	*next;
}					t_cub;

typedef struct s_elem
{
	char	*no;//pointer to the texture(.xpm)
	char	*so;
	char	*we;
	char	*ea;
	char	*c;//pointer to the color
	char	*f;
}			t_elem;

typedef struct s_parser
{
	t_cub	*cub;//List containing every line from file.cub
	t_elem	elem;
	char	**raw_map;//original map before to be parsed
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

void	init_parser(t_parser *parser);
int		check_arg(char *str);
int		check_file_name(char *str);
int		check_file_ext(char *str);
int		inputfile_to_list(t_parser *parser, char *filename);
int		parse_cub(t_parser *parser, char *filename);
int		parse_elements(t_parser *parser);
void	remove_nl(char *str);
int		check_valid_chars(char *str);
int		set_element(t_parser *parser, char **elements);


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

/*------------my prints to test program behabior------------*/
void	print_cub_list(t_cub *lst);
void	arr2d_print(char **arr2d);

#endif