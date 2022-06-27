/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:56:28 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/09 18:58:33 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int signum)
{
	extern int	g_stats;

	if (signum == SIGINT)
		printf("^C\n");
	if (signum == SIGQUIT)
		printf ("^\\Quit: 3\n");
}

void	continue_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

void	signal_catch(int signum)
{
	if (rl_on_new_line() == -1)
		exit (-1);
	if (SIGINT == signum)
	{
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_redisplay();
		g_stats = 1;
	}
}

void	ft_signals(void)
{
	signal(SIGINT, signal_catch);
	signal(SIGQUIT, SIG_IGN);
}
