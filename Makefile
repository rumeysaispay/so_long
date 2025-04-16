NAME        = so_long

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

SRC         = 	src/so_long.c								\
				src/error_message_and_free.c 				\
				src/game_graphics.c 						\
				src/map_control.c   						\
				src/map_validate.c 							\
				src/player_control.c 						\
				inc/get_next_line/get_next_line.c           \
             	inc/get_next_line/get_next_line_utils.c

OBJ         = $(SRC:.c=.o)

LIBFT_PATH      = ./inc/Libft
LIBFT           = $(LIBFT_PATH)/libft.a

FT_PRINTF_PATH  = ./inc/ft_printf
FT_PRINTF       = $(FT_PRINTF_PATH)/libftprintf.a

MINILIBX_PATH   = ./inc/minilibx-linux
MLX             = $(MINILIBX_PATH)/libmlx.a

LIBS            = -L$(MINILIBX_PATH) -lmlx -L/usr/X11/lib -lX11 -lXext

all:            $(NAME)

$(NAME):        $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF) $(LIBS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH) all

$(FT_PRINTF):
	@make -C $(FT_PRINTF_PATH) all

$(MLX):
	@make -C $(MINILIBX_PATH) all

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(FT_PRINTF_PATH) clean
	@make -C $(MINILIBX_PATH) clean
	@$(RM) $(OBJ)

fclean:	clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(FT_PRINTF_PATH) fclean
	@$(RM) $(NAME)

re:             fclean all

.PHONY:         all clean fclean re