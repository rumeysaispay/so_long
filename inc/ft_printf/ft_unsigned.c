/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rispay-s <rispay-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:52:28 by rispay-s          #+#    #+#             */
/*   Updated: 2024/11/23 17:22:23 by rispay-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int n)
{
	int		len;
	int		result;

	len = 0;
	if (n >= 10)
	{
		result = ft_unsigned(n / 10);
		if (result == -1)
			return (-1);
		len += result;
	}
	if (ft_putchar("0123456789"[n % 10]) == -1)
		return (-1);
	return (len + 1);
}
