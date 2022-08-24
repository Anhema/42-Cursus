/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_movements_bonus_ext.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:06:10 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/14 22:14:43 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	player_a_ext(t_data *data, double moved_x, double moved_y)
{
	if ((data->map[(int)moved_y][(int)(data->player->pos_x)] != '1'
		&& data->map[(int)moved_y][(int)(data->player->pos_x)] != 'D')
		|| data->map[(int)data->player->pos_y][(int)data->player->pos_x] == 'D')
		data->player->pos_y = moved_y;
	if ((data->map[(int)data->player->pos_y][(int)moved_x] != '1'
		&& data->map[(int)(data->player->pos_y)][(int)moved_x] != 'D')
		|| data->map[(int)data->player->pos_y][(int)data->player->pos_x] == 'D')
		data->player->pos_x = moved_x;
	if (data->map[(int)moved_y][(int)(data->player->pos_x)] == 'D'
		&& data->n_keys > 0)
	{
		data->player->pos_y = moved_y;
		data->n_keys -= 1;
		data->map[(int)(data->player->pos_y)][(int)(data->player->pos_x)] = 'd';
	}
	else if (data->map[(int)data->player->pos_y][(int)moved_x] == 'D'
		&& data->n_keys > 0)
	{
		data->player->pos_x = moved_x;
		data->n_keys -= 1;
		data->map[(int)(data->player->pos_y)][(int)(data->player->pos_x)] = 'd';
	}
	else
		reset_doors(data);
}

void	player_d_ext(t_data *data, double moved_x, double moved_y)
{
	if ((data->map[(int)moved_y][(int)(data->player->pos_x)] != '1'
		&& data->map[(int)moved_y][(int)(data->player->pos_x)] != 'D')
		|| data->map[(int)data->player->pos_y][(int)data->player->pos_x] == 'D')
		data->player->pos_y = moved_y;
	if ((data->map[(int)(data->player->pos_y)][(int)moved_x] != '1'
		&& data->map[(int)(data->player->pos_y)][(int)moved_x] != 'D')
		|| data->map[(int)data->player->pos_y][(int)data->player->pos_x] == 'D')
		data->player->pos_x = moved_x;
	if (data->map[(int)moved_y][(int)(data->player->pos_x)] == 'D'
		&& data->n_keys > 0)
	{
		data->player->pos_y = moved_y;
		data->n_keys -= 1;
		data->map[(int)(data->player->pos_y)][(int)(data->player->pos_x)] = 'd';
	}
	else if (data->map[(int)data->player->pos_y][(int)moved_x] == 'D'
		&& data->n_keys > 0)
	{
		data->player->pos_x = moved_x;
		data->n_keys -= 1;
		data->map[(int)(data->player->pos_y)][(int)(data->player->pos_x)] = 'd';
	}
	else
		reset_doors(data);
}

void	player_w_ext(t_data *data, double moved_x, double moved_y)
{
	if ((data->map[(int)moved_y][(int)data->player->pos_x] != '1'
		&& data->map[(int)moved_y][(int)data->player->pos_x] != 'D')
		|| data->map[(int)data->player->pos_y][(int)data->player->pos_x] == 'D')
		data->player->pos_y = moved_y;
	if ((data->map[(int)data->player->pos_y][(int)moved_x] != '1'
		&& data->map[(int)data->player->pos_y][(int)moved_x] != 'D')
		|| data->map[(int)data->player->pos_y][(int)data->player->pos_x] == 'D')
		data->player->pos_x = moved_x;
	if (data->map[(int)moved_y][(int)(data->player->pos_x)] == 'D'
		&& data->n_keys > 0)
	{
		data->player->pos_y = moved_y;
		data->n_keys -= 1;
		data->map[(int)(data->player->pos_y)][(int)(data->player->pos_x)] = 'd';
	}
	else if (data->map[(int)data->player->pos_y][(int)moved_x] == 'D'
		&& data->n_keys > 0)
	{
		data->player->pos_x = moved_x;
		data->n_keys -= 1;
		data->map[(int)(data->player->pos_y)][(int)(data->player->pos_x)] = 'd';
	}
	else
		reset_doors(data);
}

void	player_s_ext(t_data *data, double moved_x, double moved_y)
{
	if ((data->map[(int)moved_y][(int)(data->player->pos_x)] != '1'
		&& data->map[(int)moved_y][(int)(data->player->pos_x)] != 'D')
		|| data->map[(int)data->player->pos_y][(int)data->player->pos_x] == 'D')
		data->player->pos_y = moved_y;
	if ((data->map[(int)(data->player->pos_y)][(int)moved_x] != '1'
		&& data->map[(int)(data->player->pos_y)][(int)moved_x] != 'D')
		|| data->map[(int)data->player->pos_y][(int)data->player->pos_x] == 'D')
		data->player->pos_x = moved_x;
	if (data->map[(int)moved_y][(int)(data->player->pos_x)] == 'D'
		&& data->n_keys > 0)
	{
		data->player->pos_y = moved_y;
		data->n_keys -= 1;
		data->map[(int)(data->player->pos_y)][(int)(data->player->pos_x)] = 'd';
	}
	else if (data->map[(int)data->player->pos_y][(int)moved_x] == 'D'
		&& data->n_keys > 0)
	{
		data->player->pos_x = moved_x;
		data->n_keys -= 1;
		data->map[(int)(data->player->pos_y)][(int)(data->player->pos_x)] = 'd';
	}
	else
		reset_doors(data);
}
