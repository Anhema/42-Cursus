/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:55:37 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/22 16:52:28 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long_bonus.h"

t_game	init_game_aux(t_game game, int y)
{
	game.y = y;
	game.frame = 0;
	game.coins.current_coins_sprite = 0;
	game.pixel = 64;
	game.player.dir = 0;
	game.player.current_player_sprite = 0;
	ft_putstr_fd("\e[1;1H\e[2J", 1);
	ft_putstr_fd("\nCreating window ...\n", 1);
	game.mlx = mlx_init();
	game.win = mlx_new_window(
			game.mlx, game.x * game.pixel, game.y * game.pixel, "so_long");
	game = get_images(game);
	return (game);
}

static t_game	set_player_enemy_coins(t_game game, int x, int y)
{
	if (game.map[y][x] == 'P')
	{
		game.player.x = x;
		game.player.y = y;
	}
	if (game.map[y][x] == 'e')
	{
		game.enemy_conut++;
	}
	if (game.map[y][x] == 'C')
		game.coins.current_coins++;
	return (game);
}

static t_game	set_enemies(t_game game)
{
	int	y;
	int	x;
	int	aux;

	aux = 0;
	y = 0;
	while (game.map[y])
	{
		x = 0;
		while (game.map[y][x])
		{
			if (game.map[y][x] == 'e')
			{
				game.enemy[aux].x = x;
				game.enemy[aux].y = y;
				game.enemy[aux].dir = 0;
				game.enemy[aux].current_enemy_sprite = 0;
				aux++;
			}
			x++;
		}
		y++;
		game.x = x;
	}
	return (game);
}

t_game	init_game(t_game game)
{
	int	y;
	int	x;

	y = 0;
	game.movements = 0;
	game.enemy_conut = 0;
	game.coins.current_coins = 0;
	while (game.map[y])
	{
		x = 0;
		while (game.map[y][x])
		{
			game = set_player_enemy_coins(game, x, y);
			x++;
		}
		y++;
		game.x = x;
	}
	game.enemy = malloc(sizeof(t_enemy) * game.enemy_conut + 1);
	game = set_enemies(game);
	game = init_game_aux(game, y);
	return (game);
}
