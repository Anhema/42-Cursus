/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expantions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:55:58 by cbustama          #+#    #+#             */
/*   Updated: 2022/06/24 17:43:41 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_execve(int status)
{
	extern int	g_stats;

	if (WIFEXITED(status))
		g_stats = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2)
			g_stats = 130;
		else if ((WTERMSIG(status) == 3))
			g_stats = 131;
	}
}

void	print_expantions(void)
{
	g_stats = 127;
	printf("%d: command not found\n", g_stats);
}
