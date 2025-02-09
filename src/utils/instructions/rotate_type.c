/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:34:50 by skang             #+#    #+#             */
/*   Updated: 2025/02/09 20:34:51 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rotate_a(t_stack *stack, int reverse)
{
	if (reverse)
	{
		stack_rrotate(stack);
		ft_putstr_fd("rra\n", 1);
		return ;
	}
	stack_rotate(stack);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack *stack, int reverse)
{
	if (reverse)
	{
		stack_rrotate(stack);
		ft_putstr_fd("rrb\n", 1);
		return ;
	}
	stack_rotate(stack);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
}

void	rrotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a, 1);
	rotate_a(stack_b, 1);
}
