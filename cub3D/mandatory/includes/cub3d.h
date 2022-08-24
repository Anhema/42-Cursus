/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:24:45 by aherrero          #+#    #+#             */
/*   Updated: 2022/08/11 19:20:19 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include  "../libft/libft.h"
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# define SIZE 64
# define WIDTH 900
# define HEIGTH 600
# define MOVE_SPEED 0.2
# define ROT_SPEED 0.3

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
	t_mlx			tex[4];
	int				tex_height;
	int				tex_width;
	int				f;
	int				c;
	char			**map;
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
//terminal functions
void			change_value(t_data *data);
void			player_s(t_data *data);
void			player_a(t_data *data);
void			player_w(t_data *data);
void			player_d(t_data *data);
//raycasting related functions
int				main_loop(t_data *data);
void			raycast(t_data *data);
void			raycast_init(t_data *data, t_ray *ray);
void			raycast_dir(t_data *data, t_ray *ray);
void			raycast_hit(t_data *data, t_ray *ray);
void			raycast_draw_pos(t_data *data, t_ray *ray);
void			get_texture_id(t_ray *ray);
void			texturing_calculations(t_data *data, t_ray *ray);
void			print_map(t_data *data, t_ray ray);
//camera movements related function
void			cam_left(t_data *data);
void			cam_right(t_data *data);
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
int				len(char *str, char c);
#endif
