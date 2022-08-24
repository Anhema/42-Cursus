/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_floor_raycasting_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:11:51 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/14 21:35:32 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	sky_floor_raycast_ext_(t_data *data, t_ray_floor *ray_floor)
{
	ray_floor->cell_x = (int)(ray_floor->floor_x);
	ray_floor->cell_y = (int)(ray_floor->floor_y);
	ray_floor->tx_f = (int)(data->floor.w
			* (ray_floor->floor_x - ray_floor->cell_x)
			/ FLOOR_TILING) & (data->floor.w - 1);
	ray_floor->ty_f = (int)(data->floor.h
			* (ray_floor->floor_y - ray_floor->cell_y)
			/ FLOOR_TILING) & (data->floor.h - 1);
	ray_floor->tx_c = (int)(data->sky.w
			* (ray_floor->floor_x - ray_floor->cell_x)
			/ SKY_TILING) & (data->sky.w - 1);
	ray_floor->ty_c = (int)(data->sky.h
			* (ray_floor->floor_y - ray_floor->cell_y)
			/ SKY_TILING) & (data->sky.h - 1);
	ray_floor->floor_x += ray_floor->floor_step_x;
	ray_floor->floor_y += ray_floor->floor_step_y;
}

static void	sky_floor_raycast_ext(t_data *data, t_ray_floor	*ray_floor)
{
	while (ray_floor->x < data->width)
	{
		sky_floor_raycast_ext_(data, ray_floor);
		if (ray_floor->y <= data->height / 2)
		{
			if (data->c >= 0)
				my_mlx_pixel_put(data, ray_floor->x, ray_floor->y, data->c);
			else
				mlx_draw_column_fc(data, *ray_floor, data->sky, 0);
		}
		else
		{
			if (data->f >= 0)
				my_mlx_pixel_put(data, ray_floor->x, ray_floor->y, data->f);
			else
				mlx_draw_column_fc(data, *ray_floor, data->floor, 1);
		}
		ray_floor->x++;
	}
		ray_floor->y++;
}

static void	sky_floor_raycast_ext_one(t_data *data, t_ray_floor	*ray_floor)
{
	ray_floor->ray_dir_x_0 = data->player->dir_x - data->player->plane_x;
	ray_floor->ray_dir_y_0 = data->player->dir_y - data->player->plane_y;
	ray_floor->ray_dir_x_1 = data->player->dir_x + data->player->plane_x;
	ray_floor->ray_dir_y_1 = data->player->dir_y + data->player->plane_y;
	ray_floor->p = ray_floor->y - data->height / 2;
	ray_floor->pos_z = 0.5 * data->height;
	ray_floor->row_distance = ray_floor->pos_z / ray_floor->p;
}

void	sky_floor_raycast(t_data *data)
{
	t_ray_floor	ray_floor;

	ray_floor.y = 0;
	while (ray_floor.y < data->height)
	{
		sky_floor_raycast_ext_one(data, &ray_floor);
		ray_floor.floor_step_x = ray_floor.row_distance
			* (ray_floor.ray_dir_x_1 - ray_floor.ray_dir_x_0) / data->width;
		ray_floor.floor_step_y = ray_floor.row_distance
			* (ray_floor.ray_dir_y_1 - ray_floor.ray_dir_y_0) / data->width;
		ray_floor.floor_x = data->player->pos_x
			+ ray_floor.row_distance * ray_floor.ray_dir_x_0;
		ray_floor.floor_y = data->player->pos_y
			+ ray_floor.row_distance * ray_floor.ray_dir_y_0;
		ray_floor.x = 0;
		sky_floor_raycast_ext(data, &ray_floor);
	}
}
