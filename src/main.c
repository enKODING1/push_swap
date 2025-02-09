/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:17:42 by skang             #+#    #+#             */
/*   Updated: 2025/02/09 23:15:35 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!check_args(argc, argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (0);
	stack_a->top = NULL;
	stack_b->top = NULL;
	create_stack(stack_a, argv);
	init_index(stack_a);
	set_index(stack_a);
	radix(stack_a, stack_b);
	// ft_lstiter(stack_a->top, show_list);
	// ft_putstr_fd("\n", 1);
	// ft_lstiter(stack_b->top, show_list);
	// printf("sizE: %d\n", ft_lstsize(stack_a->top));
	return (0);
}
