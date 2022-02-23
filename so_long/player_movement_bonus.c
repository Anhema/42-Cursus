/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:02:47 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/21 17:48:57 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long_bonus.h"

t_game	player_move_up(t_game	*game)
{
	char	next_pos;

	next_pos = game->map[(int)
		(game->player.y -0.2)][(int)(game->player.x + 0.3)];
	if (next_pos == '0' || next_pos == 'E'
		|| next_pos == 'e' || next_pos == 'P')
	{
		game->player.y = game->player.y - 0.2;
		game->movements++;
	}
	if (next_pos == 'C')
	{
		game->coins.current_coins--;
		game->map[(int)game->player.y - 1][(int)(game->player.x + 0.3)] = '0';
		game->player.y = (int)game->player.y - 0.2;
		game->movements++;
	}
	if ((next_pos == 'E' && game->coins.current_coins <= 0))
	{
		game->player.y = game->player.y - 0.2;
		game->movements++;
		close_win(game);
	}
	game->player.dir = 1;
	return (*game);
}

t_game	player_move_down(t_game	*game)
{
	char	next_pos;

	next_pos = game->map[(int)
		((int)game->player.y + 1)][(int)(game->player.x + 0.3)];
	if (next_pos == '0' || next_pos == 'E'
		|| next_pos == 'e' || next_pos == 'P')
	{
		game->player.y = game->player.y + 0.2;
		game->movements++;
	}
	if (next_pos == 'C')
	{
		game->coins.current_coins--;
		game->map[(int)game->player.y + 1][(int)(game->player.x + 0.3)] = '0';
		game->player.y = game->player.y + 0.2;
		game->movements++;
	}
	if ((next_pos == 'E' && game->coins.current_coins <= 0))
	{
		game->player.y = game->player.y + 0.2;
		game->movements++;
		close_win(game);
	}
	game->player.dir = 0;
	return (*game);
}

t_game	player_move_left(t_game *game)
{
	char	next_pos;

	next_pos = game->map[(int)
		(game->player.y + 0.5)][(int)(game->player.x + 0.2)];
	if (next_pos == '0' || next_pos == 'E'
		|| next_pos == 'e' || next_pos == 'P')
	{
		game->player.x = game->player.x - 0.2;
		game->movements++;
	}
	if (next_pos == 'C')
	{
		game->coins.current_coins--;
		game->map[(int)(game->player.y + 0.2)][(int)game->player.x - 1] = '0';
		game->player.x = game->player.x - 0.2;
		game->movements++;
	}
	if ((next_pos == 'E' && game->coins.current_coins <= 0))
	{
		game->player.x = game->player.x - 0.2;
		game->movements++;
		close_win(game);
	}
	game->player.dir = 2;
	return (*game);
}

t_game	player_move_right(t_game *game)
{
	char	next_pos;

	next_pos = game->map[(int)
		(game->player.y + 0.6)][(int)(game->player.x + 0.5)];
	if (next_pos == '0' || next_pos == 'E'
		|| next_pos == 'e' || next_pos == 'P')
	{
		game->player.x = game->player.x + 0.2;
		game->movements++;
	}
	if (next_pos == 'C')
	{
		game->coins.current_coins--;
		game->map[(int)(game->player.y + 0.2)][(int)game->player.x + 1] = '0';
		game->player.x = game->player.x + 0.2;
		game->movements++;
	}
	if ((next_pos == 'E' && game->coins.current_coins <= 0))
	{
		game->player.x = game->player.x + 0.2;
		game->movements++;
		close_win(game);
	}
	game->player.dir = 3;
	return (*game);
}
