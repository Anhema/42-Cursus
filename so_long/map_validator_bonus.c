/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:56:34 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/15 17:38:07 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long_bonus.h"

static int	count_char(char c, char comp)
{
	if (c == comp)
		return (1);
	if (c == comp)
		return (1);
	if (c == comp)
		return (1);
	return (0);
}

static int	check_min_pos(char **map)
{
	int	e;
	int	c;
	int	p;
	int	i;
	int	j;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			e += count_char(map[i][j], 'E');
			p += count_char(map[i][j], 'P');
			c += count_char(map[i][j], 'C');
			j++;
		}
		i++;
	}
	if (e > 0 && c > 0 && p > 0)
		return (1);
	return (0);
}

static int	map_validator_aux(char **lines)
{
	if (!check_rectangle(lines))
	{
		ft_print_colors("Error\n", "red");
		ft_print_colors("Map is not rectangle\n", "yellow");
		return (0);
	}
	if (!check_chars(lines))
	{
		ft_print_colors("Error\n", "red");
		ft_print_colors("Map has invalid chraracters\n", "yellow");
		return (0);
	}
	if (!closed_map(lines))
	{
		ft_print_colors("Error\n", "red");
		ft_print_colors("Map is not closed\n", "yellow");
		return (0);
	}
	if (!check_min_pos(lines))
	{
		ft_print_colors("Error\n", "red");
		ft_print_colors("Map needs at least an 'C', 'P' and 'E'\n", "yellow");
		return (0);
	}
	return (1);
}

char	**map_validator(char *argv)
{
	char	*file;
	char	**lines;

	if (!check_extension(argv))
		return (NULL);
	file = ft_read_file(argv, 0);
	lines = ft_split(file, '\n');
	free(file);
	if (map_validator_aux(lines) == 0)
		return (NULL);
	ft_print_colors("Map correct\n", "green");
	return (lines);
}
