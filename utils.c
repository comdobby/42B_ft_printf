/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:58:06 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/04 15:20:37 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * The strchr() function returns a pointer to the first occurrence of the
 * character c in the string s.
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == '\0' && (char)c != '\0')
		return (NULL);
	return ((char *)s);
}

/**
 * The strlen() function calculates the length of the string pointed to
 * bytes, excluding the terminating null byte ('\0').
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
