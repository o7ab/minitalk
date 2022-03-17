/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:27:11 by oabushar          #+#    #+#             */
/*   Updated: 2022/03/17 16:21:09 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(n + 48, fd);
		return ;
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

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
	write (1, "The Server PID is: \n", 21);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &dumbasss, NULL);
	sigaction(SIGUSR2, &dumbasss, NULL);
	while (1)
		pause();
	return (0);
}
