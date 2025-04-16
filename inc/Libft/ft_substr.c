/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rispay-s <rispay-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:21:46 by rispay-s          #+#    #+#             */
/*   Updated: 2024/11/01 14:31:26 by rispay-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	s_len;
	size_t	cpy_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (ft_strlen(s + start) > len)
		cpy = (char *)malloc(sizeof(char) * (len + 1));
	else
		cpy = (char *)malloc(ft_strlen(s + start) + 1);
	if (cpy == NULL)
		return (NULL);
	cpy_len = 0;
	while (s[start] != '\0' && cpy_len < len)
	{
		cpy[cpy_len] = s[start];
		cpy_len++;
		start++;
	}
	cpy[cpy_len] = '\0';
	return (cpy);
}
