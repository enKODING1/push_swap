/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:34:48 by skang             #+#    #+#             */
/*   Updated: 2024/11/19 17:27:07 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	valid_specifier(char specifier)
{
	char	valid_specifier_array[9];
	int		index;

	ft_strlcpy(valid_specifier_array, "cspdiuxX%", 10);
	index = 0;
	while (valid_specifier_array[index] != '\0')
	{
		if (specifier == valid_specifier_array[index])
			return (1);
		index++;
	}
	return (0);
}

static int	specifier_dispatcher(char specifier, va_list arg_ptr)
{
	if (specifier == 'c')
		return (print_char(arg_ptr));
	if (specifier == 's')
		return (print_str(arg_ptr));
	if (specifier == 'p')
		return (print_addr(arg_ptr));
	if (specifier == 'd')
		return (print_int(arg_ptr));
	if (specifier == 'i')
		return (print_i(arg_ptr));
	if (specifier == 'u')
		return (print_u(arg_ptr));
	if (specifier == 'x')
		return (print_x(arg_ptr, 'x'));
	if (specifier == 'X')
		return (print_x(arg_ptr, 'X'));
	if (specifier == '%')
		return (print_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	int		index;
	int		format_len;
	int		str_count;

	va_start(arg_ptr, format);
	index = 0;
	format_len = (int)ft_strlen(format);
	str_count = 0;
	while (format[index] != '\0' || index < format_len)
	{
		if (format[index] == '%' && valid_specifier(format[index + 1]))
		{
			str_count += specifier_dispatcher(format[index + 1], arg_ptr);
			index += 2;
			continue ;
		}
		ft_putchar_fd(format[index], 1);
		index++;
		str_count++;
	}
	va_end(arg_ptr);
	return (str_count);
}
