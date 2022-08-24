/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:10:05 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/11 19:59:30 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_double_char(char **str)
{
	int	i;

	if (str)
	{
		i = -1;
		while (str[++i])
			free(str[i]);
		free (str);
	}
}
