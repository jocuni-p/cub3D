# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 17:23:07 by jocuni-p          #+#    #+#              #
#    Updated: 2024/10/27 20:02:06 by jocuni-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MacOS compilation: gcc main.c ... libmlx42.a -Iinclude -lglfw
# Linux compilation: gcc main.c ... libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

# For MacOS you need to use the following flags to compile your program with the
# library in order to link the program with the correct frameworks:
# -framework Cocoa -framework OpenGL -framework IOKit


NAME	:= cub3D
UNAME := $(shell uname)#gets the OS we are using (Mac or Linux)
#CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g #-fsanitize=address

# For MacOS (Apple Silicon) platforms
#CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -g -arch arm64 #-fsanitize=address

# Si uso fsanitize en las flags de compilado, debo ponerla tambien en las del enlazado, sino da error al compilar
LDFLAGS	:= #-fsanitize=address #(only on MacOS systems)
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft/
LIBFT_A	:= $(LIBFT)libft.a 
HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)

# To compile the mlx on Linux at 42Barcelona campus   
ifeq ($(UNAME), Linux)
	LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -g #-fsanitize=address
	CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g #-fsanitize=address
# To compile the mlx on MacOS (Apple Silicon)
else ifeq ($(UNAME), Darwin)
	LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -L/opt/homebrew/lib -lglfw -pthread -lm #-g -fsanitize=address
	CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -g -arch arm64 #-fsanitize=address
else
    $(Error. Unsupported platform: $(UNAME))
endif

ifeq ($(UNAME), Darwin)
    LIBS := $(LIBMLX)/build/libmlx42.a -ldl -L$(shell brew --prefix glfw)/lib -lglfw -pthread -lm
endif



LIBS += -L$(LIBFT) -lft

# Source files about lists
SRCS_LST :=         ./src/lst/lst_creator.c \
					./src/lst/lst_newnode.c \
					./src/lst/lst_size.c \
					./src/lst/lstadd_back.c \
					./src/lst/lstlast.c \
					./src/lst/lst_clear.c

# Source files about parsing
SRCS_PARSER :=		./src/parser/parse_color.c \
			 		./src/parser/print_error.c \
					./src/parser/parse_cub.c \
					./src/parser/parse_elements.c \
					./src/parser/parse_map_1.c \
					./src/parser/parse_map_2.c \
					./src/parser/arr2d_creator.c \
					
# Source files about print_tests
SRCS_PRINT_TESTS := ./src/print_tests/arr2d_print.c \
					./src/print_tests/print_cub_list.c \
					./src/print_tests/print_vars.c \
					./src/print_tests/print_map_list.c \
					./src/print_tests/print_game_struct.c \
					./src/print_tests/print_minimap_vars.c

# Source files about utils
SRCS_UTILS := 		./src/utils/arr2d_element_cnt.c \
					./src/utils/arr2d_free.c \
					./src/utils/check_arg.c \
					./src/utils/elem_free.c \
					./src/utils/remove_nl.c \
					./src/utils/get_opposite_color.c \
					./src/utils/game_free.c

# Source files about graphic part
SRCS_GAME :=		./src/game/draw_background.c \
					./src/game/draw_minimap.c \
					./src/game/init_game.c \
					./src/game/start_game.c \
					./src/game/loop_updater.c \
					./src/game/movement.c



# Puts together all src files
SRCS := ./src/main.c $(SRCS_LST) $(SRCS_PARSER) $(SRCS_PRINT_TESTS) $(SRCS_UTILS) $(SRCS_GAME)

# Object files
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
	@$(CC) $(OBJS) $(HEADERS) -o $(NAME) $(LIBS) $(LDFLAGS)
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