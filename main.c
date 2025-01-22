/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:17:42 by skang             #+#    #+#             */
/*   Updated: 2025/01/11 21:17:43 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (!check_args(argc, argv))
	{
		ft_putstr_fd("Error\n", 1);
		return 0;
	}

	t_stack stack_a;		
	t_stack stack_b;

	stack_a.top = ft_lstnew("1");
	stack_a.top->next = ft_lstnew("2");
	stack_a.top->next->next = ft_lstnew("3");

	stack_b.top = ft_lstnew("4");
	stack_b.top->next = ft_lstnew("5");
	stack_b.top->next->next = ft_lstnew("6");

	// stack_swap(&stack_a);
	// stack_push(&stack_a, &stack_b);
	// stack_rotate(&stack_a);
	stack_rrotate(&stack_a);

	ft_lstiter(stack_a.top, show_list);
	// ft_lstiter(stack_b.top, show_list);
	return (0);
}