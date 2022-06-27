/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:01:00 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/23 22:16:04 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_prompt(t_data *data)
{
	char	*prompt;
	char	*_prompt;
	char	*_oldprompt;
	char	*s;
	char	*_str;

	if (data->is_redir)
	{
		prompt = "> ";
		return (prompt);
	}
	s = ft_strjoin("/Users/", data->usr);
	_str = ft_strreplace(get_dict_value(data->env, "PWD"), s, "~");
	_prompt = ft_strjoin(data->usr, ": ");
	_oldprompt = ft_strjoin(_prompt, _str);
	prompt = ft_strjoin(_oldprompt, " % ");
	data->prompt = ft_strdup(prompt);
	free(_str);
	free(s);
	free(prompt);
	free(_prompt);
	free(_oldprompt);
	return (data->prompt);
}

void	free_mem(t_data *data, char *str)
{
	int	i;

	i = -1;
	if (str)
		free(str);
	if (data->env)
		delete_all(data->env);
	if (data->usr)
		free(data->usr);
	if (data->prompt)
		free(data->prompt);
	free(data);
	data = NULL;
	str = NULL;
}

char	*ft_readline(t_data *data)
{
	char			*str;
	struct termios	term;
	struct termios	term_old;
	char			*count;

	tcgetattr(STDIN_FILENO, &term_old);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL | ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	ft_signals();
	free_data_readline_two(data);
	str = readline(get_prompt(data));
	if (!str)
	{
		count = getcwd(NULL, 0);
		printf("\033[1A");
		printf("\033[%zuC", ft_strlen(count) - 2);
		printf(" exit\n");
		free_mem(data, str);
		free (count);
		exit(0);
	}
	free_data_readline(data);
	tcsetattr(STDIN_FILENO, TCSANOW, &term_old);
	return (str);
}

char	*ft_readline_heredoc(t_data *data)
{
	char			*str;
	struct termios	term;
	struct termios	term_old;
	char			*count;

	tcgetattr(STDIN_FILENO, &term_old);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL | ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	ft_signals();
	str = readline(get_prompt(data));
	if (!str)
	{
		count = getcwd(NULL, 0);
		printf("\033[1A");
		printf("\033[%zuC", ft_strlen(count) - 2);
		printf(" exit\n");
		free (count);
		exit(0);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &term_old);
	return (str);
}
