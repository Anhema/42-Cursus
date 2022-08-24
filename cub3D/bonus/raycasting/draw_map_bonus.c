/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:03:17 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/14 22:03:51 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx_s->addr + (
			y * data->mlx_s->line_length + x * (
				data->mlx_s->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->mlx_s->addr + (
			y * data->mlx_s->line_length + x * (
				data->mlx_s->bits_per_pixel / 8));
	return ((unsigned int)dst);
}

void	mlx_draw_img(t_data *data, t_mlx texture, int size_scale)
{
	int	i;
	int	j;

	i = 0;
	while (i < texture.h / size_scale)
	{
		j = 0;
		while (j < texture.w / size_scale)
		{
			my_mlx_pixel_put(data, j, i,
				get_mlx_pixel_color(&texture, j, i));
			j++;
		}
		i++;
	}
}

void	get_texture_id(t_ray *ray, t_data *data)
{
	if (data->map[ray->map_y][ray->map_x] == 'D')
	{
		ray->tex = 4;
		return ;
	}
	if (ray->side == 0)
	{
		if (ray->raydir_x > 0)
			ray->tex = 3;
		else
			ray->tex = 2;
	}
	else
	{
		if (ray->raydir_y > 0)
			ray->tex = 1;
		else
			ray->tex = 0;
	}
}
