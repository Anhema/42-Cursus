/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_movements_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:34:25 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/14 22:16:01 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	reset_doors(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'd')
				data->map[i][j] = 'D';
			j++;
		}
		i++;
	}
}

void	player_a(t_data *data)
{
	double	moved_x;
	double	moved_y;

	moved_x = data->player->pos_x + data->player->dir_y * MOVE_SPEED;
	moved_y = data->player->pos_y - data->player->dir_x * MOVE_SPEED;
	player_a_ext(data, moved_x, moved_y);
	if (data->map[(int)moved_y][(int)(data->player->pos_x)] == 'K')
	{
		data->player->pos_y = moved_y;
		data->n_keys += 1;
	}
	if (data->map[(int)data->player->pos_y][(int)moved_x] == 'K')
	{
		data->player->pos_x = moved_x;
		data->n_keys += 1;
	}
	data->player->x = (data->player->pos_x);
	data->player->y = (data->player->pos_y);
}

void	player_d(t_data *data)
{
	double	moved_x;
	double	moved_y;

	moved_x = data->player->pos_x - data->player->dir_y * MOVE_SPEED;
	moved_y = data->player->pos_y + data->player->dir_x * MOVE_SPEED;
	player_d_ext(data, moved_x, moved_y);
	if (data->map[(int)moved_y][(int)(data->player->pos_x)] == 'K')
	{
		data->player->pos_y = moved_y;
		data->n_keys += 1;
	}
	if (data->map[(int)data->player->pos_y][(int)moved_x] == 'K')
	{
		data->player->pos_x = moved_x;
		data->n_keys += 1;
	}
	data->player->x = (data->player->pos_x);
	data->player->y = (data->player->pos_y);
}

void	player_w(t_data *data)
{
	double	moved_x;
	double	moved_y;

	moved_x = data->player->pos_x + data->player->dir_x * MOVE_SPEED;
	moved_y = data->player->pos_y + data->player->dir_y * MOVE_SPEED;
	player_w_ext(data, moved_x, moved_y);
	if (data->map[(int)moved_y][(int)(data->player->pos_x)] == 'K')
	{
		data->player->pos_y = moved_y;
		data->n_keys += 1;
		data->map[(int)(data->player->pos_y)][(int)(data->player->pos_x)] = '0';
	}
	if (data->map[(int)data->player->pos_y][(int)moved_x] == 'K')
	{
		data->player->pos_x = moved_x;
		data->n_keys += 1;
		data->map[(int)(data->player->pos_y)][(int)(data->player->pos_x)] = '0';
	}
	data->player->x = (data->player->pos_x);
	data->player->y = (data->player->pos_y);
}

void	player_s(t_data *data)
{
	double	moved_x;
	double	moved_y;

	moved_x = data->player->pos_x - data->player->dir_x * MOVE_SPEED;
	moved_y = data->player->pos_y - data->player->dir_y * MOVE_SPEED;
	player_s_ext(data, moved_x, moved_y);
	if (data->map[(int)moved_y][(int)(data->player->pos_x)] == 'K')
	{
		data->player->pos_y = moved_y;
		data->n_keys += 1;
	}
	if (data->map[(int)data->player->pos_y][(int)moved_x] == 'K')
	{
		data->player->pos_x = moved_x;
		data->n_keys += 1;
	}
	data->player->x = (data->player->pos_x);
	data->player->y = (data->player->pos_y);
}
