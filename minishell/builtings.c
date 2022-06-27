/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:49:58 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/24 19:25:09 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
{
	extern int	g_stats;
	char		*s;

	s = getcwd(NULL, 0);
	printf("%s\n", s);
	g_stats = 0;
	free (s);
}

int	ft_magic_nbr(int n, t_data *data)
{
	n = ft_atoi(data->commands->value);
	if (n > 256)
		n = n - 256 ;
	else if (n < 0)
		n = 256 + n;
	else if (n >= 500)
		n = n - 512;
	else if (n == 256 || n == 512)
		n = 0;
	return (n);
}

void	ft_exit(char *str, t_data *data)
{
	int	n;
	int	i;
	int	space;

	i = -1;
	n = 0;
	space = 0;
	if (data->commands->value)
	{
		while (data->commands->value[++i])
		{
			if (space >= 1)
			{
				g_stats = 1;
				printf("exit\nminishell: exit: too many arguments\n");
				return ;
			}
			if (ft_exit_end(data, i, &space))
				continue ;
		}
		n = ft_magic_nbr(n, data);
	}
	g_stats = n;
	free(str);
	exit(n);
}

t_data	*builtings(t_data *data, char *str)
{
	(void)str;
	if (ft_str_equals(data->commands->key, "pwd"))
		ft_pwd();
	else if (ft_str_equals(data->commands->key, "echo"))
		ft_echo(data);
	else if (ft_str_equals(data->commands->key, "env")
		&& !data->commands->value)
		print_dict(data->env);
	else if (ft_str_equals(data->commands->key, "history"))
		ft_read_file(".history", 0);
	else if (ft_str_equals(data->commands->key, "cd"))
		printf("");
	else
		ft_execve(data);
	return (data);
}

t_data	*redirections(t_data *data)
{
	int		temp_in;
	int		temp_out;
	int		i;
	t_dict	*temp;
	t_data	data_temp;

	temp_in = dup(0);
	temp_out = dup(1);
	i = -1;
	data_temp = *data;
	while (data_temp.redirections[++i])
	{
		temp = data_temp.redirections[i];
		while (temp)
		{
			if (ft_str_equals(temp->value, "") || !temp->value)
			{
				printf("minishell: syntax error near unexpected token\n");
				return (data);
			}
			temp = temp->next;
		}
	}
	redirections_aux(data, 0, temp_in, temp_out);
	return (data);
}
