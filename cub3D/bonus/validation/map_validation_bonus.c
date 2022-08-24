/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:19:46 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/14 17:11:37 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	print_map_error(char *str, char *file, char **lines)
{
	int	i;

	printf("Error\n");
	printf("%s\n", str);
	if (file)
		free (file);
	i = 0;
	if (lines)
	{
		while (lines[i])
		{
			free(lines[i]);
			i++;
		}
		free (lines);
	}
	exit (0);
}

static int	map_validation_header(char **lines, char *file, t_validate *map)
{
	int		j;
	int		i;

	i = -1;
	map->n = 0;
	map->is_map = 0;
	map->headers = NULL;
	while (lines[++i])
	{
		j = 0;
		while (lines[i][j] == ' ')
			j++;
		while (lines[i][j])
		{
			if (headers_validation_check(i, j, lines, map) > 0)
				break ;
			j++;
		}
		if (check_is_map(map, file, lines, i) > 0)
			return (i);
	}
	return (1);
}

int	continue_validate_map(t_validate *map, char **lines, char *file)
{
	int	j;

	map->y -= 1;
	while (++map->i < map->y)
	{
		j = -1;
		while (lines[map->i] && lines[map->i][++j])
		{
			continue_validate_map_ext(map, lines, file, j);
			if (lines[map->i][j] == '0' || lines[map->i][j] == 'N'
			|| lines[map->i][j] == 'S' || lines[map->i][j] == 'E'
			|| lines[map->i][j] == 'W' || lines[map->i][j] == 'D'
			|| lines[map->i][j] == 'D' || lines[map->i][j] == 'K')
				check_not_full_line(lines, file, map->i, j);
			if (lines[map->i][j] == ' ')
				map_is_closed(lines, file, map->i, j);
			if (lines[map->i][j] == 'N' || lines[map->i][j] == 'S'
			|| lines[map->i][j] == 'E' || lines[map->i][j] == 'W')
				map->n++;
		}
	}
	return (map->n);
}

static int	validate_map(char **lines, char *file, int i, t_validate *map)
{
	map->i = i;
	map->y = 0;
	while (lines && lines[map->y])
		map->y++;
	check_map_multiple_lines(lines, file);
	check_first_last_lines(lines, file, map->i);
	map->n = 0;
	map->n = continue_validate_map(map, lines, file);
	if (map->n > 1)
		print_map_error("More than one position for player", file, lines);
	if (map->n == 0)
		print_map_error("No player position", file, lines);
	return (1);
}

int	map_validation(int argc, char **argv)
{
	char		**lines;
	int			i;
	t_validate	map;

	map.file = NULL;
	lines = NULL;
	if (argc != 2 || !(argv[1][ft_strlen(argv[1]) - 1] == 'b'
		&& argv[1][ft_strlen(argv[1]) - 2] == 'u'
		&& argv[1][ft_strlen(argv[1]) - 3] == 'c'
		&& argv[1][ft_strlen(argv[1]) - 4] == '.'))
		print_map_error("Invalid input: ./cub3D [*.cub]", map.file, lines);
	map.file = ft_read_file(argv[1], 0);
	if (!map.file || map.file[0] <= 0)
		print_map_error("Invalid file", map.file, lines);
	lines = ft_split(map.file, '\n');
	i = map_validation_header(lines, map.file, &map);
	validate_map(lines, map.file, i, &map);
	printf("MAP OK!\n");
	free (map.file);
	free_double_char(lines);
	return (1);
}
