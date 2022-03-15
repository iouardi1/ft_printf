/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:14:43 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/15 12:56:14 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	try_harder(t_game *game, int a)
{
	if (a == 125)
	{
		if (mp->arr[(pl->y / 75) + 1][(pl->x / 75)] != '1')
			pl->y += 75;
		pl->move = strcpy(pl->move, "do");
	}
	if (a == 126)
	{
		if (mp->arr[(pl->y / 75) - 1][(pl->x / 75)] != '1')
			pl->y -= 75;
		pl->move = strcpy(pl->move, "up");
	}
	if (a == 123)
	{
		if (mp->arr[(pl->y / 75)][(pl->x / 75) - 1] != '1')
			pl->x -= 75;
		pl->move = strcpy(pl->move, "le");
	}
	if (a == 124)
	{
		if (mp->arr[(pl->y / 75)][(pl->x / 75) + 1] != '1')
			pl->x += 75;
		pl->move = strcpy(pl->move, "ri");
	}
}

int	try(int a, t_game *game)
{
	if (a == 53)
		free_n_exit(game);
		// exit(0);
	try_harder(game, a);
	eaten_collect(game);
	mlx_clear_window(ml.mlx, ml.mlx_win);
	im.img = mlx_new_image(ml.mlx, mp->height, mp->width);
	im.addr = mlx_get_data_addr(im.img, \
		&im.bits_per_pixel, &im.line_length, &im.endian);
	draw_map2(game);
	return (0);
}

void	eaten_collect(t_game *game)
{
	if (mp->arr[(pl->y / 75)][(pl->x / 75)] == 'C')
	{
		mp->arr[(pl->y / 75)][(pl->x / 75)] = '0';
		pl->eaten_collect++;
	}
	if (pl->eaten_collect == mp->collects && \
		mp->arr[(pl->y / 75)][(pl->x / 75)] == 'E')
		free_n_exit(game);
		// exit(0);
}

int	clooose(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	free_n_exit(game);
	return (0);
}

int	draw_player_supports(t_game *game)
{
	int		w;
	int		h;

	if (!ft_strncmp(pl->move, "do", 3))
	{
		mp->player = mlx_xpm_file_to_image(ml.mlx_win, \
			"mandatory/images_xpm/frontlook.xpm", &w, &h);
		mlx_put_image_to_window(ml.mlx, ml.mlx_win, mp->player, pl->x, pl->y);
		return (0);
	}
	else if (!ft_strncmp(pl->move, "up", 3))
	{
		mp->player = mlx_xpm_file_to_image(ml.mlx_win, \
			"mandatory/images_xpm/backlook.xpm", &w, &h);
		mlx_put_image_to_window(ml.mlx, ml.mlx_win, mp->player, pl->x, pl->y);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (argc == 2)
	{
		initialize(game, argv[1]);
		if (!check_parsing(game))
			free_n_exit(game);
		draw_map(game);
		mlx_hook(ml.mlx_win, 2, 0, try, game);
		mlx_hook(ml.mlx_win, 17, 1L<<5, clooose, game);
		mlx_loop(ml.mlx);
	}
	return (0);
}
