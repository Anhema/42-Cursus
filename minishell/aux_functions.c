/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:41:29 by cbustama          #+#    #+#             */
/*   Updated: 2022/06/24 17:43:15 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*aux_get_path(char **paths, char *path)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		if (access(paths[i], F_OK) == 0)
		{		
			path = ft_strdup(paths[i]);
			free_split_double(paths);
			return (path);
		}
		i++;
	}
	return (path);
}

void	free_data_readline_two(t_data *data)
{
	int	i;

	i = 0;
	if (data->prompt)
		free(data->prompt);
	if (data->commands)
		delete_all(data->commands);
	if (data->redirections)
	{
		i = 0;
		while (i <= data->rediretions_conut)
		{
			delete_all(data->redirections[i]);
			i++;
		}
		free(data->redirections);
	}
}

void	free_data_readline(t_data *data)
{
	data->commands = NULL;
	data->redirections = NULL;
	data->str = NULL;
	data->fd[0] = 0;
	data->fd[1] = 1;
}

char	*aux_replace_redirections(char *str, char *temp, char c, int n)
{
	int	j;
	int	i;

	j = 0;
	n = 0;
	i = -1;
	while (str[++i])
	{
		n = replace_aux(n, &c, str, j);
		if (n == 0)
		{
			temp[j] = replace_char(str, i, n);
			if (temp[j] == -126 || temp[j] == -125)
				i++;
		}
		else
			temp[j] = str[i];
		j++;
	}
	return (temp);
}

void	end_redirections_aux(int temp_in, int temp_out, int pid, int status)
{
	dup2(temp_in, 0);
	dup2(temp_out, 1);
	close(temp_out);
	close(temp_in);
	waitpid(pid, &status, 0);
	expand_execve(status);
}
