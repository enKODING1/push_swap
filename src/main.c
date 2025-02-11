/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:17:42 by skang             #+#    #+#             */
/*   Updated: 2025/02/11 15:27:52 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	if (argc == 1)
		return 0;
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
	initial_stack(stack_a, argv);
	sort(stack_a, stack_b, argv);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
