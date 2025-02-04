#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

void	del(void *value)
{
	if (value)
		free(value);
}

void	show_list(void *content)
{
	ft_putstr_fd(content, 1);
	ft_putstr_fd("->", 1);
}