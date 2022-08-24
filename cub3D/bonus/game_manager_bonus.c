/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:59:51 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/15 12:22:27 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	_esc(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_window(data->mlx, data->window);
	free_double_char(data->map);
	free (data->tex[0].img);
	free (data->tex[1].img);
	free (data->tex[2].img);
	free (data->tex[3].img);
	if (data->keys)
		free(data->keys);
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
	if (keycode == 40)
		data->n_keys += 1;
	if (keycode == 123)
		cam_left(data);
	if (keycode == 124)
		cam_right(data);
	change_value(data);
	printf("\e[1;1H\e[2J");
	return (0);
}

void	print_cube(int offset_x, int offset_y, t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= ((HEIGTH * MINIMAP_SIZE) / WIDTH) - 1)
	{
		j = 0;
		while (j <= ((HEIGTH * MINIMAP_SIZE) / WIDTH) - 1)
		{
			my_mlx_pixel_put(data,
				j + offset_x, i + offset_y, color);
			j++;
		}
		i++;
	}
}

int	main_loop(t_data *data)
{
	if (data->fps > 5)
	{
		if (data->key_anim == 6)
			data->key_anim = 0;
		data->key_anim++;
		data->fps = 0;
	}
	data->fps++;
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
	mlx_hook(data.window, 6, 1L << 6, cam, &data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	change_value(&data);
	mlx_loop(data.mlx);
	mlx_clear_window(data.mlx, data.window);
	mlx_destroy_window(data.mlx, data.window);
}
