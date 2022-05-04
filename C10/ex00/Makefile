CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = ft_display_file
SRC = main.c
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all