/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:00 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/01 20:56:17 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_signal(int i)
{
	static int	bit;
	static int	nbr;

	if (i == SIGUSR1)
		nbr |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(nbr, 1);
		bit = 0;
		nbr = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

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
	while (1)
	{
		signal(SIGUSR1, receive_signal);
		signal(SIGUSR2, receive_signal);
		pause();
	}
	return (0);
}
