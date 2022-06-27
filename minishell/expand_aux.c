/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:47:17 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/24 17:44:24 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*continue_expand_three_aux(char *str,
			char *aux, int i, char *tmp)
{
	char	*result;
	char	*var_two;
	char	*temp;
	char	*result_temp;
	int		j;

	j = get_j(str, i);
	temp = ft_itoa(g_stats);
	if (aux)
		result_temp = ft_strreplace(aux, "$?", temp);
	else
		result_temp = ft_strreplace(tmp, "$?", temp);
	j--;
	while (str[j])
		j++;
	var_two = NULL;
	var_two = (char *)malloc(sizeof(char) * (j - i) + 1);
	ft_memset(var_two, 0, sizeof(char) * (j - i));
	result = continue_expand_for(str, i, result_temp, var_two);
	free (var_two);
	free (aux);
	free (tmp);
	free (temp);
	free (result_temp);
	return (result);
}
