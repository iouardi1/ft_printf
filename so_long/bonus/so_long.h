/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:44:07 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/14 16:33:07 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define mp game->mapy
# define ml game->mlx
# define pl game->tanjiro
# define im game->img

typedef struct s_player {
	int		x;
	int		y;
	int		eaten_collect;
	char	*move;
}	t_player;

typedef struct s_mapy {
	int		height;
	int		width;
	int		v_ntiles;
	int		h_ntiles;
	char	**arr;
	int		collects;
	void	*wall;
	void	*player;
	void	*collect;
	void	*exit;
}	t_mapy;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}	t_data;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

typedef struct s_game {
	t_player	*tanjiro;
	t_data		img;
	t_mlx		mlx;
	t_mapy		*mapy;
}	t_game;

void	draw_map_bonus_bonus(t_game *game);
void	my_mlx_pixel_put_bonus(t_data *data, int x, int y, int color);
void	read_the_map_bonus(t_game *game, int fd);
int		try_bonus(int a, t_game *game);
void	draw_player_bonus(t_game *game);
void	draw_map2_bonus(t_game *game);
int		check_five_char_bonus(t_game *game);
int		parsing_map_bonus(t_game *game);
int		check_rectangularity_bonus(t_game *game);
int		one_player_bonus(t_game *game);
int		draw_player_supports_bonus(t_game *game);
void	init_imgs_bonus(t_game *game);
void	initialize_bonus(t_game *game, char *map_file);
int		check_vertical_walls_bonus(t_game *game);
int		check_horizontal_walls_bonus(t_game *game);
void	eaten_collect_bonus(t_game *game);
int		check_parsing_bonus(t_game *game);
int		clooose_bonus(int keycode, t_game *game);
void	free_map_bonus(t_game *game);
void	free_imgs_bonus(t_game *game);
void	free_struct_bonus(t_game *game);
void	free_n_exit_bonus(t_game *game);

#endif
