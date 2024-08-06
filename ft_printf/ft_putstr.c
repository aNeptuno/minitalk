/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:37:03 by adiban-i          #+#    #+#             */
/*   Updated: 2023/12/23 10:37:03 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putstr(char *s, int res)
{
	int	i;

	i = 0;
	if (!s)
	{
		res = ft_putstr("(null)", res);
		return (res);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		res++;
		i++;
	}
	return (res);
}
