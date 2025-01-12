CC = cc
CFLAGS = -g
# CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

LIBFT_DIR = ./lib/libft
FT_PRINTF_DIR = ./lib/ft_printf
PUSH_SWAP_UTILS_DIR = ./src

PUSH_SWAP_UTILS = $(PUSH_SWAP_UTILS_DIR)/libpush_swap_utils.a

all: $(NAME)

$(NAME): $(PUSH_SWAP_UTILS) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) \
		-I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I ./	\
		-L$(PUSH_SWAP_UTILS_DIR) -lpush_swap_utils

$(PUSH_SWAP_UTILS):
	make -C $(PUSH_SWAP_UTILS_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ \
		 -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I ./

clean:
	make fclean -C $(PUSH_SWAP_UTILS_DIR)
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
