/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:17:59 by skang             #+#    #+#             */
/*   Updated: 2025/01/11 21:18:01 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	t_list	*top;
	int		count;
}			t_stack;

typedef struct s_arg_checker{
		
}	t_arg_checker;

/*stack utils*/
void	free_stack(t_stack *stack);
void del(void *value);
void show_list(void *content);

/*push_swap utils*/
int			stack_push(t_stack *src_stack, t_stack *dest_stack);
int			stack_swap(t_stack *stack);
int			stack_rotate(t_stack *stack);

/*check args*/
int valid_args(int argc, char **args);
#endif
