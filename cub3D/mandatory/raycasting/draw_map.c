/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:03:17 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/09 16:42:50 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx_s->addr + (
			y * data->mlx_s->line_length + x * (
				data->mlx_s->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	mlx_draw_column(t_data *data, t_ray ray, int color)
{
	int	y;

	y = 0;
	while (y < ray.draw_start)
	{
		my_mlx_pixel_put(data, ray.x, y, data->c);
		y++;
	}
	y = ray.draw_start;
	while (y <= ray.draw_end)
	{
		my_mlx_pixel_put(data, ray.x, y, color);
		y++;
	}
	if (ray.draw_end + 1 > data->height)
		return ;
	y = ray.draw_end + 1;
	while (y < data->height)
	{
		my_mlx_pixel_put(data, ray.x, y, data->f);
		y++;
	}
}

static void	print_map_ew(t_data *data, t_ray ray)
{
	if (data->map[data->player->y][data->player->x] == 'E')
	{
		if (ray.side == 1)
		{
			if (ray.x <= data->width / 2)
				mlx_draw_column(data, ray, 0x00FF0000);
			else
				mlx_draw_column(data, ray, 0x006F00FF);
		}
		else
			mlx_draw_column(data, ray, 0x00D7D7A8);
	}
	else if (data->map[data->player->y][data->player->x] == 'W')
	{
		if (ray.side == 1)
		{
			if (ray.x >= data->width / 2)
				mlx_draw_column(data, ray, 0x00FF0000);
			else
				mlx_draw_column(data, ray, 0x006F00FF);
		}
		else
			mlx_draw_column(data, ray, 0x002D2926);
	}
}

static void	print_map_ns(t_data *data, t_ray ray)
{
	if (data->map[data->player->y][data->player->x] == 'N')
	{
		if (ray.side == 1)
			mlx_draw_column(data, ray, 0x00FF0000);
		else
		{
			if (ray.x <= data->width / 2)
				mlx_draw_column(data, ray, 0x002D2926);
			else
				mlx_draw_column(data, ray, 0x00D7D7A8);
		}
	}
	else if (data->map[data->player->y][data->player->x] == 'S')
	{
		if (ray.side == 1)
			mlx_draw_column(data, ray, 0x006F00FF);
		else
		{
			if (ray.x >= data->width / 2)
				mlx_draw_column(data, ray, 0x002D2926);
			else
				mlx_draw_column(data, ray, 0x00D7D7A8);
		}
	}
}

void	print_map(t_data *data, t_ray ray)
{
	char	c;

	c = data->map[data->player->y][data->player->x];
	if (c == 'N' || c == 'S')
		print_map_ns(data, ray);
	else if (c == 'E' || c == 'W')
		print_map_ew(data, ray);
}
