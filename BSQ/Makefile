CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes

NAME = bsq
SRC = $(SRCDIR)/main.c $(SRCDIR)/basic_func.c $(SRCDIR)/print.c $(SRCDIR)/square.c $(SRCDIR)/validation.c $(SRCDIR)/read_map.c
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
