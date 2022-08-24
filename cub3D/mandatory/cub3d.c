/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:22:26 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/08 18:28:17 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	map_validation(argc, argv);
	data.mlx = mlx_init();
	get_fill_map(&data, argv[1]);
	get_player_init(&data);
	data.width = WIDTH;
	data.height = HEIGTH;
	print_data(&data);
	init_window(data);
	return (0);
}
