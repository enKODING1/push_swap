#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void del(void *value)
{
    free(value);
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

void show_stack(void *a_content, void *b_content)
{
	ft_printf("%s ", a_content);
	ft_printf("%s \n", b_content);
}

void show_stack_status(t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	while (a->top || b->top)
	{
			show_stack(a->top->content, b->top->content);
			a->top = a->top->next;	
			b->top = b->top->next;	
	}
	ft_printf("a  b\n");
}