# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 16:15:05 by jocuni-p          #+#    #+#              #
#    Updated: 2024/06/08 17:26:10 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

#'ar' es una utilitat per crear i mantenir grups d'arxius combinats en un sol
#arxu i l'usarem  per crear la llibreria
#'r' la reeemplasara si existeix ja i la creara si no existeix
#'c' fa que es silencii el missatge de la creacio de ar
#'s' escriu un index d'arxius objecte a dins per el seu control intern
LIB = ar -rcs

#no inclou el .h perque el llegeix sense compilar-lo
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	  ft_isascii.c ft_isprint.c ft_strlen.c ft_tolower.c ft_toupper.c\
	  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memset.c ft_memchr.c ft_memcpy.c\
	  ft_memcmp.c ft_memmove.c ft_strlcpy.c ft_strnstr.c ft_strdup.c ft_strlcat.c\
	  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
	  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
	  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
	  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_printf.c\
	  get_next_line_utils.c get_next_line.c put_c.c put_hex.c put_i.c put_p.c\
	  put_s.c put_u.c sel_fmt.c ft_putnbr.c ft_strcmp.c ft_atol.c ft_ltoa.c


OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	@$(LIB) $(NAME) $(OBJ)
	@echo "Library $(NAME) created."


#%.o : %.c libft.h  Makefile libft.a
%.o : %.c libft.h  Makefile
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo "Compiled $< to $@."
#La var automatica $< agafa el nom del .c (src) i $@ el dona al .o (target)


clean:
	@rm -f *.o
	@echo "Cleaned up libft object files."
# amb -f ignorem els arxius que no existeixen, borrats ja previament

fclean: clean
	@rm -f $(NAME)
	@echo "Removed library $(NAME)."

re: fclean all


.PHONY: clean fclean re all bonus
