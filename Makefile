# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 11:26:53 by jocuni-p          #+#    #+#              #
#    Updated: 2024/09/17 17:10:17 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TO DO: 
#create a directory to put all .o files
#create diferent directories inside src to put every type of functions 



NAME	:= cub3D
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft/


HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
#SRCS	:= $(shell find ./src -iname "*.c") NOT allowed wildcards in 42
SRCS	:= 	./src/main.c \
			./src/check_arg.c \
			./src/check_file_ext.c \
            ./src/check_file_name.c \
			./src/handle_error.c \
			./src/init_parser.c \
            ./src/inputfile_to_list.c \
			./src/lst_newnode.c \
			./src/lstadd_back.c \
			./src/lstlast.c \
			./src/parse_cub.c \
            ./src/print_cub_list.c
			
OBJS	:= ${SRCS:.c=.o}

LIBFT_A	:= $(LIBFT)libft.a 
LIBS += -L$(LIBFT) -lft


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
#	@rm -rf $(LIBFT_A)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx