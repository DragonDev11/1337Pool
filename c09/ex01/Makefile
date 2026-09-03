CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = libft.a

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
INC = includes/
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(TARGET)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(TARGET): $(OBJS)
	ar -r $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

