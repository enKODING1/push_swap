/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:08:09 by skang             #+#    #+#             */
/*   Updated: 2024/11/19 18:10:47 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*get_str(va_list arg_ptr)
{
	return (va_arg(arg_ptr, char *));
}

int	print_str(va_list arg_ptr)
{
	char	*str;

	str = get_str(arg_ptr);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return ((int)ft_strlen(str));
}
