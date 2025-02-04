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
	t_list		*top;
	int			count;
}				t_stack;

/*stack utils*/
void			del(void *value);
void			show_list(void *content);
// static t_stack	*create_stack(void);
static t_stack	*set_stack(t_stack *stack, char **words);
void			create_stack(t_stack *stack, char **argv);

/*check args*/
int				check_args(int argc, char **argv);
void			free_matrix(char **matrix);

/*stack instruction*/
void			stack_push(t_stack *src, t_stack *dest);
void			stack_swap(t_stack *ptr);
void			stack_rotate(t_stack *ptr);
void			stack_rrotate(t_stack *ptr);
void			swap_ab(t_stack *stack_a, t_stack *stack_b);
void			rotate_ab(t_stack *stack_a, t_stack *stack_b);
void			rrotate_ab(t_stack *stack_a, t_stack *stack_b);
#endif
