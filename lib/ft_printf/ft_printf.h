/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:29:38 by skang             #+#    #+#             */
/*   Updated: 2024/12/03 15:33:10 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr_base(int nbr, char *base);
int	ft_putnbr_addr_base(uintptr_t nbr, char *base);
int	ft_putnbr_unsigned_base(unsigned int nbr, char *base);

int	print_int(va_list arg_ptr);
int	print_char(va_list arg_ptr);
int	print_str(va_list arg_ptr);
int	print_x(va_list arg_ptr, char x_type);
int	print_i(va_list arg_ptr);
int	print_addr(va_list arg_ptr);
int	print_u(va_list arg_ptr);
int	print_percent(void);

#endif
