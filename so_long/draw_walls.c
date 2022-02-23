/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:38:36 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/15 16:22:29 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

static void	put_limit_up(t_game game, int x, int y)
{
	if (x == 0)
		mlx_put_image_to_window(game.mlx, game.win, game.wall[6],
			x * game.pixel, y * game.pixel);
	else if (x == game.x - 1)
		mlx_put_image_to_window(game.mlx, game.win, game.wall[5],
			x * game.pixel, y * game.pixel);
	else
		mlx_put_image_to_window(game.mlx, game.win, game.wall[4],
			x * game.pixel, y * game.pixel);
}

static void	put_limit_down(t_game game, int x, int y)
{
	if (x == 0)
		mlx_put_image_to_window(game.mlx, game.win, game.wall[3],
			x * game.pixel, y * game.pixel);
	else if (x == game.x - 1)
		mlx_put_image_to_window(game.mlx, game.win, game.wall[2],
			x * game.pixel, y * game.pixel);
	else
		mlx_put_image_to_window(game.mlx, game.win, game.wall[1],
			x * game.pixel, y * game.pixel);
}

static void	put_area(t_game game, int x, int y)
{
	if (x == 0)
		mlx_put_image_to_window(game.mlx, game.win, game.wall[7],
			x * game.pixel, y * game.pixel);
	else if (x == game.x - 1)
		mlx_put_image_to_window(game.mlx, game.win, game.wall[8],
			x * game.pixel, y * game.pixel);
	else
	{
		if (game.map[y + 1][x] == '1' && game.map[y - 1][x] == '1'
			&& game.map[y][x + 1] == '1' && game.map[y][x - 1] == '1')
			mlx_put_image_to_window(game.mlx, game.win, game.wall[0],
				x * game.pixel, y * game.pixel);
		else
			put_area_aux(game, x, y);
	}
}

t_game	draw_walls(t_game game)
{
	int	y;
	int	x;

	y = 0;
	while (game.map[y])
	{
		x = 0;
		while (game.map[y][x])
		{
			if (game.map[y][x] == '1')
			{
				if (y == 0)
					put_limit_up(game, x, y);
				else if (y == game.y - 1)
					put_limit_down(game, x, y);
				else
					put_area(game, x, y);
			}
			x++;
		}
		y++;
	}
	return (game);
}
