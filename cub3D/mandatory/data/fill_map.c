/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:18:47 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/09 16:42:12 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_fill_map(t_data *data, char *argv)
{
	char	*read;
	int		i;
	int		j;
	char	**lines;

	read = ft_read_file(argv, 0);
	get_headers(data, read);
	lines = ft_split(read, '\n');
	j = 6;
	while (lines[j])
		j++;
	data->height = j - 6;
	data->map = (char **)calloc(data->height + 1, sizeof(char *));
	data->width = 0;
	i = 6;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
			j++;
		if (data->width <= j)
			data->width = j;
		i++;
	}
	fill_map(data, lines, i, j);
}

int	len(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] == c)
		i++;
	return (i);
}
