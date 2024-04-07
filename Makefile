CC = cc
CFLAGS = -Wall -Wextra -Werror

#TODO:need to be switched depending on the OS
MLX_DIR = minilibx/
LFT_DIR = libft/
PRNT_DIR = ft_printf/
OBJ_DIR = obj/
OBJ_BONUS_DIR = obj_bonus/
SRC_DIR = src/
SRC_BONUS_DIR = src_bonus/

NAME = fractol
NAME_BONUS = fractol_bonus

FWORKS = -framework OpenGL -framework AppKit
LIBS = -L$(LFT_DIR) -lft -L$(PRNT_DIR) -lftprintf -L$(MLX_DIR) -lmlx

INCS = -Iinc/fractol.h
INCS_BONUS = -Iinc/fractol_bonus.h 

SRC = fractol.c \
		math_utils.c \
		event_hook.c \
		validation.c \
		render.c

SRC_BONUS = fractol_bonus.c \
		math_utils_bonus.c \
		event_hook_bonus.c \
		validation_bonus.c \
		render_bonus.c

LIBFT = $(addprefix $(LFT_DIR), libft.a)
LIBPRNT = $(addprefix $(PRNT_DIR), libftprintf.a)
SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRCS_BONUS = $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS))
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
OBJ_BONUS = $(patsubst $(SRC_BONUS_DIR)%.c,$(OBJ_BONUS_DIR)%.o,$(SRCS_BONUS))

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

bonus:$(NAME_BONUS)

$(NAME_BONUS):$(OBJ_BONUS) $(LIBFT) $(LIBPRNT)
	$(CC) $(OBJ_BONUS) $(CFLAGS) $(INCS_BONUS) $(LIBS) $(FWORKS) -o $@ 

$(OBJ_BONUS_DIR)%.o:$(SRC_BONUS_DIR)%.c
	mkdir -p $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) $(INCS_BONUS) -c $< -o $@

clean:
	make -C $(LFT_DIR) clean
	make -C $(PRNT_DIR) clean
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_BONUS_DIR)

fclean:clean
	rm -rf $(NAME) $(LIBFT) $(LIBPRNT) $(NAME_BONUS)

re:fclean all

.PHONY: all clean fclean re bonus
