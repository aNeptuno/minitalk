/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:54:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/09/23 11:46:41 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

t_server_state	g_state = {0, 0, -1, 0, {0}};

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

static void	print_msg(void)
{
	g_state.message[g_state.msg_length - 1] = '\n';
	ft_printf("\033[35m");
	ft_putstr_fd(g_state.message, STDOUT_FILENO);
	ft_printf("\033[0m");
	g_state.current_client = -1;
	g_state.msg_length = 0;
	g_state.bit_count = 0;
	g_state.current_char = 0;
	ft_memset(g_state.message, '\0', sizeof(g_state.message));
}

static void	action(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	g_state.bit_count++;
	if (g_state.current_client == -1)
		g_state.current_client = siginfo->si_pid;
	if (g_state.current_client != siginfo->si_pid)
		return ;
	if (signum == SIGUSR1)
		g_state.current_char |= (1 << (g_state.bit_count - 1));
	if (g_state.bit_count == 8)
	{
		g_state.message[g_state.msg_length] = g_state.current_char;
		g_state.msg_length++;
		if (g_state.current_char == '\0')
		{
			print_msg();
			return ;
		}
		g_state.bit_count = 0;
		g_state.current_char = 0;
	}
	kill(siginfo->si_pid, signum);
}

int	main(void)
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
