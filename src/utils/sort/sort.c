#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void two_sort(t_stack *stack)
{
    swap_a(stack);
}

void three_sort(t_stack *stack)
{
    int max;
    int min;
    
    max = get_max_index(stack);
    min = get_min_index(stack);
    if (stack->top->index == max)
        rotate_a(stack, 0); 
    if (stack->top->index > stack->top->next->index)
        swap_a(stack);
    if (is_sorted(stack))
        return;
    if (stack->top->index == min)
    {
        swap_a(stack);
        rotate_a(stack, 0);
    }
    if (is_sorted(stack))
        return;
    rotate_a(stack, 1);
}

void four_sort(t_stack *stack_a, t_stack *stack_b)
{
    int min;
    
    min = get_min_index(stack_a);
    while (1)    
    {
        if (stack_a->top->index == min)
        {
            push_b(stack_a, stack_b);
            break;
        }
        rotate_a(stack_a, 0);
    }

    three_sort(stack_a);
    push_a(stack_a, stack_b);
}

void five_sort(t_stack *stack_a, t_stack *stack_b)
{   
    int min;
    int max;
    int push_flag;

    min = get_min_index(stack_a);
    max = get_max_index(stack_a);
    push_flag = 0;
    while (1)
    {
        if (stack_a->top->index == max || stack_a->top->index == min) 
        {
            push_b(stack_a, stack_b);
            if (stack_a->top && (stack_a->top->index ==  max || stack_a->top->index == min))
            {
                push_b(stack_a, stack_b); 
                break;
            }
            push_flag++;
        }
       
        if (push_flag == 2)
            break;
        rotate_a(stack_a, 0);
    }

    three_sort(stack_a);
    if (stack_b->top->index > stack_b->top->next->index)
        swap_b(stack_b); 
    push_a(stack_a, stack_b);
    push_a(stack_a, stack_b);
    rotate_a(stack_a, 0);
}