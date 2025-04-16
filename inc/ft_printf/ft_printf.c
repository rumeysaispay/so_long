/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rispay-s <rispay-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:38:32 by rispay-s          #+#    #+#             */
/*   Updated: 2024/11/23 17:24:32 by rispay-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	ft_check(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static int	ft_format(va_list arg, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format == 'p')
		return (ft_pointer(va_arg(arg, void *), 1));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (format == 'u')
		return (ft_unsigned(va_arg(arg, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_hex(va_arg(arg, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		len;
	int		result;

	i = -1;
	len = 0;
	va_start(arg, format);
	if (!format)
		return (-1);
	while (format[++i])
	{
		if (format[i] == '%' && ft_check(format[i + 1]))
		{
			result = ft_format(arg, format[++i]);
			if (result == -1)
				return (-1);
			len = len + result;
		}
		else if (format[i] != '%' && ft_putchar(format[i]) == -1)
			return (-1);
		else if (format[i] != '%')
			len++;
	}
	return (va_end(arg), len);
}
