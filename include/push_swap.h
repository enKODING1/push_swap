/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:17:59 by skang             #+#    #+#             */
/*   Updated: 2025/02/11 12:52:43 by skang            ###   ########.fr       */
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

/*stack utils*/
void		del(void *value);
void		show_list(void *content);
void		create_stack(t_stack *stack, char **argv);
void 		initial_stack(t_stack *stack, char **argv);
void		set_index(t_stack *stack);
void		init_index(t_stack *stack);

/*check args*/
int			check_args(int argc, char **argv);
void		free_matrix(char **matrix);

/*stack instruction*/
void		stack_push(t_stack *src, t_stack *dest);
void		stack_swap(t_stack *ptr);
void		stack_rotate(t_stack *ptr);
void		stack_rrotate(t_stack *ptr);
void		push_a(t_stack *stack_a, t_stack *stack_b);
void		push_b(t_stack *stack_a, t_stack *stack_b);
void		rotate_a(t_stack *stack, int reverse);
void		rotate_b(t_stack *stack, int reverse);
void		rotate_ab(t_stack *stack_a, t_stack *stack_b);
void		rrotate_ab(t_stack *stack_a, t_stack *stack_b);
void		swap_a(t_stack *stack);
void		swap_b(t_stack *stack);
void		swap_ab(t_stack *stack_a, t_stack *stack_b);

/*sort*/
int			get_max_index(t_stack *stack);
int			get_min_index(t_stack *stack);
int			get_bit_length(int n);
void		radix(t_stack *stack_a, t_stack *stack_b);
void		two_sort(t_stack *stack);
void		three_sort(t_stack *stack);
void		four_sort(t_stack *stack_a, t_stack *stack_b);
void		five_sort(t_stack *stack_a, t_stack *stack_b);
void		sort(t_stack *stack_a, t_stack *stack_b, char **argv);

/*sort check*/
int			is_sorted(t_stack *stack);
#endif
