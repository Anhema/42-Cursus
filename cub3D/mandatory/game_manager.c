/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:59:51 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/11 19:11:57 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	_esc(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_window(data->mlx, data->window);
	free_double_char(data->map);
	free (data->tex[0].img);
	free (data->tex[1].img);
	free (data->tex[2].img);
	free (data->tex[3].img);
	exit(EXIT_SUCCESS);
}

int	_input(int keycode, t_data *data)
{
	if (keycode == 53)
		_esc(data);
	if (keycode == 13)
		player_w(data);
	if (keycode == 0)
		player_a(data);
	if (keycode == 1)
		player_s(data);
	if (keycode == 2)
		player_d(data);
	if (keycode == 123)
		cam_left(data);
	if (keycode == 124)
		cam_right(data);
	return (0);
}

void	raycast(t_data *data)
{
	t_ray	ray;

	ray.x = 0;
	mlx_clear_window(data->mlx, data->window);
	while (ray.x < data->width)
	{
		raycast_init(data, &ray);
		raycast_dir(data, &ray);
		raycast_hit(data, &ray);
		raycast_draw_pos(data, &ray);
		texturing_calculations(data, &ray);
		ray.x++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->mlx_s->img, 0, 0);
}

int	main_loop(t_data *data)
{
	raycast(data);
	return (0);
}

void	init_window(t_data data)
{
	data.mlx_s = malloc(sizeof(t_mlx));
	data.mlx_s->img = mlx_new_image
		(data.mlx, data.width, data.height);
	data.mlx_s->addr = mlx_get_data_addr
		(data.mlx_s->img, &data.mlx_s->bits_per_pixel,
			&data.mlx_s->line_length, &data.mlx_s->endian);
	data.window = mlx_new_window
		(data.mlx, data.width, data.height, "CUB3D");
	mlx_hook(data.window, 2, 1L << 0, _input, &data);
	mlx_hook(data.window, 17, 1L << 17, _esc, &data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
	mlx_clear_window(data.mlx, data.window);
	mlx_destroy_window(data.mlx, data.window);
}
