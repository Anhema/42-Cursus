/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:23:48 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/14 21:27:10 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	raycast(t_data *data)
{
	t_ray		ray;

	ray.x = 0;
	mlx_clear_window(data->mlx, data->window);
	sky_floor_raycast(data);
	while (ray.x < data->width)
	{
		raycast_init(data, &ray);
		raycast_dir(data, &ray);
		raycast_hit(data, &ray);
		raycast_draw_pos(data, &ray);
		texturing_calculations(data, &ray);
		ray.x++;
	}
	sprite_raycast(data);
	minimap(data);
	mlx_put_image_to_window(data->mlx, data->window, data->mlx_s->img, 0, 0);
}
