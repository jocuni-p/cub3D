NAME = cub3D

NAME_B = cub3D_bonus

OBJ_PATH = tmp/

OBJ_PATH_B = tmp_b/

INC = inc/

INC_B = bonus/inc/

SRC_PATH = src/

SRC_PATH_B = bonus/src/

LIBFT_PATH = src/libft/

SRC = main.c \
		parsing/parsing.c parsing/load_map.c parsing/load_arg.c \
		parsing/check_wall.c \
		tools/tools.c tools/c3d_free.c  \
		tools/c3d_print.c \
		graphics/graphics.c graphics/math.c graphics/load_textures.c \
		graphics/draw_column.c graphics/player.c graphics/player_2.c \
		graphics/player_mov.c

SRC_B = main_bonus.c \
		parsing/parsing_bonus.c parsing/load_map_bonus.c parsing/load_arg_bonus.c \
		parsing/check_wall_bonus.c \
		tools/tools_bonus.c tools/c3d_free_bonus.c  \
		tools/c3d_print_bonus.c \
		graphics/graphics_bonus.c graphics/math_bonus.c graphics/load_textures_bonus.c \
		graphics/draw_column_bonus.c graphics/player_bonus.c graphics/player_2_bonus.c \
		graphics/player_mov_bonus.c graphics/minimap_bonus.c graphics/mouse_moves_bonus.c

SRC_PPREFIX = $(addprefix $(SRC_PATH),$(SRC))

SRC_PPREFIX_B = $(addprefix $(SRC_PATH_B),$(SRC_B))

OBJ = $(addprefix $(OBJ_PATH),$(SRC_PPREFIX:.c=.o))

OBJ_B = $(addprefix $(OBJ_PATH_B),$(SRC_PPREFIX_B:.c=.o))

CFLAGS = -I $(INC) -I $(LIBFT_PATH) -Wall -Wextra -Werror -o3 #-g -fsanitize=address

CFLAGS_B = -I $(INC_B) -I $(LIBFT_PATH) -Wall -Wextra -Werror -o3 #-g -fsanitize=address

ifeq ($(shell uname), Darwin)
	CFLAGS += -D MAC_OS
	CFLAGS_B += -D MAC_OS
	MLX_PATH = mlx_mac/
	INCLUDES = -Imlx_mac
	MLX_FLAGS = -Lmlx_mac -lmlx -framework OpenGL -framework AppKit
	MLX_A = mlx_mac/libmlx.a 
#Pending to test on mac

else
	MLX_PATH = mlx_linux/
	INCLUDES = -I/usr/lib -Imlx_linux
	MLX_FLAGS = -Lmlx_linux -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
	MLX_A = mlx_linux/libmlx_Linux.a mlx_linux/libmlx.a 
endif



#############################################################################

# Regular Colors
BLACK := \033[0;30m
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN := \033[0;36m
WHITE := \033[0;37m

# Reset
RESET := \033[0m

#############################################################################

all: tmp libraries $(NAME)

bonus: tmp_b libraries $(NAME_B)

tmp:
	@mkdir -p $(OBJ_PATH)

tmp_b:
	@mkdir -p $(OBJ_PATH_B)

$(NAME): $(OBJ)	libraries $(MLX_A)
	@gcc $(CFLAGS) $(OBJ) $(LIBFT_PATH)libft.a $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)cub3D compiled$(RESET)"

$(NAME_B): $(OBJ_B)	libraries $(MLX_A)
	@gcc $(CFLAGS_B) $(OBJ_B) $(LIBFT_PATH)libft.a $(MLX_FLAGS) -o $(NAME_B)
	@echo "$(GREEN)cub3D$(RESET)_$(RED)bonus $(GREEN)compiled$(RESET)"

libraries:
	@echo "$(CYAN)Compiling libraries$(RESET)"
	@echo "$(YELLOW)Libft $(RED)- $(GREEN)Compiling Libft$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) bonus --no-print-directory
	@echo "$(YELLOW)MLX $(RED)- $(GREEN)Compiling MLX$(RESET)"
	@$(MAKE) -C $(MLX_PATH) --no-print-directory
	@echo "$(GREEN)Libraries compiled$(RESET)"

$(OBJ_PATH)%.o:%.c Makefile $(LIBFT_PATH)libft.h $(INC)cub3D.h $(LIBFT_PATH)libft.a $(MLX_A)
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(CYAN)Compiling cub3D:$(YELLOW) $@$(RESET)"

$(OBJ_PATH_B)%.o:%.c Makefile $(LIBFT_PATH)libft.h $(INC_B)cub3D_bonus.h $(LIBFT_PATH)libft.a $(MLX_A)
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS_B) $(INCLUDES) -c $< -o $@
	@echo "$(CYAN)Compiling cub3D_bonus:$(YELLOW) $@$(RESET)"

re: fclean all

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean --no-print-directory
	@echo "$(CYAN)Libft $(YELLOW)- $(RED)Obj deleted$(RESET)"
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJ_PATH_B)
	@echo "$(CYAN)cub3D $(YELLOW)- $(RED)Obj deleted$(RESET)"
	@$(MAKE) -C $(MLX_PATH) clean --no-print-directory
	@echo "$(CYAN)Minilibx $(RED)deleted$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean --no-print-directory
	@echo "$(CYAN)Libft $(RED)deleted$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(NAME_B)
	@echo "$(CYAN)cub3D $(RED)deleted$(RESET)"

norm:
	@echo "$(CYAN)Norminette $(GREEN)$(INC)$(RESET)"
	norminette $(INC)
	@echo "$(CYAN)Norminette $(GREEN)$(SRC_PPREFIX)$(RESET)"
	norminette $(SRC_PPREFIX)

norm_bonus:
	@echo "$(CYAN)Norminette $(GREEN)$(INC_B)$(RESET)"
	norminette $(INC_B)
	@echo "$(CYAN)Norminette $(GREEN)$(SRC_PPREFIX_B)$(RESET)"
	norminette $(SRC_PPREFIX_B)

.PHONY: all bonus re clean fclean norm norm_bonus
