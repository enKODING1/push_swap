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
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (!check_args(argc, argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}

	t_stack *stack_a;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	create_stack(stack_a, argv);
	ft_lstiter(stack_a->top, show_list);
	return (0);
}