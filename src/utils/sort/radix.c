/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:15:44 by skang             #+#    #+#             */
/*   Updated: 2025/02/09 23:16:33 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	int	max_value;
	int	max_bit_length;
	int	i;
	int	j;

	max_value = get_max_index(stack_a);
	max_bit_length = get_bit_length(max_value);
	i = -1;
	while (++i < max_bit_length)
	{
		j = -1;
		while (++j <= max_value)
		{
			if ((stack_a->top->index >> i) & 1)
				rotate_a(stack_a, 0);
			else
				push_b(stack_a, stack_b);
		}
		while (stack_b->top)
			push_a(stack_a, stack_b);
		if (is_sorted(stack_a))
			return;
	}
}
