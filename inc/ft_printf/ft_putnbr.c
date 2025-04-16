/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rispay-s <rispay-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:23:32 by rispay-s          #+#    #+#             */
/*   Updated: 2024/11/23 12:56:03 by rispay-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		len;
	long	num;
	int		result;

	num = n;
	len = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		num *= -1;
		len++;
	}
	if (num > 9)
	{
		result = ft_putnbr(num / 10);
		if (result == -1)
			return (-1);
		len += result;
	}
	if (ft_putchar("0123456789"[num % 10]) == -1)
		return (-1);
	return (len + 1);
}
