/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_aux_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:18:01 by cbustama          #+#    #+#             */
/*   Updated: 2022/06/23 20:24:30 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	aux_quotes(char *str)
{
	int	i;
	int	n;

	n = 0;
	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			n++;
	}
	return (n);
}

char	*aux_quotes_two(char *temp, char *str)
{
	int		i;
	int		n;
	char	c;
	int		j;

	c = 0;
	n = 0;
	j = 0;
	i = -1;
	while (str[++i])
	{
		c = remove_quotes_get_c(str, &n, c, i);
		if (str[i] != c)
		{
			if ((str[i] == '>' || str[i] == '<') && n == 0)
				remove_quotes_aux(str, temp, &i, j);
			else
				temp[j] = str[i];
			j++;
		}
	}
	temp[j] = '\0';
	return (temp);
}

char	*sort_aux(char *str, char **temp, int *i)
{
	while (temp[*i])
	{
		str = ft_strjoin(str, temp[*i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	return (str);
}
