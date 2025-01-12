/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:22:43 by skang             #+#    #+#             */
/*   Updated: 2024/11/19 18:13:12 by skang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	str_len(char *str)
{
	int	count;

	count = 0;
	while (*(str++))
		count++;
	return (count);
}

static int	is_valid(char *str)
{
	int		len;
	int		i;
	int		j;
	char	c;

	len = str_len(str);
	if (len == 0 || len == 1)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		j = 0;
		while (str[j] != '\0')
		{
			if (j != i && str[j] == c)
				return (0);
			if ((str[j] == '-' || str[j] == '+'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_recursion(long n, char *base, int len, int *count)
{
	long	mod;

	*count = *count + 1;
	mod = n % len;
	if (n >= len)
	{
		ft_recursion(n / len, base, len, count);
		write(1, &base[mod], 1);
		return ;
	}
	write(1, &base[mod], 1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	int		count;
	long	num;

	count = 0;
	len = str_len(base);
	if (!is_valid(base))
		return (0);
	num = nbr;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		count++;
	}
	ft_recursion(num, base, len, &count);
	return (count);
}
