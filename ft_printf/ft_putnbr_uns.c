/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:32:17 by adiban-i          #+#    #+#             */
/*   Updated: 2023/12/23 10:32:17 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putnbr_uns(unsigned int u, int res)
{
	res++;
	if (u > 9)
	{
		res = ft_putnbr_uns(u / 10, res);
		ft_putchar(u % 10 + '0');
	}
	if (u <= 9)
		ft_putchar(u + '0');
	return (res);
}
