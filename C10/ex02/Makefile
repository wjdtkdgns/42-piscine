CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = ft_tail
SRC = main.c print.c
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I tail.h

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all