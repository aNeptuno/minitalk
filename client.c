/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:54:33 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/06 14:35:18 by adiban-i         ###   ########.fr       */
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

static void    send_binary_msg(char *c, int pid)
{
    int bit;
    
    bit = 0;
    while (bit < 8)
    {
        if (c && (1 << bit))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        bit++;
        usleep(100);
    }
}

int	main(int ac, char **av)
{
    int     pid;

    if (ac == 3 && is_numeric(av[1]))
    {
        pid = atoi(av[1]);
        while (*av[2])
        {
            send_binary_msg(av[2], pid);
            av[2]++;
        }
    }
    else
    {
        ft_printf("Incorrect agruments\n");
        ft_printf("Usage: ./client (int)[PID] (string)[MSG]\n");
    }
    return (0);
}