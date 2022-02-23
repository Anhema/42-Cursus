/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:56:34 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/18 16:36:53 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long_bonus.h"

int	check_rectangle(char **file)
{
	int		i;
	size_t	max_len;

	max_len = ft_strlen(file[1]);
	i = 1;
	while (file[i])
	{
		if (max_len != ft_strlen(file[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_extension(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len] == 'r' && str[len - 1] == 'e'
		&& str[len - 2] == 'b' && str[len - 3] == '.')
		return (1);
	return (0);
}

int	check_chars(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (!(map[j][i] == '0' || map[j][i] == '1' || map[j][i] == '\n'
				|| map[j][i] == 'C' || map[j][i] == 'E' || map[j][i] == 'P'
				|| map[j][i] == 'e'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	free_string_array(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

int	closed_map(char **lines)
{
	int	i;
	int	j;

	i = 0;
	while (lines[i])
	{
		if (i == 0 || lines[i + 1] == NULL)
		{
			j = 0;
			while (lines[i][j])
			{
				if (lines[i][j] != '1')
					return (0);
				j++;
			}
		}
		else
		{
			if (lines[i][0] != '1' || lines[i][ft_strlen(lines[i]) - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}
