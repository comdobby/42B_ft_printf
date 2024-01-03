/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:48:14 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/03 23:55:08 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* library */
# include <unistd.h>
# include <stdarg.h>

/* macro*/
# define HEX_L "0123456789ABCDEF"
# define HEX_S "0123456789abcdef"

/* functions */
int	ft_printf(const char *str, ...);
int	check_condition(const char *str, va_list *args);

/* utils*/
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putptr(unsigned int ptr);
int	ft_puthex(unsigned int n, const char *base);
int	ft_putnbr_unsigned(unsigned int n);

#endif