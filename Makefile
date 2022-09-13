CC = clang
FLAGS = -Wall -Wextra -Werror -g
SRC =   src/cube3d.c \
        src/parsing/floor/read_floor.c \
        src/parsing/textures/read_textures.c \
        src/parsing/textures/init_textures.c \
        src/parsing/ceiling/read_ceiling.c \
        src/parsing/map/read_map.c \
		src/parsing/map/valid_map.c \
		src/parsing/map/valid_map_2.c \
        lib/get_next_line/get_next_line.c \
        lib/get_next_line/get_next_line_utils.c \
        src/parsing/map/init_map.c \
		src/free/free_prog.c \
		src/free/free_floor.c \
		src/free/free_ceiling.c \
		src/free/free_map.c \
        src/free/free_char.c \
        src/free/free_textures.c \
        src/free/free_mlx.c \
		src/ui/window.c \
		src/ui/minimap.c \
		src/ui/hooks.c \
		src/engine/colors.c \
		src/engine/game.c \
		src/engine/mlx_utils.c \
		src/engine/maths_functions.c \
		src/engine/player_moves.c \

OBJ = ${SRC:.c=.o}
LIBFT_DIR = lib/libft/
LIBFT = ${LIBFT_DIR}libft.a
NAME = cube3d
RM = rm -f

.c.o: cube3d
	${CC} ${FLAGS} -c -I./includes -I./lib/get_next_line -I./lib/libft -I./minilibx $< -o ${<:.c=.o}

all: ${NAME}

$(LIBFT):
	$(MAKE) -s -C $(LIBFT_DIR)
	@echo -ne "\\r${CHECK_MARK} $(NAME): $(GREEN)$(LIBFT) created !     $(RESET)"

${NAME}: ${OBJ} minilibx/libmlx_Linux.a $(LIBFT)
	${CC} ${FLAGS} ${OBJ} ./minilibx/libmlx_Linux.a -lXext -lX11 -I./lib/get_next_line/ -I./minilibx/include/ -I./includes/ -o ${NAME} -L$(LIBFT_DIR) -lft

clean_libft:
	@echo -n "$(NAME): $(GREEN)cleaning $(LIBFT)...$(RESET)"
	$(RM) $(LIBFT)
	@echo -ne "\\r${CHECK_MARK} $(NAME): $(GREEN)$(LIBFT) cleaned !     $(RESET)"

clean: clean_libft
	${RM} ${OBJ}
	$(MAKE) clean -s -C ./minilibx

fclean: clean clean_libft
	${RM} ${NAME}

re: fclean all

minilibx/libmlx_Linux.a:
	make -C ./minilibx
