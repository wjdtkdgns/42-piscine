CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

INCDIR = includes
SRCDIR = srcs

SRC = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
TARGET = libft.a
OBJ = $(SRC:%.c=%.o)

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INCDIR)

$(TARGET) : $(OBJ)
	ar rc $@ $(OBJ)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(TARGET)

re : fclean all