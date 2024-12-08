# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzhdanov <rzhdanov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 17:23:07 by jocuni-p          #+#    #+#              #
#    Updated: 2024/12/03 01:03:05 by rzhdanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3D
UNAME := $(shell uname)#gets the OS we are using

LDFLAGS	:= -fsanitize=address #(only on MacOS systems)
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft/
LIBFT_A	:= $(LIBFT)libft.a 
HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)

# To compile on Linux at 42Barcelona campus   
ifeq ($(UNAME), Linux)
	LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -g -fsanitize=address
	CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g -fsanitize=address
	
# To compile on MacOS (Apple Silicon)
else ifeq ($(UNAME), Darwin)
	LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -L/opt/homebrew/lib -lglfw -pthread -lm -g -fsanitize=address
	CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -g -arch arm64 -fsanitize=address
else
    $(Error. Unsupported platform: $(UNAME))
endif

LIBS += -L$(LIBFT) -lft

SRCS_LST :=         ./src/lst/lst_creator.c \
					./src/lst/lst_newnode.c \
					./src/lst/lst_size.c \
					./src/lst/lstadd_back.c \
					./src/lst/lstlast.c \
					./src/lst/lst_clear.c

SRCS_PARSER :=		./src/parser/parse_color.c \
			 		./src/parser/print_error.c \
					./src/parser/parse_cub.c \
					./src/parser/parse_elements.c \
					./src/parser/parse_map_1.c \
					./src/parser/parse_map_2.c \
					./src/parser/arr2d_creator.c \
					
SRCS_PRINT_TESTS := ./src/print_tests/arr2d_print.c \
					./src/print_tests/print_cub_list.c \
					./src/print_tests/print_elements.c \
					./src/print_tests/print_map_list.c \
					./src/print_tests/print_game_info.c \
					./src/print_tests/print_minimap_vars.c

SRCS_UTILS := 		./src/utils/arr2d_element_cnt.c \
					./src/utils/arr2d_free.c \
					./src/utils/check_arg.c \
					./src/utils/elem_free.c \
					./src/utils/error_mlx.c \
					./src/utils/remove_nl.c \
					./src/utils/get_opposite_color.c \
					./src/utils/game_free.c \
					./src/utils/textures_free.c

SRCS_GAME :=		./src/game/draw_background.c \
					./src/game/start_game.c \
					./src/game/loop_updater.c \
					./src/game/movement.c \
					./src/game/reset_player_direction.c \
					./src/game/movement_utils_0.c \
					./src/game/movement_utils_1.c \
					./src/game/movement_mouse.c

SRCS_MINIMAP :=		./src/minimap/draw_minimap.c \
					./src/minimap/draw_minimap_player.c

SRCS_RAYCAST :=		./src/raycast/raycast.c \
					./src/raycast/raycast_utils.c \
					./src/raycast/draw_wall.c

# Puts together all src files
SRCS := ./src/main.c $(SRCS_LST) $(SRCS_PARSER) $(SRCS_PRINT_TESTS) $(SRCS_UTILS) $(SRCS_MINIMAP) $(SRCS_GAME) $(SRCS_RAYCAST)#$(SRCS_MINIMAP)

# Object files
OBJS := $(SRCS:.c=.o)

# Bonus files
BONUS_SRCS_LST :=         ./bonus/lst/lst_creator_bonus.c \
                          ./bonus/lst/lst_newnode_bonus.c \
                          ./bonus/lst/lst_size_bonus.c \
                          ./bonus/lst/lstadd_back_bonus.c \
                          ./bonus/lst/lstlast_bonus.c \
                          ./bonus/lst/lst_clear_bonus.c

BONUS_SRCS_PARSER :=      ./bonus/parser/parse_color_bonus.c \
                          ./bonus/parser/print_error_bonus.c \
                          ./bonus/parser/parse_cub_bonus.c \
                          ./bonus/parser/parse_elements_bonus.c \
                          ./bonus/parser/parse_map_1_bonus.c \
                          ./bonus/parser/parse_map_2_bonus.c \
                          ./bonus/parser/arr2d_creator_bonus.c \

