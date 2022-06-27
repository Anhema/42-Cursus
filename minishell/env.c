/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:49:51 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/23 19:38:29 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dict	*create_env(char **str)
{
	char	**temp;
	char	*key;
	char	*value;
	int		i;
	t_dict	*env;

	env = NULL;
	i = 0;
	while (str[i])
	{
		temp = ft_split(str[i], '=');
		if (temp[0])
			key = ft_strdup(temp[0]);
		if (temp[1])
			value = ft_strdup(temp[1]);
		env = dict_add_back(env, dict_new(ft_strdup(key), ft_strdup(value)));
		free_split_double(temp);
		free(key);
		free(value);
		i++;
	}
	return (env);
}

t_dict	*print_export(char **str, int i, t_data data)
{
	t_dict		*new;
	char		**key_value;
	extern int	g_stats;

	if (!((str[i][0] >= 'a' && str[i][0] <= 'z')
		|| (str[i][0] >= 'A' && str[i][0] <= 'Z')))
	{
		printf("export: `%s': not a valid identifier\n", str[i]);
		return (data.env);
	}
	key_value = ft_split(str[i], '=');
	new = dict_new(key_value[0], key_value[1]);
	data.env = dict_add_back
		(data.env, dict_new(key_value[0], key_value[1]));
	return (data.env);
}

t_dict	*export_aux(char **str, t_data *data, int i)
{
	char	**key_value;
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	if (!((str[i][0] >= 'a' && str[i][0] <= 'z')
	|| (str[i][0] >= 'A' && str[i][0] <= 'Z') || (str[i][0] >= '_')))
	{
		g_stats = 1;
		printf("export: `%s': not a valid identifier\n", str[i]);
		return (data->env);
	}
	key_value = ft_split(str[i], '=');
	if (key_value[0])
		key = ft_strdup(key_value[0]);
	if (key_value[1])
		value = ft_strdup(key_value[1]);
	export_aux_continue(value, key, key_value, data);
	return (data->env);
}

t_dict	*ft_export(t_data *data)
{
	char	**str;
	t_dict	*temp;
	int		i;

	g_stats = 0;
	if (!data->commands->value)
	{
		temp = data->env;
		while (temp)
		{
			if (temp->value)
				printf("declare -x %s=\"%s\"\n", temp->key, temp->value);
			else
				printf("declare -x %s\n", temp->key);
			temp = temp->next;
		}
		return (data->env);
	}
	str = ft_split(data->commands->value, ' ');
	i = -1;
	while (str[++i])
		data->env = export_aux(str, data, i);
	free_split_double(str);
	return (data->env);
}

t_dict	*ft_unset(t_dict *env, char **str)
{
	int		i;

	i = 0;
	g_stats = 0;
	if (!str)
		return (env);
	while (str[i])
	{
		if (str[i])
			env = del_one(env, str[i]);
		i++;
	}
	return (env);
}
