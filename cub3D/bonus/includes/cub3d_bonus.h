/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:24:45 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/14 22:29:23 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include  "../libft/libft.h"
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# define WIDTH 900
# define HEIGTH 600
# define MOVE_SPEED 0.2
# define ROT_SPEED 0.1
# define MINIMAP_SIZE 7
# define FLOOR_TILING 4
# define SKY_TILING 1
# define PRESS_IMG "../../textures/press.xpm"
# define KEY_0 "./textures/keys/key.xpm"
# define KEY_1 "./textures/keys/key1.xpm"
# define KEY_2 "./textures/keys/key2.xpm"
# define KEY_3 "./textures/keys/key3.xpm"
# define KEY_4 "./textures/keys/key4.xpm"
# define KEY_5 "./textures/keys/key5.xpm"
# define KEY_6 "./textures/keys/key6.xpm"	

typedef struct s_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_mlx;

typedef struct s_validate
{
	int		is_map;
	char	**headers;
	char	*file;
	int		n;
	int		y;
	int		i;
	int		k;
}				t_validate;

typedef struct s_key
{
	t_mlx	tex[7];
	int		x;
	int		y;
}				t_key;

typedef struct s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;

	int		x;
	int		y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;

	int		line_height;
	int		draw_start;
	int		draw_end;
	int		h;

	int		tex_x;
	int		tex_y;
	int		tex;
}				t_ray;

typedef struct s_ray_floor
{
	float	ray_dir_x_0;
	float	ray_dir_y_0;
	float	ray_dir_x_1;
	float	ray_dir_y_1;
	int		p;
	float	pos_z;
	float	row_distance;
	float	floor_step_x;
	float	floor_step_y;
	float	floor_x;
	float	floor_y;
	int		cell_x;
	int		cell_y;
	int		tx_f;
	int		tx_c;
	int		ty_f;
	int		ty_c;
	int		y;
	int		x;
}				t_ray_floor;

typedef struct s_ray_sprite
{
	int				i;
	int				sprite_order;
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				sprite_draw_start_y;
	int				sprite_draw_end_y;
	int				sprite_draw_start_x;
	int				sprite_draw_end_x;
	int				tex_x;
	int				d;
	int				tex_y;
	int				v_move_screen;
}				t_sprite;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	int		x;
	int		y;
	double	dir_x;
	double	old_dir_x;
	double	dir_y;
	double	plane_x;
	double	old_plane_x;
	double	plane_y;
}				t_player;

typedef struct s_data
{
	int				width;
	int				height;
	void			*mlx;
	void			*window;
	t_mlx			sky;
	t_mlx			floor;
	t_mlx			tex[6];
	int				tex_height;
	int				tex_width;
	int				cam_x;
	int				f;
	int				c;
	int				d;
	int				fps;
	int				doors_open;
	char			**map;
	int				n_keys;
	int				len_keys;
	int				key_anim;
	t_key			*keys;
	t_player		*player;
	t_mlx			*mlx_s;
}				t_data;

void			init_window(t_data data);
void			get_fill_map(t_data *cube, char *argv);
void			get_player_init(t_data *data);
void			print_data(t_data *data);
void			free_double_char(char **str);

int				map_validation(int argc, char **argv);
int				headers_validation_check(int i, int j,
					char **lines, t_validate *map);
int				check_is_map(t_validate *map, char *file, char **lines, int i);
int				indentifies_value_validation(
					char **lines, int j, int i, char *file);
void			print_map_error(char *str, char *file, char **lines);
int				check_f_c_validation(char **lines, int j, int i, char *file);
char			**check_repeated_header(char **lines,
					char *file, char **header, char *current);
int				check_first_last_lines(char **lines, char *file, int i);
void			map_is_closed(char **lines, char *file, int i, int j);
void			check_map_multiple_lines(char **lines, char *file);
void			check_not_full_line(char **lines, char *file, int i, int j);
char			**create_new(char **header, int i, char *id);
void			ft_free(char **header, char *current, char *id);
void			check_rgb(char *value, char *file, char **lines, int n);

void			continue_validate_map_ext(t_validate *map, char **lines,
					char *file, int j);
//terminal functions
void			change_value(t_data *data);
void			player_s(t_data *data);
void			player_a(t_data *data);
void			player_w(t_data *data);
void			player_d(t_data *data);
void			player_s_ext(t_data *data, double moved_x, double moved_y);
void			player_a_ext(t_data *data, double moved_x, double moved_y);
void			player_w_ext(t_data *data, double moved_x, double moved_y);
void			player_d_ext(t_data *data, double moved_x, double moved_y);
//raycasting related functions
int				main_loop(t_data *data);
void			raycast(t_data *data);
void			raycast_init(t_data *data, t_ray *ray);
void			raycast_dir(t_data *data, t_ray *ray);
void			raycast_hit(t_data *data, t_ray *ray);
void			raycast_draw_pos(t_data *data, t_ray *ray);
void			get_texture_id(t_ray *ray, t_data *data);
void			texturing_calculations(t_data *data, t_ray *ray);
void			print_map(t_data *data, t_ray ray);
void			print_cube(int offset_x, int offset_y, t_data *data, int color);
void			minimap(t_data *data);
void			mlx_draw_img(t_data *data, t_mlx texture, int size_scale);
void			mlx_draw_column_fc(t_data *data,
					t_ray_floor ray, t_mlx texture, int i);
void			sky_floor_raycast(t_data *data);
void			sprite_raycast(t_data *data);
void			mlx_draw_sprite(t_data *data,
					t_sprite sprite, int y, int stripe);

int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);

int				create_trgb(int t, int r, int g, int b);
unsigned int	my_mlx_pixel_get(t_data *data, int x, int y);
//camera movements related function
void			cam_left(t_data *data);
void			cam_right(t_data *data);
int				cam(int x, int y, t_data *data);
//moves related functions
void			move_a(t_data *data, char orientation);
void			move_w(t_data *data, char orientation);
void			move_s(t_data *data, char orientation);
void			move_d(t_data *data, char orientation);
void			move_to_n(t_data *data);
void			move_to_s(t_data *data);
void			move_to_w(t_data *data);
void			move_to_e(t_data *data);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			print_texture(
					t_data *data, t_ray ray, double tex_pos, double step);
unsigned int	get_mlx_pixel_color(t_mlx *mlx_s, int x, int y);
void			free_double_char(char **str);
void			ft_rgb_checker(
					char *value, char **rgb, char *file, char **lines);
void			ft_indentifier_error(
					char *value, int fd, char *file, char **lines);
void			ft_check_identifier(
					char *value, char *file, char **lines, int i);
void			ft_check_format(char *value, char *file, char **lines);
//get map
void			fill_map(t_data *data, char **lines, int i, int j);
void			get_headers(t_data *data, char *read);
void			get_keys_init(t_data *data);
int				len(char *str, char c);
t_mlx			get_keys_textures(t_data *data, int k);
t_mlx			get_textures(t_data *data, char c, char *read);
char			*fill_head(char *read, char c);
void			reset_doors(t_data *data);
#endif
