/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:22:26 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/14 21:45:03 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	map_validation(argc, argv);
	data.mlx = mlx_init();
	get_fill_map(&data, argv[1]);
	get_keys_init(&data);
	get_player_init(&data);
	data.width = WIDTH;
	data.height = HEIGTH;
	data.key_anim = 0;
	data.fps = 0;
	print_data(&data);
	init_window(data);
	return (0);
}
