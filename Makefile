# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgerner <pgerner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 18:29:20 by cgerner           #+#    #+#              #
#    Updated: 2025/06/30 11:49:311 by pgerner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = $(addprefix srcs/, parsing/map.c parsing/map2.c parsing/parsing.c parsing/reading.c \
		parsing/relatives.c parsing/texture_color.c parsing/texture_color2.c parsing/utils_map.c \
		parsing/utils_map2.c parsing/utils_map3.c exec/map_design.c exec/move.c \
		exec/player.c exec/raycasting.c exec/rotate.c exec/utils_exec.c \
		exec/draw_window.c free.c free2.c main.c utils.c)

CFLAGS = -Wall -Wextra -Werror -g3

MLX_FLAGS = -lmlx_Linux -lXext -lX11 -L./minilibx-linux -lmlx -lm -L./Libft 

LIBFT = Libft/libft.a

MLX = /minilibx-linux/libmlx.a

MY_OBJECTS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(MY_OBJECTS)
	make -sC minilibx-linux/
	$(CC) $(CFLAGS) -o $(NAME) $(MY_OBJECTS) $(MLX_FLAGS) Libft/libft.a

all: $(NAME)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re