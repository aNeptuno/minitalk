/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:34:40 by adiban-i          #+#    #+#             */
/*   Updated: 2023/12/23 10:34:40 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	write_hexa(unsigned int n, int res, char *base)
{
	if (n >= 16)
	{
		res = write_hexa(n / 16, res, base);
		ft_putchar(base[n % 16]);
		res++;
	}
	if (n < 16)
	{
		ft_putchar(base[n % 16]);
		res++;
	}
	return (res);
}
