/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:07:00 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/02 22:57:44 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	response(int result)
{
	if (result == SIGUSR1)
		ft_putstr_fd("\033[0;31mKO\033[0m\n", 1);
	else
		ft_putstr_fd("\033[0;32mOK\033[0m\n", 1);
}

static void	send_char_to_server(unsigned char c, int server_pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	pid = 0;
	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == -1 || !pid || argv[2][0] == '\0')
			return (0);
		while (argv[2][i])
		{
			signal(SIGUSR1, response);
			signal(SIGUSR2, response);
			send_char_to_server(argv[2][i], pid);
			i++;
		}
		send_char_to_server('\n', pid);
	}
	else
		ft_putstr_fd("\033[0;31mInvalid format:\033[0m ./client [PID] [STR]\n", 1);
	return (0);
}
