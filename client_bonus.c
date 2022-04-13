/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntojamur <ntojamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:11:08 by ntojamur          #+#    #+#             */
/*   Updated: 2022/03/10 19:49:51 by ntojamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

static void	ft_handler(int sig, siginfo_t *siginfo, void *uncontex)
{
	(void)siginfo;
	(void)uncontex;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("\033[1;32m", 1);
		ft_putstr_fd("The data has been received.\n", 1);
		ft_putstr_fd("\033[0m", 1);
	}
	exit(0);
}

static void	ft_send(int pid, char *str)
{
	int		i;
	size_t	j;

	j = 0;
	while (j <= ft_strlen(str))
	{
		i = 128;
		while (i)
		{
			if (i & str[j])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			i /= 2;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	for_signal;

	if (argc != 3)
		return (1);
	for_signal.sa_sigaction = ft_handler;
	for_signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &for_signal, 0);
	ft_send(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
