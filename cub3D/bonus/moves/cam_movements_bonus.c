/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_movements_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:34:40 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/14 17:42:30 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cam_left(t_data *data)
{
	data->player->old_dir_x = data->player->dir_x;
	data->player->dir_x = data->player->dir_x
		* cos(-ROT_SPEED) - data->player->dir_y * sin(-ROT_SPEED);
	data->player->dir_y = data->player->old_dir_x
		* sin(-ROT_SPEED) + data->player->dir_y * cos(-ROT_SPEED);
	data->player->old_plane_x = data->player->plane_x;
	data->player->plane_x = data->player->plane_x
		* cos(-ROT_SPEED) - data->player->plane_y * sin(-ROT_SPEED);
	data->player->plane_y = data->player->old_plane_x
		* sin(-ROT_SPEED) + data->player->plane_y * cos(-ROT_SPEED);
}

void	cam_right(t_data *data)
{
	data->player->old_dir_x = data->player->dir_x;
	data->player->dir_x = data->player->dir_x
		* cos(ROT_SPEED) - data->player->dir_y * sin(ROT_SPEED);
	data->player->dir_y = data->player->old_dir_x
		* sin(ROT_SPEED) + data->player->dir_y * cos(ROT_SPEED);
	data->player->old_plane_x = data->player->plane_x;
	data->player->plane_x = data->player->plane_x
		* cos(ROT_SPEED) - data->player->plane_y * sin(ROT_SPEED);
	data->player->plane_y = data->player->old_plane_x
		* sin(ROT_SPEED) + data->player->plane_y * cos(ROT_SPEED);
}

int	cam(int x, int y, t_data *data)
{
	(void)y;
	if (x < data->cam_x)
		cam_left(data);
	else if (x > data->cam_x)
		cam_right(data);
	data->cam_x = x;
	return (0);
}
