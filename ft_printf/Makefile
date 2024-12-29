CC = gcc 
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SOURCES = ft_printf.c utils/get_char.c utils/get_str.c utils/get_addr.c utils/get_int.c utils/get_u.c utils/get_x.c utils/get_i.c utils/get_percent.c\
	utils/ft_putnbr_base.c utils/ft_putnbr_addr_base.c utils/ft_putnbr_unsigned_base.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ../libft
	make bonus -C ../libft
	cp ../libft/libft.a $(NAME)
	ar rcs $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./ -I ../libft

clean:
	make fclean -C ../libft
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
