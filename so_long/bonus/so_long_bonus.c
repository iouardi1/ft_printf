/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:14:43 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/14 16:27:10 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	try_harder_bonus(t_game *game, int a)
{
	if (a == 125)
	{
		if (mp->arr[(pl->y / 75) + 1][(pl->x / 75)] != '1')
			pl->y += 75;
		pl->move = "do";
	}
	if (a == 126)
	{
		if (mp->arr[(pl->y / 75) - 1][(pl->x / 75)] != '1')
			pl->y -= 75;
		pl->move = "up";
	}
	if (a == 123)
	{
		if (mp->arr[(pl->y / 75)][(pl->x / 75) - 1] != '1')
			pl->x -= 75;
		pl->move = "le";
	}
	if (a == 124)
	{
		if (mp->arr[(pl->y / 75)][(pl->x / 75) + 1] != '1')
			pl->x += 75;
		pl->move = "ri";
	}
}

int	try_bonus(int a, t_game *game)
{
	if (a == 53)
		exit(0);
	// free_n_exit(game);
	try_harder(game, a);
	eaten_collect(game);
	mlx_clear_window(ml.mlx, ml.mlx_win);
	im.img = mlx_new_image(ml.mlx, mp->height, mp->width);
	im.addr = mlx_get_data_addr(im.img, \
		&im.bits_per_pixel, &im.line_length, &im.endian);
	draw_map2(game);
	return (0);
}

void	eaten_collect_bonus(t_game *game)
{
	if (mp->arr[(pl->y / 75)][(pl->x / 75)] == 'C')
	{
		mp->arr[(pl->y / 75)][(pl->x / 75)] = '0';
		pl->eaten_collect++;
	}
	if (pl->eaten_collect == mp->collects && \
		mp->arr[(pl->y / 75)][(pl->x / 75)] == 'E')
		exit(0);
}

int	clooose_bonus(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	// free_n_exit(game);
	exit(0);
}

int	draw_player_supports_bonus(t_game *game)
{
	int		w;
	int		h;

	if (!ft_strncmp(pl->move, "do", 3))
	{
		mp->player = mlx_xpm_file_to_image(ml.mlx_win, \
			"./images_xpm/frontlook.xpm", &w, &h);
		mlx_put_image_to_window(ml.mlx, ml.mlx_win, mp->player, pl->x, pl->y);
		return (0);
	}
	else if (!ft_strncmp(pl->move, "up", 3))
	{
		mp->player = mlx_xpm_file_to_image(ml.mlx_win, \
			"./images_xpm/backlook.xpm", &w, &h);
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
		initialize_bonus(game, argv[1]);
		if (!check_parsing_bonus(game))
			free_n_exit_bonus(game);
		draw_map_bonus(game);
		mlx_hook(ml.mlx_win, 2, 0, try, game);
		mlx_hook(ml.mlx_win, 17, 1L<<5, clooose, game);
		mlx_loop(ml.mlx);
	}
	// system("leaks so_long");
	return (0);
}
