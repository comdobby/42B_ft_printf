/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:48:14 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/04 15:18:57 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* library */
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

/* macro*/
# define HEXL	"0123456789ABCDEF"
# define HEXS	"0123456789abcdef"
# define DEC	"0123456789"
# define NULL_STR	"(null)"
# define NULL_PTR	"(nil)"

typedef long long			t_ll;
typedef unsigned long long	t_ull;

/* libft */
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

/* print */
void	print_ptr(void *p, int *count);
void	print_unsigned_nbr(t_ull n, const char *base, int *count);
void	print_nbr(t_ll n, const char *base, int *count);
void	print_str(const char *s, int *count);
void	print_char(int c, int *count);

/* printf */
int		ft_printf(const char *s, ...);

#endif