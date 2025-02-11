/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:10:18 by skang             #+#    #+#             */
/*   Updated: 2025/02/09 19:10:19 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	del(void *value)
{
	if (value)
		free(value);
}

void	show_list(void *content)
{
	ft_putstr_fd(content, 1);
	ft_putstr_fd("->", 1);
}
