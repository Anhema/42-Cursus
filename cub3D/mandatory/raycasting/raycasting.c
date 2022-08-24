/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:56:58 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/11 19:21:07 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_init(t_data *data, t_ray *ray)
{
	ray->camera_x = 2 * ray->x / (double)data->width - 1;
	ray->raydir_x = data->player->dir_x + data->player->plane_x * ray->camera_x;
	ray->raydir_y = data->player->dir_y + data->player->plane_y * ray->camera_x;
	ray->map_x = (int)data->player->pos_x;
	ray->map_y = (int)data->player->pos_y;
	if (ray->raydir_x == 0)
		ray->delta_dist_x = exp(30);
	else
		ray->delta_dist_x = fabs(1.0 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->delta_dist_y = exp(30);
	else
		ray->delta_dist_y = fabs(1.0 / ray->raydir_y);
}

void	raycast_dir(t_data *data, t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player->pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player->pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player->pos_y)
			* ray->delta_dist_y;
	}
}

void	raycast_hit(t_data *data, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	raycast_draw_pos(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->h = data->height;
	ray->line_height = (int)(data->height / ray->perp_wall_dist);
	if (ray->perp_wall_dist <= 0)
		ray->line_height = data->height;
	ray->draw_start = -ray->line_height / 2 + data->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->height / 2;
	if (ray->draw_end >= data->height)
		ray->draw_end = data->height - 1;
}

void	texturing_calculations(t_data *data, t_ray *ray)
{
	double		wall_x;
	double		step;
	double		tex_pos;

	get_texture_id(ray);
	if (ray->side == 0)
		wall_x = data->player->pos_y + ray->perp_wall_dist * ray->raydir_y;
	else
		wall_x = data->player->pos_x + ray->perp_wall_dist * ray->raydir_x;
	wall_x -= floor((wall_x));
	ray->tex_x = (int)(wall_x * (double)data->tex[ray->tex].w);
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = data->tex[ray->tex].w - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = data->tex[ray->tex].w - ray->tex_x - 1;
	step = 1.0 * data->tex[ray->tex].h / ray->line_height;
	tex_pos = (ray->draw_start - ray->h / 2 + ray->line_height / 2) * step;
	print_texture(data, *ray, tex_pos, step);
}
