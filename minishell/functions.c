/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:19:32 by cbustama          #+#    #+#             */
/*   Updated: 2022/06/24 18:45:58 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*space_front_to_back(char *c)
{
	int		i;
	int		j;
	int		fill;
	char	*str;

	if (!c)
		return (NULL);
	i = 0;
	while (c[i] == 32)
		i++;
	j = ft_strlen(c);
	while (j > 0 && c[j - 1] == ' ')
		j--;
	if (j == 0)
		return (NULL);
	fill = j - 1;
	j = (j - i);
	i = 0;
	str = space_front_to_back_aux(c, i, j, fill);
	free (c);
	return (str);
}

t_dict	*ft_sort(char **c)
{
	t_dict	*command;
	char	**temp;
	char	*str;
	int		i;
	int		j;

	if (!c)
		return (NULL);
	command = NULL;
	j = 0;
	while (c[j])
	{
		str = "";
		temp = ft_split(space_front_to_back(c[j]), ' ');
		i = 1;
		str = sort_aux(str, temp, &i);
		command = dict_add_back(command, dict_new(temp[0], ft_strdup(str)));
		j++;
	}
	free (str);
	return (command);
}

void	ft_history(char *str)
{
	extern int	g_stats;

	if (str)
		add_history(str);
}

char	*get_builting(char	*str)
{
	int		i;
	int		j;
	int		n;
	char	c;
	char	*temp;

	i = -1;
	n = 0;
	temp = NULL;
	if (!str)
		return (NULL);
	while (str[++i])
	{
		n = aux_aux(n, &c, str, i);
		if (str[i] == ' ' && n == 0)
		{
			j = -1;
			temp = malloc(sizeof(char) * (i + 1));
			while (++j < i)
				temp[j] = str[j];
			temp[j] = '\0';
			return (temp);
		}
	}
	return (str);
}

char	*remove_quotes(char *str)
{
	int		n;
	char	*temp;

	n = aux_quotes(str);
	if (n == 0)
		return (str);
	temp = (char *)calloc((int)ft_strlen(str) + 1, sizeof(char));
	temp = aux_quotes_two(temp, str);
	return (temp);
}
