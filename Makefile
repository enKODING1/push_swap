CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ./libft
	make bonus -C ./libft
	make -C ./ft_printf
	cp libft/libft.a $(NAME)
	cp ft_printf/libftprintf.a $(NAME)
	ar rcs $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./ft_printf -I ./libft

clean:
	make fclean -C ./libft
	make fclean -C ./ft_printf
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
