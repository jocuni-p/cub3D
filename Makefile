# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 11:26:53 by jocuni-p          #+#    #+#              #
#    Updated: 2024/10/11 17:20:28 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PENDING TO DO: 
#create a directory to contain all .o files
#create diferent subdirectories inside src to contain every part of the project 



NAME	:= cub3D
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g #-fsanitize=address
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft/
LIBFT_A	:= $(LIBFT)libft.a 

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBS += -L$(LIBFT) -lft

SRCS	:= 	#./src/file_name.c \
			#./src/file_name.c

OBJS	:= ${SRCS:.c=.o}


# Colors
################################################################################

DEF_COLOR =		\033[0;39m
DARK_YELLOW =	\033[38;5;143m
DARK_GREEN 	=	\033[1m\033[38;2;75;179;82m
GREEN 		=	\033[0;32m

<<<<<<< HEAD

=======
>>>>>>> 99f7258f561db33e0d72dbda14d27f8f79fe0fc0
# Rules
################################################################################

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@echo "$(DARK_GREEN)Built target libmlx42.a $(DEF_COLOR)"

libft: 
	@$(MAKE) -C $(LIBFT)

<<<<<<< HEAD
=======
# Regla para compilar cualquier archivo .c en los subdirectorios
>>>>>>> 99f7258f561db33e0d72dbda14d27f8f79fe0fc0
./src/%.o: ./src/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
<<<<<<< HEAD
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
=======
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LDFLAGS) -o $(NAME)
>>>>>>> 99f7258f561db33e0d72dbda14d27f8f79fe0fc0
	@echo "\n$(DARK_GREEN)▶  cub3D built completed!$(DEF_COLOR)\n"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
<<<<<<< HEAD
	@rm -rf $(LIBFT_A)
=======
#	@rm -rf $(LIBFT_A)
>>>>>>> 99f7258f561db33e0d72dbda14d27f8f79fe0fc0
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
