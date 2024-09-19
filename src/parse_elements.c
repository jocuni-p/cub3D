/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:34:56 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/09/19 16:53:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_elements(t_parser *parser)
{
	t_cub 	*aux;
	char	**element_line;
	
	aux = parser->cub;
	while(aux)
	{
		remove_nl(aux->str);
//		if (ft_strchr(aux->str, '\t'))//if a tab is found the program finishes
		if (check_valid_chars(aux->str))
			return (handle_error(ERR_FILE, parser_free(parser)), 1);
		
//		if (!aux->str)//la linea esta vacia
//		eliminar el nodo quizas no hace falta, basta con saltarlo si esta vacio
//		trimmed_line = ft_strtrim(aux->str, " ");//returns a new malloced str
//		free(aux->str);
//		aux->str = trimmed_line;	

		element_line = ft_split(aux->str, ' ');//retorna un char ** con 2 elementos mallocados
		if (la len de element_line != 2)//check if the array contains only 2 elements
			return (handle_error(ERR_FILE, parser_free(parser)), 1);
			
		if ((ft_strcmp(element_line[0], "NO") == 0) && parser->elem.no == NULL)
				parser->elem.no = element_line[0];				
		else if ((ft_strcmp(element_line[0], "SO") == 0) && parser->elem.so == NULL)
				parser->elem.so = element_line[0];				
		else if ((ft_strcmp(element_line[0], "WE") == 0) && parser->elem.we == NULL)
				parser->elem.we = element_line[0];
		else if ((ft_strcmp(element_line[0], "EA") == 0) && parser->elem.ea == NULL)
				parser->elem.ea = element_line[0];
		else if ((ft_strcmp(element_line[0], "C") == 0) && parser->elem.c == NULL)
				parser->elem.c = element_line[0];
		else if ((ft_strcmp(element_line[0], "F") == 0) && parser->elem.no == NULL)
				parser->elem.f = element_line[0];
		else
			//en el return he de liberar element_line el contenedor
			return (handle_error(ERR_FILE, parser_free(parser)), 1);//OJO liberar el contenedor arr2d 'element_line'

		
//----------------------Ejemplo de uso de split
//Copies the entire 'char **envp' into a new malloced 't_env' list*/
void	env_init_list(char **envp, t_env **envlist)
{
	int		i;
	char	**tokens;
	char	*key;
	char	*value;

	i = 0;
	while (envp[i])
	{
		tokens = ft_split(envp[i], '=');
		if (tokens != NULL && tokens[0] != NULL && tokens[1] != NULL)
		{
			key = tokens[0];
			value = tokens[1];
			lstadd_back(envlist, lstnew(key, value));
		}
		free_arr2d(tokens);
		i++;
	}
	return ;
}
//----------------------------
			
		printf("%i\n", aux1->content);//ELIMINAR
		else
		aux = aux->next;
	}
	
}
/*
while(line)
v   si [0] es \n -> remove node -> continue
v	remove the '\n' 
v   si hay algun ´tab' en la linea -> exit
v    clean spaces on the beginning and at the end with strtrim
    while(str[i] != ´\0´), 
    	if (str[0] == N && str[1] == O && str[2] == _   )
                   str + 3
                 
      		if (no_qty == 0) set whit 1 else ->exit
      		get the path
              set his var in the struct with the value
		if (str[i] == F && str[i+1] == _ && C_)
      get the color
else-> exit
*/
