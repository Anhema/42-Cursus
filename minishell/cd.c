/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:19:58 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/23 17:43:37 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_dict	*cd_aux(t_dict *temp, char *old_path)
{
	char	*aux;

	aux = getcwd(NULL, 0);
	while (temp->next)
	{
		if (ft_str_equals(temp->next->key, "PWD") == 1)
		{
			free(temp->next->value);
			temp->next->value = ft_strdup(aux);
		}
		if (ft_str_equals(temp->next->key, "OLDPWD") == 1)
		{
			free(temp->next->value);
			temp->next->value = ft_strdup(old_path);
		}
		temp = temp->next;
	}
	if (aux)
		free(aux);
	return (temp);
}

static t_data	*exec_cd(char *path, t_data *data, char *old_path, int original)
{
	t_dict		*temp;

	temp = data->env;
	temp = cd_aux(temp, old_path);
	if (old_path)
		free (old_path);
	if (!original)
		free(path);
	return (data);
}

static char	*_get_path(char *usr, int *orig, char *path)
{
	if (!path)
	{
		*orig = 0;
		path = ft_strjoin("/Users/", usr);
	}
	return (path);
}

t_data	*_cd(char *str, char *usr, t_data *data)
{
	extern int	g_stats;
	char		*path;
	int			original;
	char		*old_path;

	path = str;
	original = 1;
	old_path = getcwd(NULL, 0);
	path = _get_path(usr, &original, path);
	if (ft_str_equals(old_path, "/Users") && ft_str_equals(path, ".."))
		path = "/";
	if (chdir(path) == 0)
		return (exec_cd(path, data, old_path, original));
	else
	{
		g_stats = 1;
		printf("minishell: cd: %s: No such file or directory\n", path);
	}
	g_stats = 0;
	free (old_path);
	if (!original)
		free(path);
	return (data);
}
