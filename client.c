/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamil <shamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:43:05 by ntojamur          #+#    #+#             */
/*   Updated: 2022/03/10 03:17:30 by shamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

static void	ft_send(int pid, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
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
	if (argc != 3)
		return (1);
	ft_send(ft_atoi(argv[1]), argv[2]);
	return (0);
}
