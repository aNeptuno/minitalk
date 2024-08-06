/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:30:43 by adiban-i          #+#    #+#             */
/*   Updated: 2023/12/23 10:30:43 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putnbr_int(int d, int res)
{
	res++;
	if (d == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		res += 2;
		d = 147483648;
	}
	if (d < 0)
	{
		ft_putchar('-');
		res++;
		d = -d;
	}
	if (d > 9)
	{
		res = ft_putnbr_int(d / 10, res);
		ft_putchar(d % 10 + '0');
	}
	if (d <= 9)
		ft_putchar(d + '0');
	return (res);
}
