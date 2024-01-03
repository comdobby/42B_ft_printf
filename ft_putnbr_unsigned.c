/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:42:47 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/03 23:45:37 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int		length;

	length = 0;
	if (n >= 0 && n <= 9)
		length += ft_putchar(n + '0');
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		length += ft_putchar(n % 10 + '0');
	}
	return (length);
}
