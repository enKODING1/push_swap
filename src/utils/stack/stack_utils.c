/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:10:18 by skang             #+#    #+#             */
/*   Updated: 2025/02/11 15:28:22 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	initial_stack(t_stack *stack, char **argv)
{
	create_stack(stack, argv);
	init_index(stack);
	set_index(stack);
}

void	del(void *value)
{
	if (value)
		free(value);
}

void	show_list(void *content)
{
	ft_putstr_fd(content, 1);
	ft_putstr_fd("->", 1);
}

void	free_stack(t_stack **stack)
{
	ft_lstclear(&(*stack)->top, del);
	free(*stack);
	stack = NULL;
}
