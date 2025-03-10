# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 13:26:13 by klamachi          #+#    #+#              #
#    Updated: 2025/02/19 20:24:58 by klamachi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

AR = ar

CFLAGS = -Wall -Wextra -Werror

SRC = ft_write_incr.c print_exa.c printpointer.c ft_printf.c printstr.c printchr.c printint.c print_uns_des.c

OBG = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBG)
	$(AR) -rcs $@ $?

.PHONY: all clean fclean re

clean:
	rm -f $(OBG)

fclean: clean
	rm -f $(NAME)

re: fclean all