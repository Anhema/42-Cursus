/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:58:19 by cbustama          #+#    #+#             */
/*   Updated: 2022/06/24 17:34:51 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	continue_expand(char c, int i, char *str)
{
	int	q;

	q = 0;
	if (q == 0)
	{
		if (str[i] == '\"')
		{
			c = '\"';
			q++;
		}
		if (str[i] == '\'')
		{
			c = '\'';
			q++;
		}
	}
	else if (c && str[i] == c)
	{
		if (q > 0)
			q--;
		else
			q++;
	}
	return (c);
}

int	get_j(char *str, int j)
{
	int	n;

	n = j;
	while (str[j])
	{
		if (str[j] == ' ' || str[j] == '$' || str[j] == '@'
			|| str[j] == '\'' || str[j] == '\"')
			break ;
		j++;
		n++;
	}
	return (n);
}

char	*continue_expand_two(char *str, int i, char *tmp, t_data *data)
{
	int		ii;
	int		j;
	char	*result;

	ii = -1;
	tmp = malloc(sizeof(char) * (i + 1));
	while (++ii < i)
		tmp[ii] = str[ii];
	tmp[ii] = '\0';
	i++;
	j = i;
	result = continue_expand_three(str, tmp, data, i);
	return (result);
}

char	*continue_expand_three(char *str, char *tmp, t_data *data, int i)
{
	int		n;
	int		jj;
	int		j;
	char	*var;
	char	*aux;

	j = get_j(str, i);
	var = malloc(sizeof(char) * ((j - i) + 1));
	n = -1;
	jj = j - i;
	while (++n < jj)
		var[n] = str[i++];
	var[n] = '\0';
	if (get_dict_value(data->env, var))
		aux = ft_strjoin(tmp, get_dict_value(data->env, var));
	else if (var[0] == '?')
		aux = ft_strjoin(tmp, ft_strjoin("$", var));
	else
		aux = NULL;
	free (var);
	return (continue_expand_three_aux(str, aux, i, tmp));
}

char	*continue_expand_for(char *str, int i, char *tmp, char *var)
{
	int		jj;
	int		ii;
	char	*result;

	jj = -1;
	ii = i -1;
	result = NULL;
	while (str[++ii])
		var[++jj] = str[ii];
	var[jj + 1] = '\0';
	if (var && !ft_str_equals(var, ""))
		result = ft_strjoin(tmp, var);
	else
		result = ft_strdup(tmp);
	free(str);
	return (result);
}
