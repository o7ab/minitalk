/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:27:11 by oabushar          #+#    #+#             */
/*   Updated: 2022/02/23 14:26:33 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

void	ft_receive(int sig, siginfo_t *info, void *boop)
{
	static char	c;
	static int	bit;

	boop = NULL;
	usleep(50);
	kill (info->si_pid, SIGUSR2);
	if (sig == SIGUSR1)
		c = c | 1;
	bit++;
	if (bit == 8)
	{
		write (1, &c, 1);
		bit = 0;
		c = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	dumbasss;

	dumbasss.sa_sigaction = &ft_receive;
	dumbasss.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putstr_fd("The Server PID is: \n", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &dumbasss, NULL);
	sigaction(SIGUSR2, &dumbasss, NULL);
	while (1)
		pause();
	return (0);
}
