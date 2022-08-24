/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_aux_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:37:02 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/15 11:48:58 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_check_is_map(int i, char *file, char **lines)
{
	int	j;
	int	n;

	j = i - 1;
	while (file && file[++j])
	{
		if (j >= (int)ft_strlen(file) - 1)
			return (1);
		if (file[j] == '\n' && (file[j + 1] && file[j + 1] == '\n'))
		{
			n = j - 1;
			while (file[++n])
			{
				if (file[n] != '\n')
					print_map_error("Map has multiples empty lines",
						file, lines);
				if (n >= (int)ft_strlen(file) - 1)
					return (1);
			}
		}
	}
	return (0);
}

int	ft_close_condition(char **lines, int i, int j)
{
	if ((lines[i + 1][j] == '0' || lines[i - 1][j] == '0')
	|| ((j + 1 <= (int)ft_strlen(lines[i]) && lines[i][j + 1] == '0')
	|| (j - 1 >= 0 && lines[i][j - 1] == '0')))
		return (1);
	return (0);
}
