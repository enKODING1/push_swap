/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:28:54 by skang             #+#    #+#             */
/*   Updated: 2025/02/11 15:28:55 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check_range(char *s)
{
	int	i;

	i = 0;
	if (!is_valid_integer(s))
		return (0);
	if (ft_strchr(s, ' '))
	{
		while (s[i])
		{
			if (is_space(s[i]) && ft_isdigit(s[i + 1]))
			{
				if (!is_valid_integer(&s[i]))
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
		if ((s[i] == '-' || s[i] == '+') && (s[i+1] == '-' || s[i + 1] == '+'))	
			return (0);
		if (ft_isdigit(s[i]) && (s[i+1] == '-' || s[i+1] == '+'))
			return (0);
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
