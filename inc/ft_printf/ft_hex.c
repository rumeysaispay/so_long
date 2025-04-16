/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rispay-s <rispay-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:09:53 by rispay-s          #+#    #+#             */
/*   Updated: 2024/11/23 16:06:13 by rispay-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int n, char format)
{
	int	result;
	int	len;

	len = 0;
	if (n >= 16)
	{
		result = ft_hex(n / 16, format);
		if (result == -1)
			return (-1);
		len += result;
	}
	if (format == 'x')
	{
		if (ft_putchar("0123456789abcdef"[n % 16]) == -1)
			return (-1);
	}
	if (format == 'X')
	{
		if (ft_putchar("0123456789ABCDEF"[n % 16]) == -1)
			return (-1);
	}
	return (len + 1);
}
