/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:41:28 by adiban-i          #+#    #+#             */
/*   Updated: 2023/12/16 11:41:28 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

#include <stdio.h>

static int	parse_format(char const *format, va_list args, int i, int res)
{
	if (format[i] == 'd' || format[i] == 'i')
		res = ft_putnbr_int(va_arg(args, int), res);
	if (format[i] == 'u')
		res = ft_putnbr_uns(va_arg(args, unsigned int), res);
	if (format[i] == 'c')
	{
		ft_putchar(va_arg(args, int));
		res++;
	}
	if (format[i] == '%')
	{
		ft_putchar('%');
		res++;
	}
	if (format[i] == 's')
		res = ft_putstr(va_arg(args, char *), res);
	if (format[i] == 'x')
		res = write_hexa(va_arg(args, int), res, "0123456789abcdef");
	if (format[i] == 'X')
		res = write_hexa(va_arg(args, int), res, "0123456789ABCDEF");
	if (format[i] == 'p')
		res = write_ptr(va_arg(args, void *), res);
	return (res);
}

int	ft_printf(char const *format, ...)
{
	int		res;
	va_list	args;
	int		i;

	res = 0;
	i = 0;
	va_start(args, format);
	if (write(1, "", 0) < 0)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
			res = parse_format(format, args, ++i, res);
		else
		{
			res++;
			ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (res);
}
