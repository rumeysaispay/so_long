/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rispay-s <rispay-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:43:02 by rispay-s          #+#    #+#             */
/*   Updated: 2024/11/09 11:49:59 by rispay-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	c_char;

	c_char = (char)c;
	while (*s != '\0')
	{
		if (*s == c_char)
			return ((char *)s);
		s++;
	}
	if (c_char == '\0')
		return ((char *)s);
	return (NULL);
}
