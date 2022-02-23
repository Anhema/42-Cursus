/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:02:47 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/21 18:48:05 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long_bonus.h"

t_game	enemy_move_up(t_game	*game, int n)
{
	char	next_pos;

	next_pos = game->map[(int)
		(game->enemy[n].y + 0.2)][(int)(game->enemy[n].x)];
	if (next_pos == '0' || next_pos == 'C' || next_pos == 'P'
		|| (next_pos == 'E' && game->coins.current_coins > 0)
		|| next_pos == 'e')
		game->enemy[n].y = game->enemy[n].y - 0.2;
	else
		game->enemy[n].dir = 3;
	return (*game);
}

t_game	enemy_move_down(t_game	*game, int n)
{
	char	next_pos;

	next_pos = game->map[(int)
		((int)game->enemy[n].y + 1.8)][(int)(game->enemy[n].x)];
	if (next_pos == '0' || next_pos == 'C' || next_pos == 'P'
		|| (next_pos == 'E' && game->coins.current_coins > 0)
		|| next_pos == 'e')
		game->enemy[n].y = game->enemy[n].y + 0.2;
	else
		game->enemy[n].dir = 2;
	return (*game);
}

t_game	enemy_move_left(t_game *game, int n)
{
	char	next_pos;

	next_pos = game->map[(int)
		(game->enemy[n].y)][(int)(game->enemy[n].x - 0.2)];
	if (next_pos == '0' || next_pos == 'C' || next_pos == 'P'
		|| (next_pos == 'E' && game->coins.current_coins > 0)
		|| next_pos == 'e')
		game->enemy[n].x = game->enemy[n].x - 0.2;
	else
		game->enemy[n].dir = 1;
	return (*game);
}

t_game	enemy_move_right(t_game *game, int n)
{
	char	next_pos;

	next_pos = game->map[(int)
		(game->enemy[n].y + 0.6)][(int)(game->enemy[n].x + 1)];
	if (next_pos == '0' || next_pos == 'C' || next_pos == 'P'
		|| (next_pos == 'E' && game->coins.current_coins > 0)
		|| next_pos == 'e')
		game->enemy[n].x = game->enemy[n].x + 0.2;
	else
		game->enemy[n].dir = 0;
	return (*game);
}
