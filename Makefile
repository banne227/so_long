# **************************************************************************** #
#                                  so_long                                     #
# **************************************************************************** #

NAME        := so_long
BONUS_NAME  := so_long_bonus

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -Iincludes -Iminilibx-linux
RM          := rm -rf

MLX_DIR     := minilibx-linux
MLX_LIB     := $(MLX_DIR)/libmlx_Linux.a

# ft_printf
FT_M        := srcs/ft_printf/libftprintf.a
FT_B        := srcs_bonus/ft_printf/libftprintf.a

# libs
LDLIBS      := -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

# Sources
SRCS_M      := $(filter-out srcs/ft_printf/%.c, $(wildcard srcs/*.c srcs/*/*.c))
SRCS_B      := $(filter-out srcs_bonus/ft_printf/%.c, $(wildcard srcs_bonus/*.c srcs_bonus/*/*.c))

OBJS_M      := $(SRCS_M:.c=.o)
OBJS_B      := $(SRCS_B:.c=.o)

# ============================================================================

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(MLX_LIB) $(FT_M) $(OBJS_M)
	$(CC) $(CFLAGS) $(OBJS_M) -o $@ $(LDLIBS) -Lsrcs/ft_printf -lftprintf

$(BONUS_NAME): $(MLX_LIB) $(FT_B) $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $@ $(LDLIBS) -Lsrcs_bonus/ft_printf -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# External libs
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(FT_M):
	$(MAKE) -C srcs/ft_printf

$(FT_B):
	$(MAKE) -C srcs_bonus/ft_printf

clean:
	$(RM) $(OBJS_M) $(OBJS_B)
	-$(MAKE) -C srcs/ft_printf clean
	-$(MAKE) -C srcs_bonus/ft_printf clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	-$(MAKE) -C srcs/ft_printf fclean
	-$(MAKE) -C srcs_bonus/ft_printf fclean
	-$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all bonus clean fclean re
