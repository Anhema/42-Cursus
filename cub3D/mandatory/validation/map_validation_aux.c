/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:57:24 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/15 11:48:01 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_all(char **lines, char *file)
{
	int	i;

	free (file);
	i = 0;
	while (lines[i])
		free(lines[i++]);
	free (lines);
}

static int	ft_check_invalid_chars(int i, int j, char **lines)
{
	if (lines[i][j] != ' ' && lines[i][j] != '0' && lines[i][j] != '1'
			&& lines[i][j] != 'N' && lines[i][j] != 'S'
			&& lines[i][j] != 'E' && lines[i][j] != 'W')
		return (1);
	return (0);
}

static int	ft_check_full_line(int i, int j, char **lines)
{
	if (lines[i][j] == '0' || lines[i][j] == 'N' || lines[i][j] == 'S'
			|| lines[i][j] == 'E' || lines[i][j] == 'W')
		return (1);
	return (0);
}

void	ft_map_loop_checks(int i, int j, char **lines, char *file)
{
	if (ft_check_invalid_chars(i, j, lines))
		print_map_error("Invalic character in map", file, lines);
	if (ft_check_full_line(i, j, lines))
		check_not_full_line(lines, file, i, j);
	if (lines[i][j] == ' ')
		map_is_closed(lines, file, i, j);
}

void	ft_check_map_n(int n, char *file, char **lines)
{
	if (n > 1)
		print_map_error("More than one position for player", file, lines);
	if (n == 0)
		print_map_error("No player position", file, lines);
}
