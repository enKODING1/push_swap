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