BONUS_SRCS_PRINT_TESTS := ./bonus/print_tests/arr2d_print_bonus.c \
                          ./bonus/print_tests/print_cub_list_bonus.c \
                          ./bonus/print_tests/print_elements_bonus.c \
                          ./bonus/print_tests/print_map_list_bonus.c \
                          ./bonus/print_tests/print_game_info_bonus.c \
                          ./bonus/print_tests/print_minimap_vars_bonus.c

BONUS_SRCS_UTILS :=       ./bonus/utils/arr2d_element_cnt_bonus.c \
                          ./bonus/utils/arr2d_free_bonus.c \
                          ./bonus/utils/check_arg_bonus.c \
                          ./bonus/utils/elem_free_bonus.c \
                          ./bonus/utils/error_mlx_bonus.c \
                          ./bonus/utils/remove_nl_bonus.c \
                          ./bonus/utils/get_opposite_color_bonus.c \
                          ./bonus/utils/game_free_bonus.c \
                          ./bonus/utils/textures_free_bonus.c

BONUS_SRCS_GAME :=        ./bonus/game/draw_background_bonus.c \
                          ./bonus/game/start_game_bonus.c \
                          ./bonus/game/loop_updater_bonus.c \
                          ./bonus/game/movement_bonus.c \
                          ./bonus/game/reset_player_direction_bonus.c \
                          ./bonus/game/movement_utils_0_bonus.c \
                          ./bonus/game/movement_utils_1_bonus.c \
                          ./bonus/game/movement_mouse_bonus.c

BONUS_SRCS_MINIMAP :=     ./bonus/minimap/draw_minimap_bonus.c \
                          ./bonus/minimap/draw_minimap_player_bonus.c

BONUS_SRCS_RAYCAST :=     ./bonus/raycast/raycast_bonus.c \
                          ./bonus/raycast/raycast_utils_bonus.c \
                          ./bonus/raycast/draw_wall_bonus.c

BONUS_SRCS := ./bonus/main_bonus.c $(BONUS_SRCS_LST) $(BONUS_SRCS_PARSER) \
              $(BONUS_SRCS_PRINT_TESTS) $(BONUS_SRCS_UTILS) $(BONUS_SRCS_GAME) \
              $(BONUS_SRCS_MINIMAP) $(BONUS_SRCS_RAYCAST)

# Object files for bonus
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

# Colors definition
################################################################################

DEF_COLOR =		\033[0;39m
DEL_LINE	=	\033[2K
DARK_GREEN 	=	\033[1m\033[38;2;75;179;82m
ITALIC		=	\033[3m
BOLD		=	\033[1m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m
BLACK		=	\033[0;99m
ORANGE		=	\033[38;5;209m
BROWN		=	\033[38;2;184;143;29m
DARK_GRAY	=	\033[38;5;234m
MID_GRAY	=	\033[38;5;245m
DARK_GREEN	=	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m


# Rules
################################################################################

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@echo "$(DARK_GREEN)Built target libmlx42.a $(DEF_COLOR)"

libft: 
	@$(MAKE) -C $(LIBFT)


./src/%.o: ./src/%.c Makefile include/cub3d.h
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(LDFLAGS) $(OBJS) $(HEADERS) -o $(NAME) $(LIBS)
	@echo "\n$(DARK_GREEN)▶  cub3D built completed!$(DEF_COLOR)\n"

bonus: libmlx libft $(NAME)_bonus

./bonus/%.o: ./bonus/%.c Makefile include/cub3d_bonus.h
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling (bonus): $(notdir $<)\n"

$(NAME)_bonus: $(BONUS_OBJS)
	@$(CC) $(LDFLAGS) $(BONUS_OBJS) $(HEADERS) -o $(NAME)_bonus $(LIBS)
	@echo "\n$(DARK_GREEN)▶  cub3D bonus built completed!$(DEF_COLOR)\n"

clean:
	@rm -rf $(BONUS_OBJS)
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@rm -f $(LIBFT_A)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME)_bonus

re: clean all

norm:
	norminette $(SRCS) $(LIBFT) $(BONUS_SRCS) ./include

.PHONY: all, clean, fclean, re, libmlx, norm, bonus
