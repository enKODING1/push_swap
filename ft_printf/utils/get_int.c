/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:38:28 by skang             #+#    #+#             */
/*   Updated: 2024/11/19 18:18:45 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_int_length(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	get_int(va_list arg_ptr)
{
	return (va_arg(arg_ptr, int));
}

int	print_int(va_list arg_ptr)
{
	int	num;

	num = get_int(arg_ptr);
	ft_putnbr_fd(num, 1);
	return (get_int_length(num));
}
