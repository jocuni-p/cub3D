/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:01 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/12 13:51:55 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"//is pendeng to fix (put gnl and ftprintf on their owns directories)
# include "../MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>// for ´open´
# include <math.h>//not sure if to be needed

/*-------------------Error messages--------------------*/

# define ERR_ARG "Invalid argument\n"
//# define ERR_FD "Error:\nInvalid fd\n"
# define ERR_EX "Error:\nInvalid extension\n"
//# define ERR_MAP "Error:\nInvalid map\n"
//# define ERR_FILE "Error:\nInvalid file data\n"
//# define ERR_IMG "Error;\nImage not found\n"

/*-----List containing all file.cub lines------*/
typedef struct s_cublst
{
	char			*str;//each line from file.cub
	struct s_cub	*next;
}					t_cub;

typedef struct s_elem
{
	char	*no;//pointer to the texture .xpm
	char	*so;
	char	*we;
	char	*ea;
	char	*c;//pointer to the ceiling color
	char	*f;
}			t_elem;

typedef struct s_parser
{
	t_cub	*cub;//List containing each line from file.cub
	t_elem	lem;
	char	**raw_map;//original map before to be parsed
	int		player_x;
	int		player_y;
	char	player_view;
}			t_parser;

typedef struct s_data//IN PROGRESS
{
	char	**map;//already formated with rectangular shape
	?
	?
	?
}			t_data;



/*-------------parse management--------------*/
void	init_parser(t_parser *parser);
int		check_file_ext(char *str);
t_cub	**inputfile_to_list(t_parser *parser, char *filename);

/*-------------lists management--------------*/
t_cub	*lst_newnode(char *str);
t_cub	*lstlast(t_cub *lst);
void	lstadd_back(t_cub **lst, t_cub *new);
void	lst_delone(t_cub **lst, char **node_to_del, void (*del)(void*));



#endif