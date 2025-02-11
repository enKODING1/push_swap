/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:10:11 by skang             #+#    #+#             */
/*   Updated: 2025/02/11 15:43:12 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void	create_stack(t_stack *stack, char **argv)
{
	char	**temp;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		temp = ft_split(argv[i], ' ');
		while (temp[j])
		{
			if (stack->top == NULL)
			{
				stack->top = ft_lstnew(ft_strdup(temp[j++]));
				continue ;
			}
			ft_lstadd_back(&stack->top, ft_lstnew(ft_strdup(temp[j++])));
		}
		free_matrix(temp);
		i++;
	}
}

void	init_index(t_stack *stack)
{
	t_list	*ptr;

	ptr = stack->top;
	while (ptr)
	{
		ptr->index = -1;
		ptr = ptr->next;
	}
}

void	set_index(t_stack *stack)
{
	t_list	*ptr;
	t_list	*biggest;
	int		highest;
	int		lst_size;

	lst_size = ft_lstsize(stack->top);
	ptr = stack->top;
	while (lst_size-- > 0)
	{
		highest = -2147483648;
		biggest = NULL;
		while (ptr)
		{
			if (ptr->index == -1 && ft_atoi((char *)ptr->content) >= highest)
			{
				highest = ft_atoi((char *)ptr->content);
				biggest = ptr;
			}
			ptr = ptr->next;
		}
		if (biggest)
			biggest->index = lst_size;
		ptr = stack->top;
	}
}
