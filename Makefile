# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 17:23:07 by jocuni-p          #+#    #+#              #
#    Updated: 2024/09/29 19:27:33 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# para compilar el programa desde MacOS: gcc main.c ... libmlx42.a -Iinclude -lglfw
# para compilar el programa desde Linux: gcc main.c ... libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

# For MacOS you need to use the following flags to compile your program with the
# library in order to link the program with the correct frameworks:
# -framework Cocoa -framework OpenGL -framework IOKit


NAME	:= cub3D
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g #-fsanitize=address
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft/
LIBFT_A	:= $(LIBFT)libft.a 
HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)

ifeq ($(UNAME), Linux)
# To compile the mlx on Linux at 42Barcelona campus   
	LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

else ifeq ($(UNAME), Darwin)
# To compile the mlx on MacOS
	LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -L/opt/homebrew/lib -lglfw -pthread -lm
endif

LIBS += -L$(LIBFT) -lft

# Source files from subdir .src/lst
SRCS_LST :=         ./src/lst/inputfile_to_list.c \
					./src/lst/lst_newnode.c \
					./src/lst/lstadd_back.c \
					./src/lst/lstlast.c

# Archivos fuente del directorio ./src
SRCS_PARSER := 		./src/parser/check_element_chars.c \
					./src/parser/handle_error.c \
					./src/parser/parse_color.c \
					./src/parser/parse_cub.c \
					./src/parser/parse_elements.c \
					./src/parser/remove_nl.c \
					./src/parser/set_element.c
					
# Archivos fuente del subdirectorio ./src/print_tests
SRCS_PRINT_TESTS := ./src/print_tests/arr2d_print.c \
					./src/print_tests/print_cub_list.c \
					./src/print_tests/print_elem.c

SRCS_UTILS := 		./src/utils/arr2d_element_cnt.c \
					./src/utils/arr2d_free.c \
					./src/utils/check_arg.c \
					./src/utils/check_file_ext.c \
		            ./src/utils/check_file_name.c 

# Source files from subdir .src/game
SRCS_GAME :=


# Concatenar todos los archivos fuente
SRCS := ./src/main.c $(SRCS_LST) $(SRCS_PARSER) $(SRCS_PRINT_TESTS) $(SRCS_UTILS)

# Archivos objeto
OBJS := $(SRCS:.c=.o)

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

# Regla para compilar cualquier archivo .c en los subdirectorios
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