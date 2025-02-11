/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:09:28 by skang             #+#    #+#             */
/*   Updated: 2025/02/11 14:09:30 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b, char **argv)
{
	int	stack_length;

	if (is_sorted(stack_a))
		return ;
	stack_length = ft_lstsize(stack_a->top);
	if (stack_length == 2)
		two_sort(stack_a);
	if (stack_length == 3)
		three_sort(stack_a);
	if (stack_length == 4)
		four_sort(stack_a, stack_b);
	if (stack_length == 5)
		five_sort(stack_a, stack_b);
	if (stack_length > 5)
		radix(stack_a, stack_b);
	return ;
}
