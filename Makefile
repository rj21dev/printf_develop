NAME	= ft_printf
SRC		= main.c ft_printf.c ft_putchar.c ft_itoa.c ft_processor.c ft_putstr.c ft_ultoa.c ft_isdigit.c ft_format_parcer.c
HDR		= header.h
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

run:
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
