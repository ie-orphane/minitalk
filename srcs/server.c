/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:55:20 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/28 11:11:03 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sighandler(int signum, siginfo_t *info, void *ctx)
{
	static int		count;
	static char		byte;
	static pid_t	pid;

	(void)ctx;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		count = 0;
		byte = 0;
	}
	if (signum == SIGUSR1)
		byte |= 1 << count;
	count++;
	if (count == 8)
	{
		ft_printf("%c", byte);
		count = 0;
		byte = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("PID : %d\n\n", pid);
	action.sa_sigaction = sighandler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (true)
		pause();
	return (0);
}
