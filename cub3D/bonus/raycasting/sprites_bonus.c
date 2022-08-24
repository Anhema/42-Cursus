/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:17:54 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/15 12:20:50 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

#define UDIV 2
#define VDIV 2
#define VMOVE 0.0

void	sprite_raycast_init(t_data *data, t_sprite *sprite)
{
		sprite->sprite_x = data->keys[sprite->i].x - data->player->pos_x;
		sprite->sprite_y = data->keys[sprite->i].y - data->player->pos_y;
		sprite->inv_det = 1.0 / (data->player->plane_x * data->player->dir_y
			- data->player->dir_x * data->player->plane_y);
		sprite->transform_x = sprite->inv_det * (data->player->dir_y
			* sprite->sprite_x - data->player->dir_x * sprite->sprite_y);
		sprite->transform_y = sprite->inv_det * (
			-data->player->plane_y * sprite->sprite_x
			+ data->player->plane_x * sprite->sprite_y);
		sprite->sprite_screen_x = (int)(data->width / 2) *(1
			+ sprite->transform_x / sprite->transform_y);
		sprite->v_move_screen = (int)(VMOVE / sprite->transform_y);
		sprite->sprite_height = (int)fabs(
			(data->height / sprite->transform_y)) / VDIV;
		sprite->sprite_draw_start_y = -sprite->sprite_height / 2
		+ data->height / 2 + sprite->v_move_screen;
}

void	sprite_raycast_draw_start_end(t_data *data, t_sprite *sprite)
{
	if (sprite->sprite_draw_start_y < 0)
		sprite->sprite_draw_start_y = 0;
	sprite->sprite_draw_end_y = sprite->sprite_height / 2
		+ data->height / 2 + sprite->v_move_screen;
	if (sprite->sprite_draw_end_y >= data->height)
		sprite->sprite_draw_end_y = data->height - 1;
	sprite->sprite_width = (int)fabs((
				data->height / sprite->transform_y)) / UDIV;
	sprite->sprite_draw_start_x = -sprite->sprite_width / 2
		+ sprite->sprite_screen_x;
	if (sprite->sprite_draw_start_x < 0)
		sprite->sprite_draw_start_x = 0;
	sprite->sprite_draw_end_x = sprite->sprite_width / 2
		+ sprite->sprite_screen_x;
	if (sprite->sprite_draw_end_x >= data->width)
		sprite->sprite_draw_end_x = data->width - 1;
}

void	sprite_raycast_tex_pos(t_data *data, t_sprite *sprite)
{
	int			y;
	int			stripe;

	stripe = sprite->sprite_draw_start_x;
	while (stripe < sprite->sprite_draw_end_x)
	{
		sprite->tex_x = (int)(256 * (stripe - (-sprite->sprite_width
						/ 2 + sprite->sprite_screen_x))
				* data->keys[0].tex[0].w
				/ sprite->sprite_width) / 256;
		if (sprite->transform_y > 0 && stripe > 0 && stripe < data->width)
		{
			y = sprite->sprite_draw_start_y;
			while (y < sprite->sprite_draw_end_y)
			{
				sprite->d = (y - sprite->v_move_screen) * 256
					- data->height * 128 + sprite->sprite_height * 128;
				sprite->tex_y = ((sprite->d * data->keys[sprite->i].tex[0].h)
						/ sprite->sprite_height) / 256;
				mlx_draw_sprite(data, *sprite, y, stripe);
				y++;
			}
		}
		stripe++;
	}
}

void	sprite_raycast(t_data *data)
{
	t_sprite	sprite;

	sprite.i = 0;
	while (sprite.i < data->len_keys)
	{
		sprite_raycast_init(data, &sprite);
		sprite_raycast_draw_start_end(data, &sprite);
		sprite_raycast_tex_pos(data, &sprite);
		sprite.i++;
	}
}
