/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:34:25 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/10 18:27:01 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_a(t_data *data)
{
	double	moved_x;
	double	moved_y;

	moved_x = data->player->pos_x + data->player->dir_y * MOVE_SPEED;
	moved_y = data->player->pos_y - data->player->dir_x * MOVE_SPEED;
	if (data->map[(int)moved_y][(int)(data->player->pos_x)] != '1')
		data->player->pos_y = moved_y;
	if (data->map[(int)data->player->pos_y][(int)moved_x] != '1')
		data->player->pos_x = moved_x;
	data->player->x = (data->player->pos_x);
	data->player->y = (data->player->pos_y);
	change_value(data);
	printf("\e[1;1H\e[2J");
}

void	player_d(t_data *data)
{
	double	moved_x;
	double	moved_y;

	moved_x = data->player->pos_x - data->player->dir_y * MOVE_SPEED;
	moved_y = data->player->pos_y + data->player->dir_x * MOVE_SPEED;
	if (data->map[(int)moved_y][(int)(data->player->pos_x)] != '1')
		data->player->pos_y = moved_y;
	if (data->map[(int)(data->player->pos_y)][(int)moved_x] != '1')
		data->player->pos_x = moved_x;
	data->player->x = (data->player->pos_x);
	data->player->y = (data->player->pos_y);
	change_value(data);
	printf("\e[1;1H\e[2J");
}

void	player_w(t_data *data)
{
	double	moved_x;
	double	moved_y;

	moved_x = data->player->pos_x + data->player->dir_x * MOVE_SPEED;
	moved_y = data->player->pos_y + data->player->dir_y * MOVE_SPEED;
	if (data->map[(int)moved_y][(int)data->player->pos_x] != '1')
		data->player->pos_y = moved_y;
	if (data->map[(int)data->player->pos_y][(int)moved_x] != '1')
		data->player->pos_x = moved_x;
	data->player->x = (data->player->pos_x);
	data->player->y = (data->player->pos_y);
	change_value(data);
	printf("\e[1;1H\e[2J");
}

void	player_s(t_data *data)
{
	double	moved_x;
	double	moved_y;

	moved_x = data->player->pos_x - data->player->dir_x * MOVE_SPEED;
	moved_y = data->player->pos_y - data->player->dir_y * MOVE_SPEED;
	if (data->map[(int)moved_y][(int)(data->player->pos_x)] != '1')
		data->player->pos_y = moved_y;
	if (data->map[(int)(data->player->pos_y)][(int)moved_x] != '1')
		data->player->pos_x = moved_x;
	data->player->x = (data->player->pos_x);
	data->player->y = (data->player->pos_y);
	change_value(data);
	printf("\e[1;1H\e[2J");
}
