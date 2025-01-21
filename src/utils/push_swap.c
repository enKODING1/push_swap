/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:17:51 by skang             #+#    #+#             */
/*   Updated: 2025/01/11 21:17:54 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "stdio.h"

int	stack_push(t_stack *src_stack, t_stack *dest_stack)
{
    t_list *new;
    // t_list *temp;

    new = ft_lstnew(src_stack->top->content);
	ft_lstadd_front(&dest_stack->top, new);		

    // temp = src_stack->top->next;
    // printf("value: [%p]", temp);
    // ft_lstdelone(src_stack->top, del);
    // src_stack->top = temp;
 
    return 1;
}
// int	stack_swap(t_stack *stack)
// {

// }
// int	stack_rotate(t_stack *stack)
// {

// }
