/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:54:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/06 12:42:48 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

void	handle_sigusr1(int sig)
{
	ft_putstr_fd("Recived SIGUSR1\n", STDOUT_FILENO);
}

int main()
{
	signal(SIGUSR1, handle_sigusr1);
	ft_printf("Server running with PID: %d\n", getpid());
	while (1)
	{
		ft_putstr_fd("Waiting for signals...\n", STDOUT_FILENO);
		sleep(10);
	}
	return (0);
}
