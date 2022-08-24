/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:13:33 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/11 19:59:33 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	get_player_init_e(t_data *data, int i, int j)
{
	data->player->pos_x = j + 0.5;
	data->player->pos_y = i + 0.5;
	data->player->x = j;
	data->player->y = i;
	data->player->dir_x = 1;
	data->player->dir_y = 0;
	data->player->plane_x = 0;
	data->player->plane_y = 0.66;
	data->map[i][j] = '0';
}

static void	get_player_init_w(t_data *data, int i, int j)
{
	data->player->pos_x = j + 0.5;
	data->player->pos_y = i + 0.5;
	data->player->x = j;
	data->player->y = i;
	data->player->dir_x = -1;
	data->player->dir_y = 0;
	data->player->plane_x = 0;
	data->player->plane_y = -0.66;
	data->map[i][j] = '0';
}

static void	get_player_init_s(t_data *data, int i, int j)
{
	data->player->pos_x = j + 0.5;
	data->player->pos_y = i + 0.5;
	data->player->x = j;
	data->player->y = i;
	data->player->dir_x = 0;
	data->player->dir_y = 1;
	data->player->plane_x = -0.66;
	data->player->plane_y = 0;
	data->map[i][j] = '0';
}

static void	get_player_init_n(t_data *data, int i, int j)
{
	data->player->pos_x = j + 0.5;
	data->player->pos_y = i + 0.5;
	data->player->dir_x = 0;
	data->player->x = j;
	data->player->y = i;
	data->player->dir_y = -1;
	data->player->plane_x = 0.66;
	data->player->plane_y = 0;
	data->map[i][j] = '0';
}

void	get_player_init(t_data *data)
{
	int			i;
	int			j;

	data->player = calloc(1, sizeof(t_player));
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N')
				get_player_init_n (data, i, j);
			if (data->map[i][j] == 'S')
				get_player_init_s(data, i, j);
			if (data->map[i][j] == 'W')
				get_player_init_w(data, i, j);
			if (data->map[i][j] == 'E')
				get_player_init_e(data, i, j);
			j++;
		}
		i++;
	}
}
