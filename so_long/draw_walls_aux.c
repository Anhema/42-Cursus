/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:38:36 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/15 16:27:57 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

static int	put_area_aux_three(t_game game, int x, int y)
{	
	int	i;

	i = 1;
	if (game.map[y + 1][x] != '1' && game.map[y - 1][x] != '1'
		&& game.map[y][x + 1] == '1' && game.map[y][x - 1] == '1')
		mlx_put_image_to_window(game.mlx, game.win, game.wall[17],
			x * game.pixel, y * game.pixel);
	else if (game.map[y + 1][x] == '1' && game.map[y - 1][x] == '1'
		&& game.map[y][x + 1] != '1' && game.map[y][x - 1] != '1')
		mlx_put_image_to_window(game.mlx, game.win, game.wall[18],
			x * game.pixel, y * game.pixel);
	else if (game.map[y + 1][x] == '1' && game.map[y - 1][x] == '1'
		&& game.map[y][x + 1] != '1' && game.map[y][x - 1] != '1')
		mlx_put_image_to_window(game.mlx, game.win, game.wall[19],
			x * game.pixel, y * game.pixel);
	else if (game.map[y + 1][x] != '1' && game.map[y - 1][x] != '1'
		&& game.map[y][x + 1] != '1' && game.map[y][x - 1] == '1')
		mlx_put_image_to_window(game.mlx, game.win, game.wall[19],
			x * game.pixel, y * game.pixel);
	else
		i = 0;
	return (i);
}

static int	put_area_aux_two(t_game game, int x, int y)
{	
	int	i;

	i = 1;
	if (game.map[y + 1][x] == '1' && game.map[y - 1][x] != '1'
		&& game.map[y][x + 1] == '1' && game.map[y][x - 1] != '1')
		mlx_put_image_to_window(game.mlx, game.win, game.wall[13],
			x * game.pixel, y * game.pixel);
	else if (game.map[y + 1][x] == '1' && game.map[y - 1][x] != '1'
		&& game.map[y][x + 1] != '1' && game.map[y][x - 1] == '1')
		mlx_put_image_to_window(game.mlx, game.win, game.wall[14],
			x * game.pixel, y * game.pixel);
	else if (game.map[y + 1][x] != '1' && game.map[y - 1][x] == '1'
		&& game.map[y][x + 1] != '1' && game.map[y][x - 1] == '1')
		mlx_put_image_to_window(game.mlx, game.win, game.wall[15],
			x * game.pixel, y * game.pixel);
	else if (game.map[y + 1][x] != '1' && game.map[y - 1][x] == '1'
		&& game.map[y][x + 1] == '1' && game.map[y][x - 1] != '1')
		mlx_put_image_to_window(game.mlx, game.win, game.wall[16],
			x * game.pixel, y * game.pixel);
	else
		i = 0;
	return (i);
}

static int	put_area_aux_one(t_game game, int x, int y)
{	
	int	i;

	i = 1;
	if (game.map[y + 1][x] == '1' && game.map[y - 1][x] == '1'
		&& game.map[y][x + 1] != '1' && game.map[y][x - 1] == '1')
		mlx_put_image_to_window(game.mlx, game.win, game.wall[10],
			x * game.pixel, y * game.pixel);
	else if (game.map[y + 1][x] == '1' && game.map[y - 1][x] == '1'
		&& game.map[y][x + 1] == '1' && game.map[y][x - 1] != '1')
		mlx_put_image_to_window(game.mlx, game.win, game.wall[9],
			x * game.pixel, y * game.pixel);
	else if (game.map[y + 1][x] == '1' && game.map[y - 1][x] != '1'
		&& game.map[y][x + 1] == '1' && game.map[y][x - 1] == '1')
		mlx_put_image_to_window(game.mlx, game.win, game.wall[11],
			x * game.pixel, y * game.pixel);
	else if (game.map[y + 1][x] != '1' && game.map[y - 1][x] == '1'
		&& game.map[y][x + 1] == '1' && game.map[y][x - 1] == '1')
		mlx_put_image_to_window(game.mlx, game.win, game.wall[12],
			x * game.pixel, y * game.pixel);
	else
		i = 0;
	return (i);
}

void	put_area_aux(t_game game, int x, int y)
{
	if (put_area_aux_one(game, x, y) == 0)
	{
		if (put_area_aux_two(game, x, y) == 0)
		{
			if (put_area_aux_three(game, x, y) == 0)
			{
				if (game.map[y + 1][x] != '1' && game.map[y - 1][x] != '1'
					&& game.map[y][x + 1] == '1' && game.map[y][x - 1] != '1')
					mlx_put_image_to_window(game.mlx, game.win, game.wall[20],
						x * game.pixel, y * game.pixel);
				else if (game.map[y + 1][x] == '1' && game.map[y - 1][x] != '1'
					&& game.map[y][x + 1] != '1' && game.map[y][x - 1] != '1')
					mlx_put_image_to_window(game.mlx, game.win, game.wall[21],
						x * game.pixel, y * game.pixel);
				else if (game.map[y + 1][x] != '1' && game.map[y - 1][x] == '1'
					&& game.map[y][x + 1] != '1' && game.map[y][x - 1] != '1')
					mlx_put_image_to_window(game.mlx, game.win, game.wall[22],
						x * game.pixel, y * game.pixel);
				else
					mlx_put_image_to_window(game.mlx, game.win, game.wall[24],
						x * game.pixel, y * game.pixel);
			}
		}
	}
}
