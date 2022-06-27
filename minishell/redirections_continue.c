/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_continue.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:51:51 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/23 22:53:21 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	aux_aux(int n, char *c, char *str, int j)
{
	if (n == 0)
	{
		if (str[j] == '\"')
		{
			*c = '\"';
			n++;
		}
		if (str[j] == '\'')
		{
			*c = '\'';
			n++;
		}
	}
	else if (c && str[j] == *c)
	{
		if (n > 0)
		{
			*c = 0;
			n--;
		}
		else
			n++;
	}
	return (n);
}

char	*get_redirections_loop(t_data *data, char *str, int *j, int *count)
{
	if (str[*j] == -128 || str[*j] == -125
		|| str[*j] == -126 || str[*j] == -127)
	{
		data->redirections = add_to_dict
			(data->redirections, *j, *count, ft_strdup(str));
		str = modify_str(str, *j);
		*j = 0;
		*count = 0;
		if (ft_str_equals(str, ""))
		{
			data->rediretions_conut = 1;
			free(str);
			data->str = NULL;
			return (NULL);
		}
	}
	return (str);
}

void	add_to_dict_aux(char *str, char *value)
{
	if (str)
		free(str);
	if (value)
		free(value);
}
