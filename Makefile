CC = cc
CFLAGS = -Wall -Wextra -Werror

#TODO:need to be switched depending on the OS
MLX_DIR = minilibx/
LFT_DIR = libft/
PRNT_DIR = ft_printf/
OBJ_DIR = obj/
SRC_DIR = src/

NAME = fractol

FWORKS = -framework OpenGL -framework AppKit
LIBS = -L$(LFT_DIR) -lft -L$(PRNT_DIR) -lftprintf -L$(MLX_DIR) -lmlx

INCS = -Iinc/ 

SRC = fractol.c \
		math_utils.c \
		event_hook.c \
		validation.c \
		render.c

LIBFT = $(addprefix $(LFT_DIR), libft.a)
LIBPRNT = $(addprefix $(PRNT_DIR), libftprintf.a)
SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all:$(NAME)

$(NAME):$(OBJ) $(LIBFT) $(LIBPRNT)
	$(CC) $(OBJ) $(CFLAGS) $(INCS) $(LIBS) $(FWORKS) -o $@ 

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(LIBFT):
	make -C $(LFT_DIR)

$(LIBPRNT):
	make -C $(PRNT_DIR)

clean:
	make -C $(LFT_DIR) clean
	make -C $(PRNT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:clean
	rm -rf $(NAME) $(LIBFT) $(LIBPRNT)

re:fclean all

.PHONY: all clean fclean re
