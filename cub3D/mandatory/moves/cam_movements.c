/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:34:40 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/11 19:17:12 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	change_value(data);
	printf("\e[1;1H\e[2J");
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
	change_value(data);
	printf("\e[1;1H\e[2J");
}
