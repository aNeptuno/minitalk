/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:54:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/09/23 10:41:18 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
t_server_state	s_state = {0, 0, -1};

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

static void	action(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	s_state.bit_count++;
	
	if (s_state.current_client == -1)
		s_state.current_client = siginfo->si_pid;
	if (s_state.current_client != siginfo->si_pid)
		return;

	if (signum == SIGUSR1)
	{
		s_state.current_char |= (1 << (s_state.bit_count - 1));
	}
	if (s_state.bit_count == 8)
	{
		ft_printf("\033[35m");
		ft_putchar_fd(s_state.current_char, STDOUT_FILENO);
		ft_printf("\033[0m");
		if (s_state.current_char == '\n')
        {
            s_state.current_client = -1;
        }
		s_state.bit_count = 0;
		s_state.current_char = 0;
	}
	kill(siginfo->si_pid, signum);
}

int main()
{
	struct sigaction	s_sa;

	s_sa.sa_sigaction = action;
	s_sa.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sa.sa_mask);
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	print_header();
	while (1)
		pause();
	return (0);
}
