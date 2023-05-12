/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:09:32 by frgutier          #+#    #+#             */
/*   Updated: 2022/12/08 18:10:00 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>

static void	server_signal_handler(int server_signal)
{
	static int	signals_received = 0;

	if (server_signal == SIGUSR1)
		signals_received++;
	else
	{
		ft_printf("%d\n", signals_received);
		exit(0);
	}
}

static void	send_string(int pid, char *str)
{
	int		bit;
	char	c;

	while (*str)
	{
		bit = 8;
		c = *str++;
		while (bit--)
		{
			if (c >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_printf("Caracteres enviados : %d\n", ft_strlen(argv[2]));
	ft_printf("Caracteres recibidos: ");
	signal(SIGUSR1, server_signal_handler);
	signal(SIGUSR2, server_signal_handler);
	send_string(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
