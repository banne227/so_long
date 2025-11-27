# === Variables de base ===
NAME = libftprintf.a
SOURCES = ft_printf.c ft_utils.c ft_utils1.c

OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f
CC = cc

# === Règles ===
all: $(NAME)
$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c ft_printf.h
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
