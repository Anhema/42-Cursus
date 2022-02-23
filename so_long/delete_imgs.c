/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:47:35 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/15 20:26:03 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

static t_game	delete_images_coins(t_game game)
{
	int	size;

	size = game.pixel;
	mlx_destroy_image(game.mlx, game.coins.sprites[0]);
	mlx_destroy_image(game.mlx, game.coins.sprites[1]);
	mlx_destroy_image(game.mlx, game.coins.sprites[2]);
	mlx_destroy_image(game.mlx, game.coins.sprites[3]);
	return (game);
}

static t_game	delete_images_walls(t_game game)
{
	int	size;

	size = game.pixel;
	mlx_destroy_image(game.mlx, game.wall[1]);
	mlx_destroy_image(game.mlx, game.wall[2]);
	mlx_destroy_image(game.mlx, game.wall[3]);
	mlx_destroy_image(game.mlx, game.wall[4]);
	mlx_destroy_image(game.mlx, game.wall[5]);
	mlx_destroy_image(game.mlx, game.wall[6]);
	mlx_destroy_image(game.mlx, game.wall[7]);
	mlx_destroy_image(game.mlx, game.wall[8]);
	return (game);
}

static t_game	delete_images_water_aux(t_game game)
{
	int	size;

	size = game.pixel;
	mlx_destroy_image(game.mlx, game.wall[18]);
	mlx_destroy_image(game.mlx, game.wall[19]);
	mlx_destroy_image(game.mlx, game.wall[20]);
	mlx_destroy_image(game.mlx, game.wall[21]);
	mlx_destroy_image(game.mlx, game.wall[22]);
	mlx_destroy_image(game.mlx, game.wall[23]);
	return (game);
}

static t_game	delete_images_water(t_game game)
{
	int	size;

	size = game.pixel;
	mlx_destroy_image(game.mlx, game.wall[0]);
	mlx_destroy_image(game.mlx, game.wall[9]);
	mlx_destroy_image(game.mlx, game.wall[10]);
	mlx_destroy_image(game.mlx, game.wall[11]);
	mlx_destroy_image(game.mlx, game.wall[12]);
	mlx_destroy_image(game.mlx, game.wall[13]);
	mlx_destroy_image(game.mlx, game.wall[14]);
	mlx_destroy_image(game.mlx, game.wall[15]);
	mlx_destroy_image(game.mlx, game.wall[16]);
	mlx_destroy_image(game.mlx, game.wall[17]);
	game = delete_images_water_aux(game);
	return (game);
}

t_game	delete_images(t_game game)
{
	int	size;

	size = game.pixel;
	mlx_destroy_image(game.mlx, game.background);
	mlx_destroy_image(game.mlx, game.exit[0]);
	mlx_destroy_image(game.mlx, game.exit[1]);
	game = delete_images_walls(game);
	game = delete_images_water(game);
	mlx_destroy_image(game.mlx, game.wall[24]);
	mlx_destroy_image(game.mlx, game.player.down[0]);
	game = delete_images_coins(game);
	return (game);
}
