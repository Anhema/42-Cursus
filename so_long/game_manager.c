/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:55:37 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/14 23:14:51 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

t_game	init_game_aux(t_game game, int y)
{
	game.y = y;
	game.coins.current_coins_sprite = 0;
	game.pixel = 64;
	ft_putstr_fd("\e[1;1H\e[2J", 1);
	ft_putstr_fd("\nCreating window ...\n", 1);
	game.mlx = mlx_init();
	game.win = mlx_new_window(
			game.mlx, game.x * game.pixel, game.y * game.pixel, "so_long");
	game = get_images(game);
	return (game);
}

t_game	init_game(t_game game)
{
	int	y;
	int	x;

	y = 0;
	game.movements = 0;
	game.coins.current_coins = 0;
	while (game.map[y])
	{
		x = 0;
		while (game.map[y][x])
		{
			if (game.map[y][x] == 'P')
			{
				game.player.x = x;
				game.player.y = y;
			}
			if (game.map[y][x] == 'C')
				game.coins.current_coins++;
			x++;
		}
		y++;
		game.x = x;
	}
	game = init_game_aux(game, y);
	return (game);
}
