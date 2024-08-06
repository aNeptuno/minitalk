/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:54:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/06 14:57:31 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_header(void)
{
	ft_printf("\n\033[34m /******************************************/ \n");
	ft_printf(" /*     Welcome to adiban-i server B)      */ \n");
	ft_printf(" /*                                        */ \n");
	ft_printf(" /*\033[33m     Server running with PID: %d \033[34m    */\n",
		getpid());
	ft_printf("\033[34m /*                                        */\n");
	ft_printf(" /******************************************/  \033[0m\n\n");
}

void	action(int signum, siginfo_t *siginfo, void *context)
{
	if (signum == SIGUSR1)
		ft_putstr_fd("Recived SIGUSR1 = 1\n", STDOUT_FILENO);
	else
		ft_putstr_fd("Recived SIGUSR2 = 0\n", STDOUT_FILENO);
}

int main()
{
	struct sigaction	s_sa;

	s_sa.sa_sigaction = action;
	s_sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	print_header();
	while (1)
		pause();
	return (0);
}
