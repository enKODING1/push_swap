/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:34:47 by skang             #+#    #+#             */
/*   Updated: 2025/02/09 20:34:48 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	stack_push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	stack_push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
