/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_part_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:33:04 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/27 15:14:36 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_add_command(char *line_,
	char *arguments, char *arguments_temp, char *built)
{
	if (line_)
		free(line_);
	if (arguments)
		free(arguments);
	if (arguments_temp && !ft_str_equals(arguments, arguments_temp))
		free(arguments_temp);
	if (built && line_ != built)
		free(built);
}

t_dict	*add_command(char *line, t_dict *command)
{
	char	*arguments;
	char	*arguments_temp;
	char	*line_;
	char	*built;

	if (!line)
		return (command);
	line_ = space_front_to_back(line);
	arguments_temp = get_arguments(line_);
	arguments = remove_quotes(arguments_temp);
	built = remove_quotes(get_builting(line_));
	if (!built && !arguments)
		command = NULL;
	else if (!arguments && built)
		command = dict_add_back_repeat
			(command, dict_new(ft_strdup(built), NULL));
	else
		command = dict_add_back_repeat
			(command, dict_new(ft_strdup(built), ft_strdup(arguments)));
	free_add_command(line_, arguments, arguments_temp, built);
	return (command);
}

char	*remove_spaces_aux(char	*str, int i)

{
	int		j;
	int		jj;
	char	*temp;
	char	*aux;
	char	*aux_temp;

	j = i;
	jj = 0;
	while (str[j] == ' ')
	{
		j++;
		jj++;
	}
	jj = i + jj;
	temp = remove_spaces_aux_temp(str, i);
	aux = remove_spaces_aux_aux(str, jj);
	free(str);
	aux_temp = ft_strjoin(temp, " ");
	str = ft_strjoin(aux_temp, aux);
	free(temp);
	free(aux);
	free(aux_temp);
	return (str);
}

char	*remove_spaces_aux_aux(char *str, int jj)
{
	char	*aux;
	int		j;

	aux = (char *)calloc((int)ft_strlen(str) - jj + 1, sizeof(char));
	aux = ft_memset(aux, 0, (int)ft_strlen(str) - jj + 1);
	j = 0;
	while (str[jj])
	{
		aux[j] = str[jj];
		j++;
		jj++;
	}	
	return (aux);
}

char	*remove_spaces_aux_temp(char *str, int i)
{
	char	*temp;
	int		j;

	temp = (char *)calloc(i + 1, sizeof(char));
	temp = ft_memset(temp, 0, i + 1);
	j = 0;
	while (j < i)
	{
		temp[j] = str[j];
		j++;
	}
	return (temp);
}
