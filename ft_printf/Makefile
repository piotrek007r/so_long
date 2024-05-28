FILES = ft_printf.c \
		ft_hexlow.c \
		ft_hexupx.c \
		ft_putcharx.c \
		ft_putnumx.c \
		ft_putptr.c \
		ft_putstrx.c \
		ft_putunsint.c 

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

OBJ = $(FILES:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
