/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:34:11 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/24 19:09:17 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*aux_str(char *str, t_data *data, char **_unset)
{
	data->env = ft_unset(data->env, _unset);
	if (_unset)
		free_split_double(_unset);
	if (data->str)
		free(data->str);
	str = ft_readline(data);
	return (str);
}

char	*free_str_readline(t_data *data)
{
	if (data->str)
		free(data->str);
	return (ft_readline(data));
}

char	*cd_exit_syntax(t_data *data, char *str)
{
	char	**_unset;

	if (ft_str_equals(data->commands->key, "exit") && !data->commands->next)
	{
		ft_exit(str, data);
		return (free_str_readline(data));
	}
	if (ft_str_equals(data->commands->key, "cd") && !data->commands->next)
	{
		data = _cd(data->commands->value, data->usr, data);
		return (free_str_readline(data));
	}
	if (ft_str_equals(data->commands->key, "export") && !data->commands->next)
	{
		data->env = ft_export(data);
		return (free_str_readline(data));
	}
	if (ft_str_equals(data->commands->key, "unset") && !data->commands->next)
	{
		_unset = NULL;
		if (data->commands->value)
			_unset = ft_split(data->commands->value, ' ');
		return (aux_str(str, data, _unset));
	}
	return (NULL);
}

char	*pipe_errors(char *str, t_data *data)
{
	char	*line;
	char	*temp;
	char	*result;

	if (!str)
		return (NULL);
	result = str;
	result = pipe_errors_aux(str);
	if (!result)
		return (NULL);
	if (ft_strlen(str) > 1 && str[ft_strlen(str) - 1] == '|')
	{
		data->is_redir = 1;
		line = ft_readline_heredoc(data);
		temp = ft_strdup(str);
		result = ft_strjoin(temp, line);
		free(str);
		free(temp);
		data->is_redir = 0;
	}
	return (result);
}

char	*minishell_loop(t_data *data, char *str)
{
	ft_history(str);
	str = replace_redirections
		(syntax_redirections(remove_spaces(check_quotes(str))));
	str = pipe_errors(str, data);
	if (!str || ft_str_equals(str, ""))
	{
		if (str)
			free (str);
		return (ft_readline(data));
	}
	str = expand(data, str);
	data = get_redirections(data, str);
	str = data->str;
	data->commands = ft_pipe_parse(data->str);
	if (data->commands)
	{
		data->str = cd_exit_syntax(data, data->str);
		if (data->str)
			return (data->str);
	}
	if (str)
		free (str);
	data = redirections(data);
	return (ft_readline(data));
}
