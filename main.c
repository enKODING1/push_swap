/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:17:42 by skang             #+#    #+#             */
/*   Updated: 2025/01/11 21:17:43 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

static t_stack	*create_stack(void);
static t_stack	*set_stack(t_stack *stack, char **words);

int	main(int argc, char **argv)
{
	char	**words;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2 || argc > 3)
	{
		ft_printf("error\n");
		return (0);
	}
	words = ft_split(argv[1], ' ');
	stack_a = create_stack();
	stack_b = create_stack();
	stack_a = set_stack(stack_a, words);

	stack_push(stack_a, stack_b);
	show_stack_status(stack_a, stack_b);
	// free_stack(stack_a);
	// free_stack(stack_b);
	// free(words);
	return (0);
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

