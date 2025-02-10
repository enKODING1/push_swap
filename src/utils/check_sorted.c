#include "push_swap.h"
#include "libft.h"

int is_sorted(t_stack *stack)
{
    int count;

    count = 0;
    while (stack->top)
    {
       if (!(count == stack->top->index)) 
            return 0;
        stack->top = stack->top->next;
        count++;
    }

    return 1;
}