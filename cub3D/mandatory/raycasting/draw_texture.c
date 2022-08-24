/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:03:17 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/11 19:24:59 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_mlx_pixel_color(t_mlx *mlx_s, int x, int y)
{
	char			*dst;
	int				offset;
	unsigned int	color;

	offset = (y * mlx_s->line_length + x * (mlx_s->bits_per_pixel / 8));
	dst = mlx_s->addr + offset;
	color = *(unsigned int *)dst;
	return (color);
}

static void	mlx_draw_column(t_data *data, t_ray ray, t_mlx texture)
{
	my_mlx_pixel_put(data, ray.x, ray.y,
		get_mlx_pixel_color(&texture, ray.tex_x, ray.tex_y));
}

void	get_texture_id(t_ray *ray)
{
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

void	print_texture(t_data *data, t_ray ray, double tex_pos, double step)
{
	ray.y = 0;
	while (ray.y < ray.draw_start)
		my_mlx_pixel_put(data, ray.x, ray.y++, data->c);
	ray.y = ray.draw_start;
	while (ray.y < ray.draw_end)
	{
		ray.tex_y = (int)tex_pos & (data->tex[ray.tex].h - 1);
		tex_pos += step;
		mlx_draw_column(data, ray, data->tex[ray.tex]);
		ray.y++;
	}
	while (ray.y < data->height)
		my_mlx_pixel_put(data, ray.x, ray.y++, data->f);
}
