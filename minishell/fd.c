/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:00:01 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/24 17:44:13 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*heredoc(t_data *data, t_dict *temp)
{
	int		in;
	char	*str;

	data->is_redir = 1;
	str = ft_readline_heredoc(data);
	in = open(".redir", O_WRONLY | O_APPEND | O_CREAT, 0000644);
	while (1)
	{
		if (ft_str_equals(str, temp->value))
			break ;
		if (in < 0)
		{
			perror("minishell:");
			break ;
		}
		else
		{
			ft_putstr_fd(str, in);
			ft_putstr_fd("\n", in);
			str = ft_readline_heredoc(data);
		}
	}
	close(in);
	data->is_redir = 0;
	return (".redir");
}

t_data	*redirections_fd(t_data *data, int fd_in, int temp_out, int j)
{
	int		fd_out;
	int		outfile;

	fd_out = 0;
	dup2(fd_in, 0);
	close(fd_in);
	if (data->commands)
	{
		if (!data->commands->next)
			fd_out = dup(temp_out);
		else
		{
			pipe(data->fd);
			fd_out = data->fd[1];
		}	
	}
	outfile = check_outfile(data, j);
	if (outfile > 2)
		fd_out = outfile;
	dup2(fd_out, 1);
	close(fd_out);
	return (data);
}

static t_data	*get_infd(t_data *data, int j, int fd_in, int temp_in)
{
	char	*infile;

	infile = check_infile(data, j);
	if (infile)
	{
		if (ft_str_equals(infile, "1_"))
			data->fd_aux = fd_in;
		else
			data->fd_aux = open(infile, O_RDONLY, 0000644);
	}
	else
	{
		if (j == 0)
			data->fd_aux = dup(temp_in);
	}
	return (data);
}

t_data	*redirections_loop(t_data *data, int *pid)
{
	continue_signal();
	*pid = fork();
	if (*pid == 0)
	{
		data = builtings(data, data->str);
		exit (g_stats);
	}
	dup2(data->fd[1], 1);
	close(data->fd[1]);
	data->commands = data->commands->next;
	return (data);
}

void	redirections_aux(t_data *data, int fd_in, int temp_in, int temp_out)
{
	int		status;
	int		j;
	int		pid;
	t_data	data_temp;

	pid = 0;
	status = 0;
	data_temp = *data;
	if (!data_temp.commands)
	{
		data_temp = *get_infd(&data_temp, 0, fd_in, temp_in);
		data_temp = *redirections_fd(&data_temp, fd_in, temp_in, 0);
	}
	j = 0;
	while (data_temp.commands)
	{
		data_temp = *get_infd(&data_temp, j, fd_in, temp_in);
		data_temp = *redirections_fd(&data_temp, data_temp.fd_aux, temp_out, j);
		data_temp = *redirections_loop(&data_temp, &pid);
		j++;
	}
	end_redirections_aux(temp_in, temp_out, pid, status);
	if (open(".redir", O_RDONLY, 0000644) >= 0)
		unlink(".redir");
}
