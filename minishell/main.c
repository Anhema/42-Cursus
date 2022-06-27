/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:05:56 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/24 19:22:22 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit_end(t_data *data, int i, int *space)
{
	if (data->commands->value[i] == '-')
		return (1);
	if (data->commands->value[i] == ' ')
	{
		++*space;
		return (1);
	}
	if (data->commands->value[i] < 47
		|| data->commands->value[i] > 57)
	{
		printf("exit\n");
		printf("minishell: %s: numeric argument required\n",
			data->commands->value);
		exit(255);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	extern int	g_stats;
	char		*str;
	t_data		*data;

	(void)argc;
	(void)argv;
	g_stats = 0;
	data = malloc(sizeof(t_data));
	data->env = create_env(envp);
	data->usr = ft_strdup(get_dict_value(data->env, "USER"));
	data->is_redir = 0;
	data->commands = NULL;
	data->prompt = NULL;
	data->redirections = NULL;
	data->infile_error = 0;
	data->str = NULL;
	data->fd[0] = 0;
	data->fd[1] = 1;
	str = ft_readline(data);
	while (1)
		str = minishell_loop(data, str);
	return (0);
}
