/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:43:18 by skang             #+#    #+#             */
/*   Updated: 2024/11/19 18:10:52 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_x(va_list arg_ptr)
{
	return (va_arg(arg_ptr, int));
}

int	print_x(va_list arg_ptr, char x_type)
{
	if (x_type == 'x')
		return (ft_putnbr_unsigned_base(get_x(arg_ptr), "0123456789abcdef"));
	if (x_type == 'X')
		return (ft_putnbr_unsigned_base(get_x(arg_ptr), "0123456789ABCDEF"));
	return (0);
}
