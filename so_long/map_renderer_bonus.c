/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:15:57 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/22 16:20:37 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long_bonus.h"

t_game	draw_background(t_game game)
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

void	draw_items_e(t_game game, int x, int y)
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
	if (game.player.dir == 0)
		mlx_put_image_to_window(game.mlx, game.win,
			game.player.down[game.player.current_player_sprite],
			game.player.x * game.pixel, game.player.y * game.pixel);
	else if (game.player.dir == 1)
		mlx_put_image_to_window(game.mlx, game.win,
			game.player.up[game.player.current_player_sprite],
			game.player.x * game.pixel, game.player.y * game.pixel);
	else if (game.player.dir == 2)
		mlx_put_image_to_window(game.mlx, game.win,
			game.player.left[game.player.current_player_sprite],
			game.player.x * game.pixel, game.player.y * game.pixel);
	else if (game.player.dir == 3)
		mlx_put_image_to_window(game.mlx, game.win,
			game.player.right[game.player.current_player_sprite],
			game.player.x * game.pixel, game.player.y * game.pixel);
	else
		mlx_put_image_to_window(game.mlx, game.win, game.player.down[0],
			game.player.x * game.pixel, game.player.y * game.pixel);
	return (game);
}

t_game	draw_enemy(t_game game, int i)
{
	if (game.enemy[i].dir == 0)
		mlx_put_image_to_window(game.mlx, game.win,
			game.enemy[i].down[game.enemy[i].current_enemy_sprite],
			game.enemy[i].x * game.pixel, game.enemy[i].y * game.pixel);
	else if (game.enemy[i].dir == 1)
		mlx_put_image_to_window(game.mlx, game.win,
			game.enemy[i].up[game.enemy[i].current_enemy_sprite],
			game.enemy[i].x * game.pixel, game.enemy[i].y * game.pixel);
	else if (game.enemy[i].dir == 2)
		mlx_put_image_to_window(game.mlx, game.win,
			game.enemy[i].left[game.enemy[i].current_enemy_sprite],
			game.enemy[i].x * game.pixel, game.enemy[i].y * game.pixel);
	else if (game.enemy[i].dir == 3)
		mlx_put_image_to_window(game.mlx, game.win,
			game.enemy[i].right[game.enemy[i].current_enemy_sprite],
			game.enemy[i].x * game.pixel, game.enemy[i].y * game.pixel);
	else
		mlx_put_image_to_window(game.mlx, game.win, game.enemy[i].down[0],
			game.enemy[i].x * game.pixel, game.enemy[i].y * game.pixel);
	i++;
	return (game);
}
