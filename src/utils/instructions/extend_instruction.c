#include "libft.h"
#include "push_swap.h"

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	stack_swap(stack_a);
	stack_swap(stack_b);
}

void	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate(stack_a);
	stack_rotate(stack_b);
}

void	rrotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	stack_rrotate(stack_a);
	stack_rrotate(stack_b);
}