/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:17:42 by skang             #+#    #+#             */
/*   Updated: 2025/02/09 19:10:25 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int	is_space(char c)
{
	if (c == 32 || c == 9)
		return (1);
	return (0);
}

int	check_range(char *s)
{
	long	temp;
	int		i;

	temp = 0;
	i = 0;
	temp = ft_atoi(s);
	if (temp >= 2147483647 || temp <= -2147483648)
		return (0);
	if (ft_strchr(s, ' '))
	{
		while (s[i])
		{
			if (is_space(s[i]) && ft_isdigit(s[i + 1]))
			{
				temp = ft_atoi(&s[i]);
				if (temp >= 2147483647 || temp <= -2147483648)
					return (0);
			}
			i++;
		}
	}
	return (1);
}

int	is_valid_str(char *s)
{
	int	i;
	int	num_flag;

	i = 0;
	num_flag = 0;
	while (s[i])
	{
		if ((s[i] == '-' || s[i] == '+') && (ft_isdigit(s[i + 1])))
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(s[i]) && !is_space(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	matrix = NULL;
}

int	create_node_by_matrix(t_stack *stack, char *str)
{
	t_list	*temp_top;
	int		i;
	int		is_dup;
	char	**temp_str;

	i = 0;
	is_dup = 0;
	temp_str = ft_split(str, ' ');
	if (temp_str[i] && !stack->top)
		stack->top = ft_lstnew(ft_strdup(temp_str[i++]));
	while (temp_str[i] && !is_dup)
	{
		temp_top = stack->top;
		while (temp_top && !is_dup)
		{
			if (ft_atoi(temp_top->content) == ft_atoi(temp_str[i]))
				is_dup = 1;
			temp_top = temp_top->next;
		}
		ft_lstadd_back(&(stack->top), ft_lstnew(ft_strdup(temp_str[i++])));
	}
	free_matrix(temp_str);
	if (is_dup)
		return (0);
	return (1);
}

int	check_args(int argc, char **argv)
{
	t_stack	*head;
	char	**temp_args;
	int		i;
	int		invalid;

	head = malloc(sizeof(t_stack));
	i = 0;
	invalid = 0;
	if (argc == 2)
		temp_args = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		i = 1;
		temp_args = argv;
	}
	while (temp_args[i] && !invalid)
	{
		if (!is_valid_str(temp_args[i]))
			invalid = 1;
		if (!check_range(temp_args[i]))
			invalid = 1;
		if (!create_node_by_matrix(head, temp_args[i]))
			invalid = 1;
		i++;
	}
	if (argc == 2)
		free_matrix(temp_args);
	ft_lstclear(&head->top, del);
	free(head);
	if (invalid)
		return (0);
	return (1);
}
