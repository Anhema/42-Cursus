/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:31:30 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/22 16:55:54 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

int	input_manager(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 53)
		close_win(game);
	if (keycode == 13)
		player_move_up(game);
	else if (keycode == 0)
		player_move_left(game);
	else if (keycode == 1)
		player_move_down(game);
	else if (keycode == 2)
		player_move_right(game);
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
	return (0);
}

int	close_win(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_string_array(game->map);
	delete_images(*game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fps;

	fps = 0;
	if (argc != 2)
	{
		ft_print_colors("Invlid format: ", "red");
		ft_putstr_fd("./so_long [MAP].ber\n", 1);
		return (0);
	}
	game.map = map_validator(argv[1]);
	if (!game.map)
		return (0);
	game = init_game(game);
	draw_map(&game);
	mlx_hook(game.win, 2, 1L << 0, input_manager, &game);
	mlx_hook(game.win, 17, 1L << 17, close_win, &game);
	mlx_loop(game.mlx);
	close_win(&game);
	return (0);
}
