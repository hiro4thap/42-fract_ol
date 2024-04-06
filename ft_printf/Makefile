SRCS = ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putadr.c \
	ft_puthxl.c \
	ft_puthxu.c \
	ft_putint.c \
	ft_putuint.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rcs 

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
