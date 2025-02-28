/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:55:16 by ielyatim          #+#    #+#             */
/*   Updated: 2025/02/28 11:04:39 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		pid;

int	main(int argc, char **argv)
{
	short int	j;
	bool		bit;

	(void)argc;
	pid = ft_atoi(argv[1]);
	while (*argv[2])
	{
		j = 0;
		while (j < 8)
		{
			bit = (*argv[2] & (1 << j)) >> j;
			if (bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(400);
			j++;
		}
		argv[2]++;
	}
	return (0);
}
