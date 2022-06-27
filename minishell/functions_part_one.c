/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_part_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:29:25 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/24 16:54:29 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*space_front_to_back_aux(char *c, int i, int j, int fill)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (j + 1));
	j--;
	while (j >= 0)
	{
		str[j] = c[fill];
		j--;
		i++;
		fill--;
	}
	str[i] = '\0';
	return (str);
}

char	remove_quotes_aux(char *str, char *temp, int *i, int j)
{
	if (str[*i] == '>' && str[*i + 1] != '>')
		temp[j] = (unsigned char)128;
	else if (str[*i] == '<' && str[*i + 1] != '<')
		temp[j] = (unsigned char)129;
	else if (str[*i] == '<' && str[*i + 1] == '<')
	{
		temp[j] = (unsigned char)130;
		(*i)++;
	}
	else if (str[*i] == '>' && str[*i + 1] == '>')
	{
		temp[j] = (unsigned char)131;
		(*i)++;
	}
	return (temp[j]);
}

char	remove_quotes_get_c(char *str, int *n, char c, int i)
{
	if (*n == 0)
	{
		if (str[i] == '\"')
		{
			c = '\"';
			(*n)++;
		}
		if (str[i] == '\'')
		{
			c = '\'';
			(*n)++;
		}
	}
	else if (c && str[i] == c)
	{
		if (*n > 0)
			(*n)--;
		else
			(*n)++;
	}
	return (c);
}

t_dict	*ft_pipe_parse_add(char *str, int *last, t_dict *commands, int i)
{
	int		j;
	int		jj;
	char	*temp;

	if (str[i + 1] == '|' || (str[i + 1] == ' ' && str[i + 2] == '|'))
	{
		printf("bash: syntax error near unexpected token `|'\n");
		g_stats = 258;
		delete_all(commands);
		return (NULL);
	}
	j = *last;
	temp = ft_calloc((i - *last) + 1, sizeof(char));
	jj = 0;
	while (j < i)
	{
		temp[jj] = str[j];
		j++;
		jj++;
	}
	temp[jj] = '\0';
	commands = add_command(ft_strdup(temp), commands);
	*last = i + 1;
	free(temp);
	return (commands);
}

t_dict	*ft_pipe_parse_end(char *str, int last, t_dict *commands, int i)
{
	int		j;
	char	*temp;

	j = 0;
	temp = malloc(sizeof(char) * (i - last) + 1);
	temp = ft_memset(temp, 0, sizeof(char) * (i - last) + 1);
	while (j < i - last)
	{
		temp[j] = str[j + last];
		j++;
	}
	temp[j] = '\0';
	if (!ft_str_equals(temp, "") && temp)
		commands = add_command(ft_strdup(temp), commands);
	if (temp)
		free(temp);
	return (commands);
}
