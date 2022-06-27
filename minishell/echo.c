/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:11:20 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/25 13:57:11 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_data	*expand_aux(t_data *data, char *tmp, int *i)
{
	tmp = continue_expand_two(data->str, *i, tmp, data);
	data->str = ft_strdup(tmp);
	if (tmp)
		free(tmp);
	*i = 0;
	return (data);
}

char	*expand(t_data *data, char *str)
{
	int		i;
	char	c;
	char	*tmp;

	data->str = ft_strdup(str);
	if (!data->str || ft_str_equals(data->str, ""))
		return (data->str);
	c = 0;
	i = -1;
	tmp = NULL;
	while (data->str[++i] && i <= (int)ft_strlen(data->str))
	{
		c = continue_expand(c, i, data->str);
		if (data->str[i] == '$' && c != '\'')
		{
			if (data->str[i + 1] == ' ' || data->str[i + 1] == '\0')
				continue ;
			data = expand_aux(data, tmp, &i);
		}
	}
	free (str);
	return (data->str);
}

static int	aux_echo(char *str, int *n, int i)
{
	while (str[i] != ' ' && str[i])
	{
		if (str[i] != 'n')
		{
			*n = 1;
			break ;
		}
		i++;
	}	
	if (*n == 1)
		printf("");
	return (i);
}

void	continue_echo(char *str, char *str_temp, int n, int i)
{
	i = aux_echo(str, &n, i);
	if (n != 1)
	{
		str_temp = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
		if ((int)ft_strlen(str) > i)
			i++;
		n = 0;
		while (str[i])
		{
			str_temp[n] = str[i];
			n++;
			i++;
		}
		str_temp[n] = '\0';
		printf("%s", str_temp);
		free(str_temp);
	}
	else
		printf("%s\n", str);
}

void	ft_echo(t_data *data)
{
	char		*str;
	char		*str_temp;
	int			i;
	int			n;
	extern int	g_stats;

	str = data->commands->value;
	str_temp = NULL;
	g_stats = 0;
	if (!str)
	{
		printf("\n");
		return ;
	}
	if (str[0] == '-' && str[1] == 'n')
	{
		i = 2;
		n = 0;
		continue_echo(str, str_temp, n, i);
	}
	else
		printf("%s\n", str);
	if (str_temp)
		free (str_temp);
	free (str);
}
