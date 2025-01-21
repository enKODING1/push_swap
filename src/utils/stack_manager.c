#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void del(void *value)
{
    free(value);
	// ft_printf("%s", value);
}

void	free_stack(t_stack *stack)
{
	if (stack && stack->top)
		ft_lstclear(&stack->top, del);
	free(stack);
}

void show_list(void *content)
{
    ft_printf("[%s]->", content);
}