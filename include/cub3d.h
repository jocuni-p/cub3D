/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:01 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/17 17:01:46 by jocuni-p         ###   ########.fr       */
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
	char	*no;//pointer to the texture .xpm
	int		no_qty;
	char	*so;
	int		so_qty;
	char	*we;
	int		we_qty;
	char	*ea;
	int		ea_qty;
	char	*c;//pointer to the ceiling color
	int		c_qty;
	char	*f;
	int		f_qty;
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

/*-------------lists management--------------*/

t_cub	*lst_newnode(char *str);
t_cub	*lstlast(t_cub *lst);
void	lstadd_back(t_cub **lst, t_cub *new);
//void	lst_delone(t_cub **lst, char **node_to_del, void (*del)(void*));
void	handle_error(char *str, t_parser *parser);
void	print_cub_list(t_cub *lst);

#endif