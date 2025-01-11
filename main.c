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

static void		show_list(void *content);
static void		del(void *value);
static t_stack	*create_stack(void);
static t_stack	*set_stack(t_stack *stack, char **words);
static void		free_stack(t_stack *stack);

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
	ft_lstiter(stack_a->top, show_list);
	free_stack(stack_a);
	free_stack(stack_b);
	free(words);
	return (0);
}

static void	show_list(void *content)
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

static void	free_stack(t_stack *stack)
{
	if (stack && stack->top)
		ft_lstclear(&stack->top, del);
	free(stack);
}

static void	del(void *value)
{
	free(value);
}
