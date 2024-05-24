NAME    = so_long

CC      = gcc
CFLAGS  = 
LDFLAGS = -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm

SRCS    = $(wildcard *.c) $(wildcard minilibx_linux/*.c) $(wildcard get_next_line/*.c)
OBJS    = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I./minilibx-linux -I./get_next_line -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re