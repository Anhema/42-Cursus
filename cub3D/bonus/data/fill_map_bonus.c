/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:18:47 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/14 21:44:53 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
