/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:17:33 by cbustama          #+#    #+#             */
/*   Updated: 2022/06/23 21:27:09 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_split_double(char **temp)
{
	int	i;

	i = -1;
	if (!temp)
		return ;
	while (temp[++i])
		free(temp[i]);
	free(temp);
	temp = NULL;
}

char	*pipe_errors_aux(char *str)
{
	if (str[0] == '|')
	{
		if (str[1] == '|')
			printf("minishell: syntax error near unexpected token `||'\n");
		else
			printf("minishell: syntax error near unexpected token `|'\n");
		g_stats = 258;
		free (str);
		return (NULL);
	}
	return (str);
}
