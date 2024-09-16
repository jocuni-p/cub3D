# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 11:26:53 by jocuni-p          #+#    #+#              #
#    Updated: 2024/09/16 17:25:16 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile sample from MLX42 repo




NAME	:= cub3D
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft/


HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
#SRCS	:= $(shell find ./src -iname "*.c") NOT allowed wildcards in 42
SRCS	:= 	main.c handle_error.c\
			check_file_ext.c init_parser.c\
			inputfile_to_list.c parse_cub.c\
			print_cub_list.c
			
OBJS	:= ${SRCS:.c=.o}
#------------anyadido mio----------------------
LIBFT_A	:= $(LIBFT)libft.a 
LIBS += -L$(LIBFT) -lft
#---------------------------------------


all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	
#----anyadido mio - construyo la libft------
libft: 
	@$(MAKE) -C $(LIBFT)
#------------------------------

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
#	@rm -rf $(LIBFT_A)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx