#ifndef SO_LONG_H
#define SO_LONG_H
#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"

int width_tile;
int height_tile;


typedef struct	s_player {
	int 	x;
	int 	y;
	int		eaten_collect;
	char	*move;
}	t_player;

typedef struct	s_mapy {
	int		height;
	int		width;
	int		v_ntiles;
	int		h_ntiles;
	char	**arr;
	int		collects;
}	t_mapy;

typedef struct	s_data {
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
	void	*color;
}	t_mlx;

typedef struct 	s_game {
	t_player	*tanjiro;
	t_data		img;
	t_mlx		mlx;
	t_mapy		*mapy;
}	t_game;

void	draw_map(t_game *game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	**read_the_map(int fd);
int 	try(int a, t_game *game);
void	draw_player(t_game *game);
void	draw_map2(t_game *game);
int	check_five_char(t_game *game);
int	parsing_map(t_game *game);
int	check_rectangularity(t_game *game);
int	one_player(t_game *game);

#endif
