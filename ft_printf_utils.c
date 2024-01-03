/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:58:06 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/03 23:56:10 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		length += ft_putchar(s[i]);
		i++;
	}
	return (length);
}

int	ft_putptr(unsigned int ptr)
{
	int	length;

	length = 0;
	length += ft_putstr("0x");
	length += ft_puthex(ptr, HEX_S);
	return (length);
}

int	ft_putnbr(int n)
{
	int		length;

	length = 0;
	if (n == -2147483648)
		length += ft_putstr("-2147483648");
	else if (n < 0)
	{
		length += ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 0 && n <= 9)
		length += ft_putchar(n + '0');
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		length += ft_putchar(n % 10 + '0');
	}
	return (length);
}

int	ft_puthex(unsigned int n, const char *base)
{
	int		length;

	length = 0;
	if (n > 15)
	{
		ft_puthex(n / 16, base);
		length += ft_putchar(base[n % 16]);
	}
	length += ft_putchar(base[n]);
	return (length);
}
