# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 11:26:53 by jocuni-p          #+#    #+#              #
#    Updated: 2024/09/20 18:10:04 by jocuni-p         ###   ########.fr        #
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


SRCS	:=	./src/arr2d_element_cnt.c \
			./src/arr2d_free.c \
			./src/check_arg.c \
			./src/check_file_ext.c \
            ./src/check_file_name.c \
			./src/check_valid_chars.c \
			./src/handle_error.c \
			./src/init_parser.c \
            ./src/inputfile_to_list.c \
			./src/lst_newnode.c \
			./src/lstadd_back.c \
			./src/lstlast.c \
		 	./src/main.c \
			./src/parse_cub.c \
			./src/parse_elements.c \
            ./src/print_cub_list.c \
			./src/remove_nl.c \
			./src/set_element.c
			

OBJS	:= ${SRCS:.c=.o}

# Colors
################################################################################

DEF_COLOR =		\033[0;39m
DARK_YELLOW =	\033[38;5;143m
DARK_GREEN 	=	\033[1m\033[38;2;75;179;82m
GREEN 		=	\033[0;32m

# Rules
################################################################################

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@echo "$(DARK_GREEN)Built target libmlx42.a $(DEF_COLOR)"

libft: 
	@$(MAKE) -C $(LIBFT)

./src/%.o: ./src/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "\n$(DARK_GREEN)▶  cub3D built completed!$(DEF_COLOR)\n"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(LIBFT_A)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx