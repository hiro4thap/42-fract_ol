CC = cc
CFLAGS = -Wall -Wextra -Werror

#TODO:need to be switched depending on the OS
MLX_DIR = minilibx/
LFT_DIR = libft/
OBJ_DIR = obj/
SRC_DIR = src/

NAME = fractol

FWORKS = -framework OpenGL -framework AppKit
LIBS = -L$(LFT_DIR) -lft -L$(MLX_DIR) -lmlx

INCS = -Iinc/ 

SRC = fractol.c #math_utils.c
LIBFT = $(addprefix $(LFT_DIR), libft.a)
SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all:$(NAME)

$(NAME):$(OBJ) $(LIBFT)
	make -C $(LFT_DIR)
	$(CC) $(OBJ) $(CFLAGS) $(INCS) $(LIBS) $(FWORKS) -o $@ 

$(OBJ):$(SRCS) 
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(LIBFT):
	make -C $(LFT_DIR)

clean:
	make -C $(LFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:clean
	rm -rf $(NAME)

re:fclean all

.PHONY: all clean fclean re
