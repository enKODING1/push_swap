/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:34:54 by skang             #+#    #+#             */
/*   Updated: 2025/02/09 20:34:55 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	stack_swap(stack);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack *stack)
{
	stack_swap(stack);
	ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
