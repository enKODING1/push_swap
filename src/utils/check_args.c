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

#include "libft.h"
#include "push_swap.h"

int is_space(char c)
{
    if(c == 32 || c == 9)
        return 1;
    return 0;
}

int check_range(char *s)
{
    long temp;
    int i;

    temp = 0;
    i = 0;
    
    temp = ft_atoi(s);
    if (temp >= 2147483647 || temp <= -2147483648)
        return 0;

    if (ft_strchr(s, ' '))
    {
        while(s[i])
        {
            if (is_space(s[i]) && ft_isdigit(s[i + 1]))
            {
                temp = ft_atoi(&s[i]);
                if (temp >= 2147483647 || temp <= -2147483648)
                    return 0;
            }
            i++;
        }
    }
    return 1;
}

int is_valid_str(char *s)
{
    int i;
    int num_flag;

    i = 0;
    num_flag = 0;
    while (s[i])
    {
        if ((s[i] == '-' || s[i] == '+') && (ft_isdigit(s[i + 1])))
        {
            i++;
            continue;
        }
        if (!ft_isdigit(s[i]) && !is_space(s[i]))
            return 0;
        i++;
    }
    return 1;
}

void free_matrix(char **matrix)
{
    int i;
    if (!matrix)
        return;

    i = -1;
    while(matrix[++i])
    {
        free(matrix[i]);
        matrix[i] = NULL;
    }
}

int create_nodes_by_args(t_stack *stack, char *str)
{
    char **temp_args;
    t_list *new;
    t_stack *temp;
    int temp_content;
    int i;

    i = 0;
    temp_content = 0;
    temp_args = ft_split(str, ' ');
    while(temp_args[i])
    {
        temp_content = ft_atoi(temp_args[i]);
        new = ft_lstnew(ft_atoi(temp_content));
        if (stack->top == NULL)
            stack->top = new;

        temp = stack;
        while (temp->top)
        {
            if (temp->top->content == temp_content)    
            {
                free_matrix(temp_args);    
                free_stack(stack);
                return 0;
            }
             temp->top = temp->top->next;
        } 
        ft_lstadd_back(&(stack->top), new);
    }
    free_matrix(temp_args);
    return 1;
}

int check_args(int argc, char **argv)
{
    char **temp_args;
    int i;

    t_stack *head;          
    
    i = 0;
    if (argc == 2)
        temp_args = ft_split(argv[1], ' ');
    else if (argc > 2)
    {
        i = 1;
        temp_args = argv;
    }

    while(temp_args[i])
    {
       if (!is_valid_str(temp_args[i]))
            return 0;
       if (!check_range(temp_args[i]))
            return 0;
       if (!create_nodes_by_args(head, temp_args[i]))
            return 0;
       i++;
    }
    if (argc == 2)
        free_matrix(temp_args);
    free_stack(head);
    return 1;
}