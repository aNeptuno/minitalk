/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:54:33 by adiban-i          #+#    #+#             */
/*   Updated: 2024/09/23 11:21:20 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_numeric(char *pid)
{
    int i;
    int is_num;

    i = 0;
    is_num = 1;
    while (pid[i] && is_num)
    {
        if (!ft_isdigit(pid[i]))
            is_num = 0;
        i++;
    }
    return (is_num);
}

static void    send_binary_msg(char c, int pid)
{
    int bit;
    
    bit = 0;
    while (bit < 8)
    {
        if (c & (1 << bit))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        bit++;
        usleep(1000);
    }
}
static void	action(int signum, siginfo_t *siginfo, void *context)
{
    (void)context;
    (void)siginfo;
    if (signum == SIGUSR1)
        ft_putstr_fd("\033[32m Server says: OK! recived SIGUSR1\033[0m\n", STDOUT_FILENO);
    else
        ft_putstr_fd("\033[33m Server says: OK! recived SIGUSR2\033[0m\n", STDOUT_FILENO);
}

int	main(int ac, char **av)
{
    int                 pid;
    struct sigaction	s_sa;

	s_sa.sa_sigaction = action;
	s_sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
    if (ac == 3 && is_numeric(av[1]))
    {
        pid = atoi(av[1]);
        while (*av[2])
        {
            send_binary_msg(*av[2], pid);
            av[2]++;
        }
        send_binary_msg('\0', pid);
    }
    else
    {
        ft_printf("\033[31m");
        ft_printf("Incorrect agruments\n");
        ft_printf("Usage: ./client (int)[PID] (string)[MSG]\n");
        ft_printf("\033[0m");
    }
    while (1)
		pause();
    return (0);
}