/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager_aux_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:55:37 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/22 16:19:39 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long_bonus.h"

void	print_console(t_game *game)
{
	ft_putstr_fd("\e[1;1H\e[2J", 1);
	ft_putstr_fd("					SO_LONG					\n\n", 1);
	ft_putstr_fd("\nMovements: ", 1);
	ft_putnbr_fd(game->movements, 1);
	ft_putstr_fd("\nRemaining coins: ", 1);
	ft_putnbr_fd(game->coins.current_coins, 1);
	ft_putstr_fd("\n\n\nPlayer pos: (", 1);
	ft_putnbr_fd(game->player.x, 1);
	ft_putstr_fd(", ", 1);
	ft_putnbr_fd(game->player.y, 1);
	ft_putstr_fd(")\n", 1);
}

static void	check_col(int i, t_game *game)
{
	if (game->enemy[i].dir == 0 || game->enemy[i].dir == 2)
	{
		if ((int)game->player.x == (int)game->enemy[i].x
			&& (int)game->player.y == (int)game->enemy[i].y)
			close_win(game);
	}
	else if (game->enemy[i].dir == 3)
	{
		if ((int)game->player.x == (int)game->enemy[i].x
			&& (int)game->player.y == (int)game->enemy[i].y + 1)
			close_win(game);
	}
	else
	{
		if ((int)game->player.x == (int)game->enemy[i].x - 1
			&& (int)game->player.y == (int)game->enemy[i].y + 1)
			close_win(game);
	}
}

void	enemy_col(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_conut)
	{
		if (game->frame == 1000)
		{
			if (game->enemy[i].dir == 0)
				enemy_move_down(game, i);
			if (game->enemy[i].dir == 1)
				enemy_move_up(game, i);
			if (game->enemy[i].dir == 2)
				enemy_move_left(game, i);
			if (game->enemy[i].dir == 3)
				enemy_move_right(game, i);
			game->enemy[i].current_enemy_sprite++;
			if (game->enemy[i].current_enemy_sprite > 3)
				game->enemy[i].current_enemy_sprite = 0;
		}
		check_col(i, game);
		i++;
	}
}

void	draw_map(t_game *game)
{
	int	i;

	i = 0;
	draw_background(*game);
	draw_items(*game);
	draw_walls(*game);
	game->coins.current_coins_sprite++;
	if (game->coins.current_coins_sprite > 3)
		game->coins.current_coins_sprite = 0;
	while (i < game->enemy_conut)
	{
		draw_enemy(*game, i);
		i++;
	}
	mlx_string_put(game->mlx, game->win, 20, 20, 0, "Movements: ");
	mlx_string_put(game->mlx, game->win, 100, 20, 0, ft_itoa(game->movements));
	draw_player(*game);
}
