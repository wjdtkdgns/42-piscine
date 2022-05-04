CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = ft_hexdump
SRC = main.c print.c string.c hexfile.c validate.c print_error.c
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I hexdump.h
	
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all