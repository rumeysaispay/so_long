/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rispay-s <rispay-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:10:02 by rispay-s          #+#    #+#             */
/*   Updated: 2024/11/23 17:39:15 by rispay-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_handlenull(void)
{
	if (write(1, "(nil)", 5) == -1)
		return (-1);
	return (5);
}

int	ft_pointer(void *ptr, int i)
{
	unsigned long	c;
	int				result;
	int				len;

	if (ptr == NULL)
		return (ft_handlenull());
	c = (unsigned long)ptr;
	len = 0;
	if (i)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		len += 2;
	}
	if (c >= 16)
	{
		result = ft_pointer((void *)(c / 16), 0);
		if (result == -1)
			return (-1);
		len += result;
	}
	if (ft_putchar("0123456789abcdef"[c % 16]) == -1)
		return (-1);
	return (len + 1);
}
