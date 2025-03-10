# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 21:40:18 by klamachi          #+#    #+#              #
#    Updated: 2025/02/19 22:17:11 by klamachi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -I/usr/include/minilibx-linux 

LFLAGS = -L/usr/include/minilibx-linux/ -lmlx_Linux -lXext -lX11 

SRC = so_long.c handle_input.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c utils.c free_close.c draw.c check_wall_characters.c flood_fill.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all:$(NAME)

$(NAME): $(OBJ)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) -Lft_printf -lftprintf $(LFLAGS) -o $@

clean:
	rm -f $(OBJ)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re:fclean all
