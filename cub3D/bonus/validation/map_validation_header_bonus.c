/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_header_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:37:49 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/12 17:04:57 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	headers_validation_check_aux(int i,
	int j, char **lines, t_validate *map)
{
	if (((lines[i][j] == 'N' && lines[i][j + 1] == 'O')
		|| (lines[i][j] == 'S' && lines[i][j + 1] == 'O')
		|| (lines[i][j] == 'W' && lines[i][j + 1] == 'E')
		|| (lines[i][j] == 'E' && lines[i][j + 1] == 'A')
		|| (lines[i][j] == 'D' && lines[i][j + 1] == 'O'))
		&& lines[i][j + 2] == ' ')
	{
		indentifies_value_validation(lines, j + 2, i, map->file);
		map->headers = check_repeated_header(lines, map->file,
				map->headers, ft_strjoin(&lines[i][j], &lines[i][j + 1]));
		map->n++;
		return (1);
	}
	else if ((lines[i][j] == 'F' || lines[i][j] == 'C')
		&& lines[i][j + 1] == ' ')
	{
		check_f_c_validation(lines, j + 1, i, map->file);
		map->headers = check_repeated_header(lines, map->file,
				map->headers, ft_strjoin(&lines[i][j], ""));
		map->n++;
		return (1);
	}
	free_double_char(map->headers);
	return (0);
}

int	headers_validation_check(int i, int j, char **lines, t_validate *map)
{
	if (headers_validation_check_aux(i, j, lines, map) > 0)
		return (1);
	else
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] != '1' && lines[i][j] != '0' && lines[i][j] != ' ')
				print_map_error("Invalid Identifier", map->file, lines);
			j++;
		}
		map->is_map = 1;
		return (1);
	}
	return (0);
}

int	check_is_map(t_validate *map, char *file, char **lines, int i)
{
	if (map->is_map)
	{
		if (map->n == 7)
			return (i);
		if (map->n > 7)
			print_map_error("To many Identifier", file, lines);
		if (map->n < 7)
			print_map_error("Missing Identifier", file, lines);
	}
	return (-1);
}
