/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:03:17 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/14 22:04:03 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	mlx_draw_column(t_data *data, t_ray ray, t_mlx texture)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	color;

	t = get_t(get_mlx_pixel_color(&texture, ray.tex_x, ray.tex_y));
	r = get_r(get_mlx_pixel_color(&texture, ray.tex_x, ray.tex_y));
	g = get_g(get_mlx_pixel_color(&texture, ray.tex_x, ray.tex_y));
	b = get_b(get_mlx_pixel_color(&texture, ray.tex_x, ray.tex_y));
	color = create_trgb(t, r, g, b);
	if (color > 0)
		my_mlx_pixel_put(data, ray.x, ray.y, color);
}

void	mlx_draw_sprite(t_data *data, t_sprite sprite, int y, int stripe)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	color;

	t = get_t(get_mlx_pixel_color(&data->keys[sprite.i].tex[data->key_anim],
				sprite.tex_x, sprite.tex_y));
	r = get_r(get_mlx_pixel_color(&data->keys[sprite.i].tex[data->key_anim],
				sprite.tex_x, sprite.tex_y));
	g = get_g(get_mlx_pixel_color(&data->keys[sprite.i].tex[data->key_anim],
				sprite.tex_x, sprite.tex_y));
	b = get_b(get_mlx_pixel_color(&data->keys[sprite.i].tex[data->key_anim],
				sprite.tex_x, sprite.tex_y));
	color = create_trgb(t, r, g, b);
	if (color > 0)
		my_mlx_pixel_put(data, stripe, y, color);
}

void	mlx_draw_column_fc(t_data *data, t_ray_floor ray, t_mlx texture, int i)
{
	if (i == 0)
	{
		my_mlx_pixel_put(data, ray.x, ray.y,
			get_mlx_pixel_color(&texture, ray.tx_c, ray.ty_c));
	}
	else
	{		
		my_mlx_pixel_put(data, ray.x, ray.y,
			get_mlx_pixel_color(&texture, ray.tx_f, ray.ty_f));
	}
}

void	print_texture(t_data *data, t_ray ray, double tex_pos, double step)
{
	ray.y = ray.draw_start;
	while (ray.y < ray.draw_end)
	{
		ray.tex_y = (int)tex_pos & (data->tex[ray.tex].h - 1);
		tex_pos += step;
		mlx_draw_column(data, ray, data->tex[ray.tex]);
		ray.y++;
	}
}
