CC = cc -g
CFLAGS = -Wall -Wextra -Werror
CFLAGS =
NAME = libpush_swap_utils.a
SOURCES = utils/stack/stack_utils.c utils/stack/stack.c \
		  utils/args/args_core.c utils/args/args_utils.c utils/args/overflow_checker.c\
		  utils/instructions/instructions.c utils/instructions/push_type.c utils/instructions/rotate_type.c utils/instructions/swap_type.c \
		  utils/sort/radix.c utils/sort/sort_utils.c utils/sort/sort.c utils/sort/sort_core.c
OBJECTS = $(SOURCES:.c=.o)

LIBFT_DIR = ../lib/libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	ar rcs $@ $(OBJECTS)

$(LIBFT):
	make -C $(LIBFT_DIR)
	make bonus -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_DIR) -I ../include/

clean:
	make fclean -C $(LIBFT_DIR)
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
