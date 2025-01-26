CC = gcc 
# CFLAGS = -Wall -Wextra -Werror
CFLAGS =
NAME = libpush_swap_utils.a
SOURCES = utils/stack/stack_manager.c utils/check_args.c utils/instructions/basic.c utils/instructions/extend_instructions.c 
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
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I ../

clean:
	make fclean -C $(FT_PRINTF_DIR)
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
