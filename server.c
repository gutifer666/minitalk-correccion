/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:57:32 by frgutier          #+#    #+#             */
/*   Updated: 2022/12/08 18:25:12 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<signal.h>
#include "libft/libft.h"

static	void	client_signal_handler(int sig, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++bit == 7)
	{
		bit = 0;
		if (!c)
		{
			client_pid = 0;
			return ;
		}
		ft_printf("%c", c);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("Server PID: %d\n", getpid());
	s_sigaction.sa_sigaction = client_signal_handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
