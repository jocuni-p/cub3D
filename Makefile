#Basic Makefile sample as a starting point from MLX42 repo


NAME	:= cub3D
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g #-fsanitize=address #-fsanitize=leak
# Si uso fsanitize en las flags de compilado, debo ponerla tambien en las del enlazado, sino da error al compilar
LDFLAGS	:= #-fsanitize=address
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft/
LIBFT_A	:= $(LIBFT)libft.a 
HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)

# To compile the mlx on Linux at 42Barcelona campus   
ifeq ($(UNAME), Linux)
	LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm #-g -fsanitize=address

# To compile the mlx on MacOS
else ifeq ($(UNAME), Darwin)
	LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -L/opt/homebrew/lib -lglfw -pthread -lm #-g -fsanitize=address
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
					./src/parser/init_parser.c \
					./src/parser/parse_cub.c \
					./src/parser/parse_elements.c \
					./src/parser/parse_map_1.c \
					./src/parser/parse_map_2.c \
					./src/parser/arr2d_creator.c \
					./src/parser/parser_free.c
					
# Source files about print_tests
SRCS_PRINT_TESTS := ./src/print_tests/arr2d_print.c \
					./src/print_tests/print_cub_list.c \
					./src/print_tests/print_elem.c \
					./src/print_tests/print_map_list.c \
					./src/print_tests/print_game_struct.c

# Source files about utils
SRCS_UTILS := 		./src/utils/arr2d_element_cnt.c \
					./src/utils/arr2d_free.c \
					./src/utils/check_arg.c \
					./src/utils/elem_free.c \
					./src/utils/remove_nl.c

# Source files about graphic part
SRCS_GAME :=		./src/game/init_game.c


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
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LDFLAGS) -o $(NAME)
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
