/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:23:29 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/11 19:58:38 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	_check_first_last_lines(char **lines, char *file, int y)
{
	int	j;

	j = 0;
	while (lines[y][j] != '\0')
	{
		if (lines[y][j] == ' ' || lines[y][j] == '1')
			j++;
		else if (lines[y][j] == '0')
			print_map_error("Map not closed", file, lines);
		else
			print_map_error("Invalid character in map", file, lines);
	}
}

int	check_first_last_lines(char **lines, char *file, int i)
{
	int	y;
	int	j;

	y = i;
	while (lines && lines[y])
		y++;
	y--;
	j = 0;
	while (lines[i][j])
	{
		if (lines[i][j] == ' ' || lines[i][j] == '1')
			j++;
		else if (lines[i][j] == '0')
			print_map_error("Map not closed", file, lines);
		else
			print_map_error("Invalic character in map", file, lines);
	}
	_check_first_last_lines(lines, file, y);
	return (1);
}

static void	continue_map_is_closed(char **lines, char *file, int i, int j)
{
	if ((j + 1 <= (int)ft_strlen(lines[i]) && lines[i][j + 1] == 'S')
		|| (j - 1 >= 0 && lines[i][j - 1] == 'S'))
		print_map_error("Invalid player start position", file, lines);
	if (lines[i + 1][j] == 'E' || lines[i - 1][j] == 'E')
		print_map_error("Invalid player start position", file, lines);
	if ((j + 1 <= (int)ft_strlen(lines[i]) && lines[i][j + 1] == 'E')
		|| (j - 1 >= 0 && lines[i][j - 1] == 'E'))
		print_map_error("Invalid player start position", file, lines);
	if (lines[i + 1][j] == 'W' || lines[i - 1][j] == 'W')
		print_map_error("Invalid player start position", file, lines);
	if ((j + 1 <= (int)ft_strlen(lines[i]) && lines[i][j + 1] == 'W')
		|| (j - 1 >= 0 && lines[i][j - 1] == 'W'))
		print_map_error("Invalid player start position", file, lines);
}

void	map_is_closed(char **lines, char *file, int i, int j)
{
	if ((int)ft_strlen(lines[i + 1]) < (int)ft_strlen(lines[i])
		|| (int)ft_strlen(lines[i - 1]) < (int)ft_strlen(lines[i]))
		return ;
	if (lines[i + 1][j] == '0' || lines[i - 1][j] == '0')
		print_map_error("Map not closed", file, lines);
	if ((j + 1 <= (int)ft_strlen(lines[i]) && lines[i][j + 1] == '0')
		|| (j - 1 >= 0 && lines[i][j - 1] == '0'))
		print_map_error("Map not closed", file, lines);
	if (lines[i + 1][j] == 'N' || lines[i - 1][j] == 'N')
		print_map_error("Invalid player start position", file, lines);
	if ((j + 1 <= (int)ft_strlen(lines[i]) && lines[i][j + 1] == 'N')
		|| (j - 1 >= 0 && lines[i][j - 1] == 'N'))
		print_map_error("Invalid player start position", file, lines);
	if (lines[i + 1][j] == 'S' || lines[i - 1][j] == 'S')
		print_map_error("Invalid player start position", file, lines);
	continue_map_is_closed(lines, file, i, j);
}

void	check_not_full_line(char **lines, char *file, int i, int j)
{
	int	next_len;
	int	prev_len;

	next_len = (int)ft_strlen(lines[i + 1]);
	prev_len = (int)ft_strlen(lines[i - 1]);
	if (j >= next_len)
		print_map_error("Map not closed", file, lines);
	if (j >= prev_len)
		print_map_error("Map not closed", file, lines);
	if (lines[i + 1][j] == ' ' || lines[i + 1][j] == '\n'
		|| lines[i - 1][j] == ' ' || lines[i - 1][j] == '\n')
		print_map_error("Map not closed", file, lines);
	if (lines[i][j + 1] == ' ' || lines[i][j + 1] == '\n'
		|| lines[i][j - 1] == ' ' || lines[i][j - 1] == '\n')
		print_map_error("Map not closed", file, lines);
	if (lines[i][j] == '0' && (j == 0 || j == (int)ft_strlen(lines[i]) - 1))
		print_map_error("Map not closed", file, lines);
}
