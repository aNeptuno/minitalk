/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:41:51 by adiban-i          #+#    #+#             */
/*   Updated: 2023/12/16 11:41:51 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *format, ...);
void	ft_putchar(char c);
int		ft_putnbr_int(int d, int res);
int		ft_putnbr_uns(unsigned int u, int res);
int		write_hexa(unsigned int n, int res, char *base);
int		ft_putstr(char *s, int res);
int		write_ptr(void *ptr, int res);

#endif
