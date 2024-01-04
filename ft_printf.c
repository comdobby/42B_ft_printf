/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:47:58 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/04 15:26:39 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	condition(const char *s, va_list *args, int *count)
{
	if (*s == 'c')
		print_char((char)va_arg(*args, int), count);
	else if (*s == 's')
		print_str(va_arg(*args, char *), count);
	else if (*s == 'p')
		print_ptr(va_arg(*args, void *), count);
	else if (*s == 'd' || *s == 'i')
		print_nbr(va_arg(*args, int), DEC, count);
	else if (*s == 'u')
		print_nbr(va_arg(*args, unsigned int), DEC, count);
	else if (*s == 'x')
		print_nbr(va_arg(*args, unsigned int), HEXS, count);
	else if (*s == 'X')
		print_nbr(va_arg(*args, unsigned int), HEXL, count);
	else if (*s == '%')
		print_char('%', count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = -1;
	count = 0;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]))
			condition(&s[++i], &args, &count);
		else
			count += write(1, &s[i], 1);
	}
	va_end(args);
	return (count);
}

/*
#include <stdio.h>
#include <limits.h>
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
	printf("----------------------\n");
	printf("%p\n", (void *)LONG_MIN);
	printf("%p\n", (void *)LONG_MAX);
	ft_printf("%p\n", (void *)LONG_MIN);
	ft_printf("%p\n", (void *)LONG_MAX);
	printf("----------------------\n");
	printf("%p %p \n", (void *)0, (void *)0);
	ft_printf("%p %p \n", (void *)0, (void *)0);
	printf("----------------------\n");
	return (0);
}*/