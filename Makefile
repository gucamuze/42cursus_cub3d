# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 02:21:09 by gucamuze          #+#    #+#              #
#    Updated: 2022/05/17 16:27:24 by gucamuze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


EXEC_NAME			=	cub3d
CC					=	clang -Wall -Wextra -Werror -g
RM					=	rm -f

SRC_FILES_PATH		=	./srcs/
PARSING_FILES_PATH	=	./srcs/parsing/
ENGINE_FILES_PATH	=	./srcs/engine/
UI_FILES_PATH		=	./srcs/ui/

LIBFT_PATH			=	./libft/
LIBFT_A				=	./libft/libft.a
INCLUDES			=	 -Iminilibx-linux -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz $(LIBFT_A)
			
PARSING_FILES		=	parsing.c color.c create_map.c error_map.c loop_info.c map.c \
						path_textures.c gnl.c fill_map.c 
PARSING_PATH		=	$(addprefix ${PARSING_FILES_PATH}, ${PARSING_FILES})
PARSING_OFILES		=	$(PARSING_PATH:.c=.o)
ALL_OFILES			+=	$(PARSING_OFILES)

ENGINE_FILES		=	engine.c colors.c
ENGINE_PATH			=	$(addprefix ${ENGINE_FILES_PATH}, ${ENGINE_FILES})
ENGINE_OFILES		=	$(ENGINE_PATH:.c=.o)
ALL_OFILES			+=	$(ENGINE_OFILES)					
				
UI_FILES			=	ui.c hooks.c
UI_PATH				=	$(addprefix ${UI_FILES_PATH}, ${UI_FILES})
UI_OFILES			=	$(UI_PATH:.c=.o)
ALL_OFILES			+=	$(UI_OFILES)
			
SRC_FILES			=	main.c cleanup.c
SRC_PATH			=	$(addprefix ${SRC_FILES_PATH}, ${SRC_FILES})
SRC_OFILES			=	$(SRC_PATH:.c=.o)
ALL_OFILES			+=	$(SRC_OFILES)

%.o:%.c
				$(CC) -Iincludes -Iminilibx-linux -c $< -o $@

all:			${EXEC_NAME}

$(EXEC_NAME):	$(LIBFT_A) OFILES
				$(CC) $(ALL_OFILES) $(INCLUDES) -o $(EXEC_NAME)

$(LIBFT_A):
				make --directory=libft

OFILES:			${SRC_OFILES} ${ENGINE_OFILES} ${UI_OFILES} ${PARSING_OFILES}
				
noflags:		CC = clang -g
noflags:		all

fsanitize:		CC = clang -Wall -Wextra -Werror -fsanitize=address -g
fsanitize:		all
				
clean:
				make clean --directory=libft
				$(RM) $(ALL_OFILES)

fclean:		clean
				$(RM) $(LIBFT_A) ${EXEC_NAME}

re:			fclean all

norminette:
			norminette srcs libft includes

bonus:
			@google-chrome-stable --new-window https://youtu.be/dQw4w9WgXcQ\?t\=42	

.PHONY:	all clean fclean re norminette

