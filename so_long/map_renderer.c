/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:15:57 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/15 16:37:04 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

static t_game	draw_background(t_game game)
{
	int	y;
	int	x;

	y = 0;
	while (game.map[y])
	{
		x = 0;
		while (game.map[y][x])
		{
			if (y != 0 && y != game.y - 1)
				mlx_put_image_to_window(game.mlx, game.win,
					game.background, x * game.pixel, y * game.pixel);
			x++;
		}
		y++;
	}
	return (game);
}

static void	draw_items_e(t_game game, int x, int y)
{
	if (game.coins.current_coins > 0)
		mlx_put_image_to_window(game.mlx, game.win, game.exit[0],
			x * game.pixel, y * game.pixel);
	else
		mlx_put_image_to_window(game.mlx, game.win, game.exit[1],
			x * game.pixel, y * game.pixel);
}

t_game	draw_items(t_game game)
{
	int	y;
	int	x;

	y = 0;
	while (game.map[y])
	{
		x = 0;
		while (game.map[y][x])
		{
			if (game.map[y][x] == 'C')
				mlx_put_image_to_window(game.mlx, game.win,
					game.coins.sprites[game.coins.current_coins_sprite],
					x * game.pixel, y * game.pixel);
			if (game.map[y][x] == 'E')
				draw_items_e(game, x, y);
			x++;
		}
		y++;
	}
	return (game);
}

t_game	draw_player(t_game game)
{
	mlx_put_image_to_window(game.mlx, game.win, game.player.down[0],
		game.player.x * game.pixel, game.player.y * game.pixel);
	return (game);
}

void	draw_map(t_game *game)
{
	draw_background(*game);
	draw_walls(*game);
	draw_items(*game);
	draw_player(*game);
}
