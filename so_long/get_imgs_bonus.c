/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_imgs_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:47:35 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/22 16:12:31 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long_bonus.h"

static t_game	get_images_coins(t_game game)
{
	int	size;

	size = game.pixel;
	game.coins.sprites[0] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/coin_1.xpm", &size, &size);
	game.coins.sprites[1] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/coin_2.xpm", &size, &size);
	game.coins.sprites[2] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/coin_3.xpm", &size, &size);
	game.coins.sprites[3] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/coin_4.xpm", &size, &size);
	return (game);
}

static t_game	get_images_walls(t_game game)
{
	int	size;

	size = game.pixel;
	game.wall[1] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/wall_D.xpm", &size, &size);
	game.wall[2] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/wall_D_R.xpm", &size, &size);
	game.wall[3] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/wall_D_L.xpm", &size, &size);
	game.wall[4] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/wall_U.xpm", &size, &size);
	game.wall[5] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/wall_U_R.xpm", &size, &size);
	game.wall[6] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/wall_U_L.xpm", &size, &size);
	game.wall[7] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/wall_L.xpm", &size, &size);
	game.wall[8] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/wall_R.xpm", &size, &size);
	return (game);
}

static t_game	get_images_water_aux(t_game game)
{
	int	size;

	size = game.pixel;
	game.wall[18] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_L_R.xpm", &size, &size);
	game.wall[19] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_U_D_R.xpm", &size, &size);
	game.wall[20] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_U_D_L.xpm", &size, &size);
	game.wall[21] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_L_R_U.xpm", &size, &size);
	game.wall[22] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_L_R_D.xpm", &size, &size);
	game.wall[23] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_U_corner_R.xpm", &size, &size);
	return (game);
}

static t_game	get_images_water(t_game game)
{
	int	size;

	size = game.pixel;
	game.wall[0] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water.xpm", &size, &size);
	game.wall[9] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_L.xpm", &size, &size);
	game.wall[10] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_R.xpm", &size, &size);
	game.wall[11] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_U.xpm", &size, &size);
	game.wall[12] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_D.xpm", &size, &size);
	game.wall[13] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_U_L.xpm", &size, &size);
	game.wall[14] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_U_R.xpm", &size, &size);
	game.wall[15] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_D_R.xpm", &size, &size);
	game.wall[16] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_D_L.xpm", &size, &size);
	game.wall[17] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/water_U_D.xpm", &size, &size);
	game = get_images_water_aux(game);
	return (game);
}

t_game	get_images(t_game game)
{
	int	size;
	int	i;

	size = game.pixel;
	i = 0;
	game.background = mlx_xpm_file_to_image
		(game.mlx, "./imgs/grass_2.xpm", &size, &size);
	game.exit[0] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/exit_1.xpm", &size, &size);
	game.exit[1] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/exit_2.xpm", &size, &size);
	game = get_images_walls(game);
	game = get_images_water(game);
	game.wall[24] = mlx_xpm_file_to_image
		(game.mlx, "./imgs/wall3.xpm", &size, &size);
	game = get_images_player_down_up(game);
	game = get_images_player_right_left(game);
	while (i < game.enemy_conut)
	{
		game = get_images_enemy_down_up(game, i);
		game = get_images_enemy_right_left(game, i);
		i++;
	}
	game = get_images_coins(game);
	return (game);
}
