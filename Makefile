NAME		= libftprintf.a
SRC			= ft_printf.c ft_type_processing.c
HDR			= header.h
LIB_SRC		= ./libft
LIB_NAME	= ./libft/libft.a
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -I $(LIB_SRC) -c $< -o $@

$(NAME): $(LIB_NAME) $(OBJ)
	cp $< $@
	ar -rcs $@ $(OBJ)

$(LIB_NAME) : libft ;

libft :
	$(MAKE) -C $(LIB_SRC)

clean:
	$(MAKE) -C $(LIB_SRC) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIB_SRC) fclean
	rm -f $(NAME)

re: fclean all

.PHONY : all libft clean fclean re
