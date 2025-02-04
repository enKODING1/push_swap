#include "libft.h"
#include "push_swap.h"

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
			ft_lstadd_back(&stack->top, ft_lstnew((temp[j++])));
		}
		free_matrix(temp);
		i++;
	}
}

void 	init_index(t_stack *stack)
{
	t_list *ptr;

	ptr = stack->top;
	while(ptr)
	{
		ptr->index = -1;
		ptr = ptr->next;
	}
}

// content사이즈에 따른 index 순서 부여
// void set_index(t_stack *stack)
// {
// 		t_list *biggest;
// 		t_list *ptr;
// 		int	highest;
// 		int lst_size;

// 		lst_size = ft_lstsize(stack->top);
// 		highest = -2147483648;
// 		ptr = stack->top;
// 		biggest = stack->top;
// 		while(lst_size-- > 0)
// 		{
// 			while (ptr)
// 			{
// 				if (ft_atoi(ptr->content) < highest)	
// 			}
// 		}
		
// }
