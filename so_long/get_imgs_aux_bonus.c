/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_imgs_aux_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:47:35 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/22 16:13:11 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long_bonus.h"

t_game	get_images_enemy_down_up(t_game game, int i)
{
	int	size;

	size = game.pixel;
	game.enemy[i].down[0] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_down.xpm", &size, &size);
	game.enemy[i].down[1] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_down_1.xpm", &size, &size);
	game.enemy[i].down[2] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_down.xpm", &size, &size);
	game.enemy[i].down[3] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_down_2.xpm", &size, &size);
	game.enemy[i].up[0] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_up.xpm", &size, &size);
	game.enemy[i].up[1] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_up_1.xpm", &size, &size);
	game.enemy[i].up[2] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_up.xpm", &size, &size);
	game.enemy[i].up[3] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_up_2.xpm", &size, &size);
	i++;
	return (game);
}

t_game	get_images_enemy_right_left(t_game game, int i)
{
	int	size;

	size = game.pixel;
	game.enemy[i].right[0] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_right.xpm", &size, &size);
	game.enemy[i].right[1] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_right_1.xpm", &size, &size);
	game.enemy[i].right[2] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_right.xpm", &size, &size);
	game.enemy[i].right[3] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_right_2.xpm", &size, &size);
	game.enemy[i].left[0] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_left.xpm", &size, &size);
	game.enemy[i].left[1] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_left_1.xpm", &size, &size);
	game.enemy[i].left[2] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_left.xpm", &size, &size);
	game.enemy[i].left[3] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/enemy/enemy_left_2.xpm", &size, &size);
	i++;
	return (game);
}

t_game	get_images_player_down_up(t_game game)
{
	int	size;

	size = game.pixel;
	game.player.down[0] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_down.xpm", &size, &size);
	game.player.down[1] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_down_1.xpm", &size, &size);
	game.player.down[2] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_down.xpm", &size, &size);
	game.player.down[3] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_down_2.xpm", &size, &size);
	game.player.up[0] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_up.xpm", &size, &size);
	game.player.up[1] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_up_1.xpm", &size, &size);
	game.player.up[2] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_up.xpm", &size, &size);
	game.player.up[3] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_up_2.xpm", &size, &size);
	return (game);
}

t_game	get_images_player_right_left(t_game game)
{
	int	size;

	size = game.pixel;
	game.player.right[0] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_right.xpm", &size, &size);
	game.player.right[1] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_right_1.xpm", &size, &size);
	game.player.right[2] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_right.xpm", &size, &size);
	game.player.right[3] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_right_2.xpm", &size, &size);
	game.player.left[0] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_left.xpm", &size, &size);
	game.player.left[1] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_left_1.xpm", &size, &size);
	game.player.left[2] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_left.xpm", &size, &size);
	game.player.left[3] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/player_left_2.xpm", &size, &size);
	return (game);
}
