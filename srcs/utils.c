/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:01:25 by ielyatim          #+#    #+#             */
/*   Updated: 2025/03/03 14:13:30 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_error(void)
{
	ft_putstr_fd("❌ Error\n", 2);
	exit(1);
}

void	ft_kill(pid_t pid, int sig)
{
	int	out;

	out = kill(pid, sig);
	if (out == -1)
		ft_error();
}
