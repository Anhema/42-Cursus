/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:02:47 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/10 22:21:13 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

t_game	player_move_up(t_game	*game)
{
	char	next_pos;

	next_pos = game->map[game->player.y - 1][game->player.x];
	if (next_pos == '0')
	{
		game->player.y = game->player.y - 1;
		game->movements++;
	}
	if (next_pos == 'C')
	{
		game->coins.current_coins--;
		game->map[game->player.y - 1][game->player.x] = '0';
		game->player.y = game->player.y - 1;
		game->movements++;
	}
	if (next_pos == 'E' && game->coins.current_coins <= 0)
	{
		game->player.y = game->player.y - 1;
		game->movements++;
		close_win(game);
	}
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	return (*game);
}

t_game	player_move_down(t_game	*game)
{
	char	next_pos;

	next_pos = game->map[game->player.y + 1][game->player.x];
	if (next_pos == '0')
	{
		game->player.y = game->player.y + 1;
		game->movements++;
	}
	if (next_pos == 'C')
	{
		game->coins.current_coins--;
		game->map[game->player.y + 1][game->player.x] = '0';
		game->player.y = game->player.y + 1;
		game->movements++;
	}
	if (next_pos == 'E' && game->coins.current_coins <= 0)
	{
		game->player.y = game->player.y + 1;
		game->movements++;
		close_win(game);
	}
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	return (*game);
}

t_game	player_move_left(t_game *game)
{
	char	next_pos;

	next_pos = game->map[game->player.y][game->player.x - 1];
	if (next_pos == '0')
	{
		game->player.x = game->player.x - 1;
		game->movements++;
	}
	if (next_pos == 'C')
	{
		game->coins.current_coins--;
		game->map[game->player.y][game->player.x - 1] = '0';
		game->player.x = game->player.x - 1;
		game->movements++;
	}
	if (next_pos == 'E' && game->coins.current_coins <= 0)
	{
		game->player.x = game->player.x - 1;
		game->movements++;
		close_win(game);
	}
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	return (*game);
}

t_game	player_move_right(t_game	*game)
{
	char	next_pos;

	next_pos = game->map[game->player.y][game->player.x + 1];
	if (next_pos == '0')
	{
		game->player.x = game->player.x + 1;
		game->movements++;
	}
	if (next_pos == 'C')
	{
		game->coins.current_coins--;
		game->map[game->player.y][game->player.x + 1] = '0';
		game->player.x = game->player.x + 1;
		game->movements++;
	}
	if (next_pos == 'E' && game->coins.current_coins <= 0)
	{
		game->player.x = game->player.x + 1;
		game->movements++;
		close_win(game);
	}
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	return (*game);
}
