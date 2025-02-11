/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:17:42 by skang             #+#    #+#             */
/*   Updated: 2025/02/11 15:28:49 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int	valid_args(t_stack *stack, char **argv, int start)
{
	int	i;
	int	valid;

	i = start;
	valid = 1;
	while (argv[i] && valid)
	{
		if (!is_valid_str(argv[i]))
			valid = 0;
		if (!check_range(argv[i]))
			valid = 0;
		if (!create_node_by_matrix(stack, argv[i]))
			valid = 0;
		i++;
	}
	return (valid);
}

int	check_args(int argc, char **argv)
{
	t_stack	*stack;
	char	**temp_args;
	int		i;
	int		valid;

	stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	i = 0;
	if (argc == 2)
		temp_args = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		i = 1;
		temp_args = argv;
	}
	valid = valid_args(stack, temp_args, i);
	if (argc == 2)
		free_matrix(temp_args);
	free_stack(&stack);
	if (!valid)
		return (0);
	return (1);
}
