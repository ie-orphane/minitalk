/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielyatim <ielyatim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:19:04 by ielyatim          #+#    #+#             */
/*   Updated: 2025/03/03 14:28:29 by ielyatim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include <signal.h>

void	ft_error(void);
void	ft_kill(pid_t pid, int sig);
int		ft_ultimate_atoi(char *number);

#endif // MAIN_H
