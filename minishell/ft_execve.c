/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:41:22 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/24 17:40:55 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**aux_join_env(char **env, t_dict *temp, int j)
{
	char	*tmp;

	while (temp)
	{
		tmp = ft_strjoin(temp->key, "=");
		env[j] = tmp;
		env[j] = ft_strjoin(tmp, temp->value);
		temp = temp->next;
		free(tmp);
		j++;
	}
	env[j] = NULL;
	return (env);
}

char	**join_env(t_dict *d_env)
{
	char	**env;
	int		i;
	int		j;
	t_dict	*temp;

	temp = d_env;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	env = malloc(sizeof(char *) * (i + 1));
	temp = d_env;
	j = 0;
	env = aux_join_env(env, temp, j);
	return (env);
}

static char	**execv_aux(t_data *data, char **temp, char *key, char **argv)
{
	if (!temp)
	{
		argv = malloc(sizeof(char *) * 3);
		argv[0] = key;
		argv[1] = data->commands->value;
		argv[2] = NULL;
	}
	return (argv);
}

static void	aux_execve_free(char **temp, char **argv, char **env, char *path)
{
	free_split_double(temp);
	if (argv)
		free(argv);
	free_split_double(env);
	if (path)
		free(path);
}

void	ft_execve(t_data *data)
{
	char	**temp;
	char	**argv;
	char	**env;
	char	*path;
	char	*key;

	argv = NULL;
	path = NULL;
	env = NULL;
	if (data->infile_error)
		return ;
	key = ft_strreplace(data->commands->key, "/bin/", "");
	temp = ft_split(data->commands->value, ' ');
	argv = execv_aux(data, temp, key, argv);
	if (temp)
		argv = continue_execve(data, temp, argv, key);
	env = join_env(data->env);
	_execve_print(data);
	path = get_path(get_dict_value(data->env, "PATH"), key);
	argv[0] = path;
	if (execve(path, argv, env) < 0)
		print_error(data, path);
	aux_execve_free(temp, argv, env, path);
	free(key);
}
