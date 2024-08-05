/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:54:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/05 14:20:16 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

void	handle_sigusr1(int sig)
{
	ft_putstr_fd("Recived SIGUSR1\n", STDOUT_FILENO);
}

int main()
{
	signal(SIGUSR1, handle_sigusr1);
	while (1)
	{
		ft_putstr_fd("Waiting for signals...\n", STDOUT_FILENO);
		sleep(10);
	}
	return (0);
}
