/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:50:12 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/14 21:49:00 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	get_keys_init_ext(t_data *data, t_key *keys)
{
	int	i;
	int	j;
	int	n;
	int	k;

	i = -1;
	n = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'K')
			{
				keys[n].x = j;
				keys[n].y = i;
				k = -1;
				while (++k < 7)
					keys[n].tex[k] = get_keys_textures(data, k);
				n++;
			}
		}
	}
}

void	get_keys_init(t_data *data)
{
	int		i;
	int		j;
	int		n;
	t_key	*keys;

	i = -1;
	n = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'K')
				n++;
		}
	}
	keys = calloc(n, sizeof(t_key));
	data->len_keys = n;
	data->n_keys = 0;
	get_keys_init_ext(data, keys);
	data->keys = keys;
}

static void	rgb_ext(char *s, t_data *data, int n)
{
	if (n == 0)
	{
		data->floor.img = mlx_xpm_file_to_image(data->mlx,
				s, &data->floor.w, &data->floor.h);
		data->floor.bits_per_pixel = 0;
		data->floor.endian = 0;
		data->floor.addr = mlx_get_data_addr(data->floor.img,
				&data->floor.bits_per_pixel,
				&data->floor.line_length, &data->floor.endian);
			data->f = -1;
	}
	else
	{	
		data->sky.img = mlx_xpm_file_to_image(data->mlx,
				s, &data->sky.w, &data->sky.h);
		data->sky.bits_per_pixel = 0;
		data->sky.endian = 0;
		data->sky.addr = mlx_get_data_addr(data->sky.img,
				&data->sky.bits_per_pixel,
				&data->sky.line_length, &data->sky.endian);
		data->c = -1;
	}
}

int	rgb(char *s, t_data *data, int n)
{
	int		c;
	int		is_file;
	int		i;
	char	**rgb;

	is_file = 0;
	if (open(s, O_RDONLY) >= 0)
		is_file = 1;
	c = -1;
	rgb = NULL;
	if (is_file == 0)
	{
		rgb = ft_split(s, ',');
		c = ft_atoi(rgb[0]);
		c = (c << 8) | ft_atoi(rgb[1]);
		c = (c << 8) | ft_atoi(rgb[2]);
		i = 0;
	}
	else
	{
		rgb_ext(s, data, n);
	}
	free_double_char(rgb);
	free(s);
	return (c);
}

void	get_headers(t_data *data, char *read)
{
	data->f = rgb(fill_head(read, 'F'), data, 0);
	data->c = rgb(fill_head(read, 'C'), data, 1);
	data->tex[0] = get_textures(data, 'n', read);
	data->tex[1] = get_textures(data, 's', read);
	data->tex[2] = get_textures(data, 'w', read);
	data->tex[3] = get_textures(data, 'e', read);
	data->tex[4] = get_textures(data, 'd', read);
	data->tex[5] = get_textures(data, 'p', "textures/press.xpm");
}
