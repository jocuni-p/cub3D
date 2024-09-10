/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:01 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/10 10:46:55 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"//is pendeng to fix (put gnl and ftprintf on their owns directories)
# include "../MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>//not sure if to be needed

/*-------------------Error messages--------------------*/

//# define ERR_FD "Error:\nInvalid fd :(\n"
//# define ERR_EX "Error:\nInvalid extension :(\n"
//# define ERR_MAP "Error:\nInvalid map :(\n"
//# define ERR_FILE "Error:\nInvalid file data :(\n"
//# define ERR_IMG "Error;\nImage not found :(\n"


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
	t_list	raw_input;//will contain all lines from .cub
	char	**raw_map;//original map before 
	int		player_x;
	int		player_y;
	char	player_view;
	t_elem	elements;
}			t_parser;

typedef struct s_data
{
	char	**map;//already formated


	
}			t_data;





#endif