CC = gcc -g
# CFLAGS = -Wall -Wextra -Werror
CFLAGS =
NAME = libpush_swap_utils.a
SOURCES = utils/stack/stack_utils.c utils/stack/stack.c utils/args/check_args.c utils/instructions/instructions.c utils/instructions/push_type.c utils/instructions/rotate_type.c utils/instructions/swap_type.c utils/sort/radix.c utils/sort/sort_utils.c utils/sort/sort.c
OBJECTS = $(SOURCES:.c=.o)

LIBFT_DIR = ../lib/libft
FT_PRINTF_DIR = ../lib/ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(FT_PRINTF) $(OBJECTS)
	ar rcs $@ $(OBJECTS)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)
	cp $(FT_PRINTF) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I ../include/

clean:
	make fclean -C $(FT_PRINTF_DIR)
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
