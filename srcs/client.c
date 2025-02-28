/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:55:16 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/28 11:34:02 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		pid;

void	byte_send(char byte)
{
	short int	j;

	j = 0;
	while (j < 8)
	{
		if ((byte & (1 << j)) >> j)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		j++;
	}
}

void	sighandler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Message received by server\n");
}

int	main(int argc, char **argv)
{
	(void)argc;
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, sighandler);
	while (true)
	{
		byte_send(*argv[2]);
		if (!*argv[2])
			break ;
		argv[2]++;
	}
	return (0);
}
