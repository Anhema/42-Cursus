/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:33:11 by cbustama          #+#    #+#             */
/*   Updated: 2022/08/11 19:19:06 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	position_values(t_data *data, int i, int j)
{
	if (data->player->y == i && data->player->x == j)
		printf("🎮");
	else if (data->map[i][j] == ' ')
		printf("  ");
	else if (data->map[i][j] == '1')
		printf("\xF0\x9F\x8C\xB4");
	else if (data->map[i][j] == '0')
		printf("🟦");
}

void	change_value(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (++j < data->width)
		{
			if (!data->map[i][j])
				break ;
			position_values(data, i, j);
		}
		printf("\n");
	}
	print_data(data);
}

void	print_data(t_data *data)
{
	printf("\n---------\n");
	printf("PLAYER:\npos = (%f, %f) -- (%d, %d)\n",
		data->player->pos_x, data->player->pos_y,
		data->player->x, data->player->y);
	printf("dir = (%f, %f)\nplane = (%f, %f)\n",
		data->player->dir_x, data->player->dir_y,
		data->player->plane_x, data->player->plane_y);
}
