#include "push_swap.h"
#include "libft.h"

// int is_sorted(t_stack *stack)
// {
//     int count;
//     t_list *lst;

//     count = 0;
//     lst = stack->top;
//     while (lst)
//     {
//        if (!(count == lst->index)) 
//             return 0;
//         lst = lst->next;
//         count++;
//     }

//     return 1;
// }

int is_sorted(t_stack *stack)
{
    int max;
    t_list *lst;

    max = -1;
    lst = stack->top;
    while (lst)
    {
       if (lst->index > max)
            max = lst->index;
       else
            return 0;
       lst = lst->next;
    }

    return 1;
}