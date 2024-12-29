CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	# build library
	make -C ./libft
	make bonus -C ./libft
	make -C ./ft_printf
	# copy library
	cp libft/libft.a $(NAME)
	cp ft_printf/libftprintf.a $(NAME)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L./libft -lft -L./ft_printf -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I ./ft_printf -I ./libft
	

clean:
	make fclean -C ./libft
	make fclean -C ./ft_printf
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
