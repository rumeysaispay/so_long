/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rispay-s <rispay-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:31:12 by rispay-s          #+#    #+#             */
/*   Updated: 2024/11/05 15:48:45 by rispay-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;

	a = (char *)dst;
	b = (char *)src;
	if ((dst == NULL) && (src == NULL))
		return (NULL);
	if (a < b)
	{
		while (len--)
			*a++ = *b++;
	}
	if (a > b)
	{
		while (len--)
		{
			a[len] = b[len];
		}
	}
	return (dst);
}
