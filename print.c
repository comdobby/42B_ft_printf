/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:42:47 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/07 20:42:33 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int c, int *count)
{
	*count += write(1, &c, 1);
}

void	print_str(const char *s, int *count)
{
	if (!s)
	{
		print_str(NULL_STR, count);
		return ;
	}
	while (*s)
	{
		*count += write(1, &(*s), 1);
		s++;
	}
}

void	print_nbr(t_ll n, const char *base, int *count)
{
	if (n < 0)
	{
		*count += write(1, "-", 1);
		n = -n;
	}
	if (n >= (t_ll)ft_strlen(base))
		print_nbr(n / ft_strlen(base), base, count);
	*count += write(1, &base[n % ft_strlen(base)], 1);
}

void	print_unsigned_nbr(t_ull n, const char *base, int *count)
{
	if (n >= ft_strlen(base))
		print_unsigned_nbr(n / ft_strlen(base), base, count);
	*count += write(1, &base[n % ft_strlen(base)], 1);
}

void	print_ptr(void *p, int *count)
{
	if (!p)
	{
		print_str(NULL_PTR, count);
		return ;
	}
	*count += write(1, "0x", 2);
	print_unsigned_nbr((t_ull)p, HEXL, count);
}
