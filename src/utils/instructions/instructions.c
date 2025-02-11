/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:09:51 by skang             #+#    #+#             */
/*   Updated: 2025/02/09 19:09:52 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	stack_push(t_stack *src, t_stack *dest)
{
	t_list	*src_top;
	t_list	*dest_top;

	src_top = src->top;
	src->top = src_top->next;
	dest_top = dest->top;
	src_top->next = dest_top;
	dest->top = src_top;
}

void	stack_swap(t_stack *ptr)
{
	t_list	*top;

	top = ptr->top;
	ptr->top = top->next;
	top->next = ptr->top->next;
	ptr->top->next = top;
}

void	stack_rotate(t_stack *ptr)
{
	t_list	*top;

	top = ptr->top;
	ptr->top = top->next;
	top->next = NULL;
	ft_lstadd_back(&(ptr->top), top);
}

void	stack_rrotate(t_stack *ptr)
{
	t_list	*top;
	t_list	*last;
	t_list	*temp;

	top = ptr->top;
	last = ft_lstlast(ptr->top);
	temp = ptr->top;
	while (temp->next != last)
	{
		temp = temp->next;
		if (temp->next == last)
		{
			temp->next = NULL;
			break ;
		}
	}
	ptr->top = last;
	last->next = top;
}
