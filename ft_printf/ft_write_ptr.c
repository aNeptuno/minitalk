/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:38:09 by adiban-i          #+#    #+#             */
/*   Updated: 2023/12/23 10:38:09 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	write_nibble(unsigned long nibble, int res)
{
	if (nibble < 10)
		ft_putchar(nibble + '0');
	else
		ft_putchar(nibble - 10 + 'a');
	res++;
	return (res);
}

int	write_ptr(void *ptr, int res)
{
	unsigned long	addr;
	unsigned long	nibble;
	int				shift;
	int				flag;

	flag = 0;
	write(1, "0x", 2);
	res += 2;
	if (ptr == 0)
	{
		ft_putchar('0');
		return (++res);
	}
	addr = (unsigned long)ptr;
	shift = sizeof(void *) * 8 - 4;
	while (shift >= 0)
	{
		nibble = (addr >> shift) & 0xF;
		if (nibble != 0)
			flag = 1;
		if (flag)
			res = write_nibble(nibble, res);
		shift -= 4;
	}
	return (res);
}
