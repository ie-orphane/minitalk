/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:01:25 by ielyatim          #+#    #+#             */
/*   Updated: 2025/03/03 14:33:34 by ielyatim         ###   ########.fr       */
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

static bool	ft_isnumeric(char *str)
{
	if (!*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

int	ft_ultimate_atoi(char *number)
{
	long	num;

	if (!ft_isnumeric(number + (number[0] == '+' || number[0] == '-')))
		ft_error();
	num = ft_atoi(number);
	if (num > INT_MAX || num < INT_MIN)
		ft_error();
	return (num);
}
