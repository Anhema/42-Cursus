/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:30:32 by aherrero          #+#    #+#             */
/*   Updated: 2022/02/22 16:40:43 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include  "libft/libft.h"
# include <stdlib.h>
# include  <mlx.h>

typedef struct s_enemy {
	float		x;
	float		y;
	int			dir;
	int			current_enemy_sprite;
	void		*down[4];
	void		*up[4];
	void		*left[4];
	void		*right[4];
}				t_enemy;

typedef struct s_player {
	float		x;
	float		y;
	int			dir;
	int			current_player_sprite;
	void		*down[4];
	void		*up[4];
	void		*left[4];
	void		*right[4];
}				t_player;

typedef struct s_coins {
	int		current_coins;
	int		current_coins_sprite;
	void	*sprites[4];
}				t_coins;

typedef struct s_game {
	void			*mlx;
	void			*win;
	char			**map;
	int				x;
	int				y;
	int				pixel;
	int				movements;
	int				frame;
	void			*background;
	void			*wall[25];
	void			*exit[2];
	t_coins			coins;
	t_player		player;
	t_enemy			*enemy;
	int				enemy_conut;
}				t_game;

int		check_rectangle(char **file);
int		check_extension(char *str);
int		check_chars(char **map);
void	free_string_array(char **lines);
void	print_console(t_game *game);
int		closed_map(char **lines);
char	**map_validator(char *argv);
void	draw_map(t_game *game);
int		close_win(void *param);
void	enemy_col(t_game *game);
t_game	init_game(t_game game);
t_game	get_images(t_game game);
t_game	get_images_enemy_down_up(t_game game, int i);
t_game	get_images_enemy_right_left(t_game game, int i);
t_game	get_images_player_down_up(t_game game);
t_game	get_images_player_right_left(t_game game);
t_game	draw_items(t_game game);
t_game	draw_player(t_game game);
t_game	draw_enemy(t_game game, int i);
t_game	draw_walls(t_game game);
t_game	draw_background(t_game game);
void	draw_items_e(t_game game, int x, int y);
t_game	delete_images_coins(t_game game);
t_game	delete_images(t_game game);
void	put_area_aux(t_game game, int x, int y);
t_game	player_move_up(t_game *game);
t_game	player_move_down(t_game *game);
t_game	player_move_left(t_game *game);
t_game	player_move_right(t_game *game);
t_game	enemy_move_up(t_game *game, int n);
t_game	enemy_move_down(t_game *game, int n);
t_game	enemy_move_left(t_game *game, int n);
t_game	enemy_move_right(t_game *game, int n);

#endif
