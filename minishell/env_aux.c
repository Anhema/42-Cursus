/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:38:56 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/23 19:39:24 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_aux_continue(char *value,
	char *key, char **key_value, t_data *data)
{
	if (value)
		data->env = dict_add_back
			(data->env, dict_new(ft_strdup(key), ft_strdup(value)));
	else
		data->env = dict_add_back
			(data->env, dict_new(ft_strdup(key), NULL));
	free_split_double(key_value);
	free(key);
	free(value);
}
