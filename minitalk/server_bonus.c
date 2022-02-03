/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:00 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/02 22:59:29 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_signal(int i, siginfo_t *info, void *context)
{
	static int	bit;
	static int	nbr;

	(void)info;
	(void)context;
	if (i == SIGUSR1)
		nbr |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(nbr, 1);
		bit = 0;
		nbr = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	s_action;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("\033[0;31mInvalid format:\033[0m ./server\n", 1);
		return (0);
	}
	pid = getpid();
	ft_putstr_fd("\033[0;32mSERVER PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\033[0m\n\033[0;33mMessages:\033[0m\n\n", 1);
	s_action.sa_sigaction = receive_signal;
	sigemptyset(&s_action.sa_mask);
	s_action.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &s_action, NULL);
		sigaction(SIGUSR2, &s_action, NULL);
		pause();
	}
	return (0);
}
