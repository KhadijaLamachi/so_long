NAME=so_long

CC=cc

# CFLAGS=-Wall -Wextra -Werror -Iminilibx-linux -Lminilibx-linux -lmlx -lX11 -lXext -lm
CFLAGS = -Wall -Wextra -Werror -I/usr/include/minilibx-linux 
LFLAGS = -L/usr/include/minilibx-linux/ -lmlx_Linux -lXext -lX11 

SRC=so_long.c handle_input.c ft_strrchr.c ft_strcmp.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ=$(SRC:.c=.o)

.PHONY: all clean fclean re

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all
