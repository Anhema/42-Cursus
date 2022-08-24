/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_map_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:55:17 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/09 16:43:11 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_check_map_multiple_lines(int i, char *file, char **lines, int n)
{
	int	j;

	j = i;
	while (file && file[j])
	{
		if (j >= (int)ft_strlen(file) - 1)
			return (1);
		if (file[j] == '\n' && (file[j + 1] && file[j + 1] == '\n'))
		{
			n = j;
			while (file[n])
			{
				if (file[n] != '\n')
					print_map_error("Map has multiples empty lines",
						file, lines);
				if (n >= (int)ft_strlen(file) - 1)
					return (1);
				n++;
			}
		}
		j++;
	}
	return (0);
}

void	check_map_multiple_lines(char **lines, char *file)
{
	int	i;
	int	n;
	int	is_map;

	i = len(file, '\n');
	n = 0;
	is_map = 1;
	while (file && file[i])
	{
		if (file[i] == '\n' && (file[i + 1] && file[i + 1] != '\n'))
		{
			if (is_map)
			{
				if (_check_map_multiple_lines(i, file, lines, n) > 0)
					return ;
			}
			is_map = 1;
		}
		else if (file[i] != ' ' && file[i] != '0' && file[i] != '1'
			&& file[i] != 'N' && file[i] != 'S'
			&& file[i] != 'E' && file[i] != 'W')
			is_map = 0;
		i++;
	}
}
