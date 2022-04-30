CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCSRC = includes

SRC = $(SRCDIR)/main.c $(SRCDIR)/ft_atoi.c $(SRCDIR)/validation.c $(SRCDIR)/calculation.c $(SRCDIR)/basic_func.c
TARGET = do-op
OBJ = $(SRC:%.c=%.o)

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCSRC)

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(TARGET)

re : fclean all