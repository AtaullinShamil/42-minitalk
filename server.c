/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:42:47 by ntojamur          #+#    #+#             */
/*   Updated: 2022/03/10 18:52:16 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

static void	ft_handler(int sig, siginfo_t *siginfo, void *uncontex)
{
	static int	size = 0;
	static char	c = 0;
	static int	client_pid = 0;

	(void)uncontex;
	if (!client_pid || client_pid != siginfo->si_pid)
	{
		client_pid = siginfo->si_pid;
		size = 0;
		c = 0;
	}
	c |= (sig == SIGUSR1);
	size++;
	if (size == 8)
	{
		write(1, &c, 1);
		size = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	for_signal;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	for_signal.sa_sigaction = ft_handler;
	for_signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &for_signal, 0);
	sigaction(SIGUSR2, &for_signal, 0);
	while (1)
		pause();
	return (0);
}
