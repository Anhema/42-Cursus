/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:31:30 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/22 16:51:56 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long_bonus.h"

void	player_next_sprite(int dir, t_game *game)
{
	if (dir == 0)
	{
		player_move_left(game);
		game->player.current_player_sprite++;
		if (game->player.current_player_sprite > 3)
			game->player.current_player_sprite = 0;
	}
	else if (dir == 1)
	{
		player_move_down(game);
		game->player.current_player_sprite++;
		if (game->player.current_player_sprite > 3)
			game->player.current_player_sprite = 0;
	}
	else if (dir == 2)
	{
		player_move_right(game);
		game->player.current_player_sprite++;
		if (game->player.current_player_sprite > 3)
			game->player.current_player_sprite = 0;
	}
}

int	input_manager(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 53)
		close_win(game);
	if (keycode == 13)
	{
		player_move_up(game);
		game->player.current_player_sprite++;
		if (game->player.current_player_sprite > 3)
			game->player.current_player_sprite = 0;
	}
	else if (keycode == 0)
		player_next_sprite(0, game);
	else if (keycode == 1)
		player_next_sprite(1, game);
	else if (keycode == 2)
		player_next_sprite(2, game);
	print_console(game);
	return (0);
}

//THIS FUNCTION RUN WHILE WINDOW IS OPEN
int	test_loop(t_game *game)
{
	if (game->frame < 1000)
	{
		game->frame++;
		enemy_col(game);
	}
	else
	{
		mlx_clear_window(game->mlx, game->win);
		draw_map(game);
		game->frame = 0;
	}
	return (0);
}

int	close_win(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_string_array(game->map);
	free(game->enemy);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
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
	mlx_loop_hook(game.mlx, test_loop, &game);
	ft_putstr_fd("\nWindow succesfully created\n", 1);
	mlx_loop(game.mlx);
	close_win(&game);
	free_string_array(game.map);
	return (0);
}
