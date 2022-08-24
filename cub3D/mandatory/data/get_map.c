/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:03:15 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/11 19:16:22 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*fill_head(char *read, char c)
{
	int		i;
	char	**str;
	char	*result;
	int		k;
	char	**temp;

	i = 0;
	str = ft_split(read, '\n');
	k = 0;
	while (str[k])
	{
		temp = ft_split(str[k], ' ');
		if (temp[0] && temp[0][0] == c)
			result = ft_strdup(temp[1]);
		k++;
	}
	free_double_char(str);
	free_double_char(temp);
	return (result);
}

void	fill_map(t_data *data, char **lines, int i, int j)
{
	int	count;

	i = 0;
	while (i < data->height)
	{
		data->map[i] = (char *)calloc(data->width + 1, sizeof(char));
		i++;
	}
	i = 6;
	j = 0;
	while (lines[i])
	{
		count = 0;
		while (count < data->width)
		{
			if (!lines[i][count])
				break ;
			data->map[j][count] = lines[i][count];
			count++;
		}
		data->map[j][count] = '\0';
		i++;
		j++;
	}
}

int	rgb(char *s)
{
	int		c;
	int		i;
	char	**rgb;

	rgb = ft_split(s, ',');
	c = ft_atoi(rgb[0]);
	c = (c << 8) | ft_atoi(rgb[1]);
	c = (c << 8) | ft_atoi(rgb[2]);
	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
	free(s);
	return (c);
}

static t_mlx	get_textures(t_data *data, char c, char *read)
{
	t_mlx	img;

	if (c == 'n')
		img.img = mlx_xpm_file_to_image(data->mlx,
				fill_head(read, 'N'), &img.w, &img.h);
	if (c == 's')
		img.img = mlx_xpm_file_to_image(data->mlx,
				fill_head(read, 'S'), &img.w, &img.h);
	if (c == 'w')
		img.img = mlx_xpm_file_to_image(data->mlx,
				fill_head(read, 'W'), &img.w, &img.h);
	if (c == 'e')
		img.img = mlx_xpm_file_to_image(data->mlx,
				fill_head(read, 'E'), &img.w, &img.h);
	img.line_length = 0;
	img.bits_per_pixel = 0;
	img.endian = 0;
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	return (img);
}

void	get_headers(t_data *data, char *read)
{
	data->f = rgb(fill_head(read, 'F'));
	data->c = rgb(fill_head(read, 'C'));
	data->tex[0] = get_textures(data, 'n', read);
	data->tex[1] = get_textures(data, 's', read);
	data->tex[2] = get_textures(data, 'w', read);
	data->tex[3] = get_textures(data, 'e', read);
}
