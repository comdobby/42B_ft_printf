/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:47:58 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/04 00:05:35 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_condition(const char *str, va_list *args)
{
	int		length;

	length = 0;
	if (*str == 'c')
		length += ft_putchar((char)va_arg(*args, int));
	else if (*str == 's')
		length += ft_putstr(va_arg(*args, char *));
	else if (*str == 'p')
		length += ft_putptr(va_arg(*args, unsigned int));
	else if (*str == 'd' || *str == 'i')
		length += ft_putnbr(va_arg(*args, int));
	else if (*str == 'u')
		length += ft_putnbr_unsigned(va_arg(*args, unsigned int));
	else if (*str == 'x')
		length += ft_puthex(va_arg(*args, unsigned int), HEX_S);
	else if (*str == 'X')
		length += ft_puthex(va_arg(*args, unsigned int), HEX_L);
	else if (*str == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = -1;
	length = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
			length += check_condition(&str[++i], &args);
		else
			length += ft_putchar(str[i]);
	}
	va_end(args);
	return (length);
}

/*
#include <stdio.h>
int	main(void)
{
	int	ori;
	int	my;
	
	char *s1 = "here is\n";
	int hex = 155;
	int d = -1;
	int	i = 1010;

	printf("----------------------\n");
	ori = printf("%s", s1);
	my = printf("%s", s1);
	printf("----------------------\n");
	printf("%d\n", ori);
	printf("%d\n", my);
	printf("----------------------\n");
	ori = printf("%d\n", d);
	my = printf("%d\n", d);
	printf("%d\n", ori);
	printf("%d\n", my);
	printf("----------------------\n");
	ori = printf("%x\n", hex);
	my = printf("%x\n", hex);
	printf("----------------------\n");
	ft_printf("%s\n", "toto");
	printf("%s\n", "toto");
	printf("----------------------\n");
	ft_printf("Magic %s is %d\n", "number", 42);
	printf("Magic %s is %d\n", "number", 42);
	printf("----------------------\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("----------------------\n");
	ft_printf("i is %i\n", i);
	printf("i is %i\n", i);
	return (0);
}*/