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

static t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->count = 0;
	return (stack);
}

static t_stack	*set_stack(t_stack *stack, char **words)
{
	int	i;
		t_list *node;

	i = 0;
	while (words[i])
	{
		node = ft_lstnew(words[i++]);
		if (!stack->top && !node)
		{
			stack->top = node;
			continue ;
		}
		ft_lstadd_front(&(stack->top), node);
	}
	return (stack);
}