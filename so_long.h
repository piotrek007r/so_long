#ifndef SO_LONG_H
# define SO_LONG_H
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"




#endif

// NAME    = so_long

// CC      = gcc
// CFLAGS  = -Wall -Wextra -Werror
// LDFLAGS = -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm

// SRCS    = $(wildcard *.c) $(wildcard minilibx_linux/*.c) $(wildcard get_next_line/*.c)
// OBJS    = $(SRCS:.c=.o)


// all: $(NAME)

// $(NAME): $(OBJS)
// 	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

// %.o: %.c
// 	$(CC) $(CFLAGS) -I./minilibx-linux -I./get_next_line -c $< -o $@

// clean:
// 	rm -f $(OBJS)

// fclean: clean
// 	rm -f $(NAME)

// re: fclean all

// .PHONY: all clean fclean re