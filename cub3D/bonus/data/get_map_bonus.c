/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:03:15 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/14 21:54:48 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

static void	get_textures_ext(t_data *data, char c, char *read, t_mlx *img)
{
	if (c == 'f')
		img->img = mlx_xpm_file_to_image(data->mlx,
				fill_head(read, 'F'), &img->w, &img->h);
	if (c == 'k')
		img->img = mlx_xpm_file_to_image(data->mlx,
				fill_head(read, 'C'), &img->w, &img->h);
	if (c == 'n')
		img->img = mlx_xpm_file_to_image(data->mlx,
				fill_head(read, 'N'), &img->w, &img->h);
	if (c == 's')
		img->img = mlx_xpm_file_to_image(data->mlx,
				fill_head(read, 'S'), &img->w, &img->h);
	if (c == 'w')
		img->img = mlx_xpm_file_to_image(data->mlx,
				fill_head(read, 'W'), &img->w, &img->h);
	if (c == 'e')
		img->img = mlx_xpm_file_to_image(data->mlx,
				fill_head(read, 'W'), &img->w, &img->h);
	if (c == 'd')
		img->img = mlx_xpm_file_to_image(data->mlx,
				fill_head(read, 'D'), &img->w, &img->h);
}

t_mlx	get_textures(t_data *data, char c, char *read)
{
	t_mlx	img;

	get_textures_ext(data, c, read, &img);
	if (c == 'p')
	{
		img.img = mlx_xpm_file_to_image(data->mlx, read, &img.w, &img.h);
		img.w = img.w / 2;
		img.h = img.h / 2;
	}
	img.line_length = 0;
	img.bits_per_pixel = 0;
	img.endian = 0;
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	return (img);
}

t_mlx	get_keys_textures(t_data *data, int k)
{
	t_mlx	img;

	if (k == 0)
		img.img = mlx_xpm_file_to_image(data->mlx, KEY_0, &img.w, &img.h);
	if (k == 1)
		img.img = mlx_xpm_file_to_image(data->mlx, KEY_1, &img.w, &img.h);
	if (k == 2)
		img.img = mlx_xpm_file_to_image(data->mlx, KEY_2, &img.w, &img.h);
	if (k == 3)
		img.img = mlx_xpm_file_to_image(data->mlx, KEY_3, &img.w, &img.h);
	if (k == 4)
		img.img = mlx_xpm_file_to_image(data->mlx, KEY_4, &img.w, &img.h);
	if (k == 5)
		img.img = mlx_xpm_file_to_image(data->mlx, KEY_5, &img.w, &img.h);
	if (k == 6)
		img.img = mlx_xpm_file_to_image(data->mlx, KEY_6, &img.w, &img.h);
	img.line_length = 0;
	img.bits_per_pixel = 0;
	img.endian = 0;
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	return (img);
}
