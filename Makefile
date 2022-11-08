NAME=so_long
CC=cc
HEADER=src/so_long.h
CFLAGS=-Wall -Wextra -Werror
MAKEFILE=Makefile
MLX=-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRCS=src/main.c\
	src/get_next_line.c\
	src/get_next_line_utils.c\
	src/utils.c\
	src/so_long.c\
	src/my_mlx_utils.c\
	src/print_map_utils.c\
	src/move_player_utils.c\
	src/help_utils.c\
	src/ft_itoa.c

OBJS=$(SRCS:.c=.o)

.PHONY: all clean fclean re

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX) -o $(NAME) 

%.o: %.c $(MAKEFILE) $(HEADER)
	$(CC) $(CFLAGS) -I/usr/include -Imlx -c $< -o $@
 
clean:
	rm -f src/*.o

fclean: clean
	rm -f $(NAME)

run: all
	./so_long maps/map1.ber

re: clean fclean all 
