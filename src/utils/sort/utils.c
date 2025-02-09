/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:15:50 by skang             #+#    #+#             */
/*   Updated: 2025/02/09 23:15:51 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	get_max_index(t_stack *stack)
{
	return (ft_lstsize(stack->top) - 1);
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
