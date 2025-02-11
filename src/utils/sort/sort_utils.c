/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:15:50 by skang             #+#    #+#             */
/*   Updated: 2025/02/11 12:51:21 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	get_max_index(t_stack *stack)
{
	int		max;
	t_list	*lst;

	max = -1;
	lst = stack->top;
	while (lst)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	return (max);
}

int	get_min_index(t_stack *stack)
{
	int		min;
	t_list	*lst;

	min = 2147483647;
	lst = stack->top;
	while (lst)
	{
		if (lst->index < min)
			min = lst->index;
		lst = lst->next;
	}
	return (min);
}

int	get_bit_length(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n = n >> 1;
		count++;
	}
	return (count);
}

int	is_sorted(t_stack *stack)
{
	int		max;
	t_list	*lst;

	max = -1;
	lst = stack->top;
	while (lst)
	{
		if (lst->index > max)
			max = lst->index;
		else
			return (0);
		lst = lst->next;
	}
	return (1);
}
