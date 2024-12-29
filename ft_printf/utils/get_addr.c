/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:13:01 by skang             #+#    #+#             */
/*   Updated: 2024/11/19 18:10:38 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static uintptr_t	get_addr(va_list arg_ptr)
{
	return (va_arg(arg_ptr, uintptr_t));
}

int	print_addr(va_list arg_ptr)
{
	uintptr_t	addr;
	int			addr_count;

	addr = get_addr(arg_ptr);
	if (addr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	addr_count = ft_putnbr_addr_base(addr, "0123456789abcdef");
	return (addr_count + 2);
}
