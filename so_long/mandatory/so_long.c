/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:14:43 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/16 22:40:58 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	try_harder(t_game *game, int a)
{
	if (a == 125)
	{
		if (game->mapy->arr[(game->tanjiro->y / 75) + 1][(game->tanjiro->x / 75)] != '1')
		{
			game->tanjiro->count_moves += 1;
			printf("%d\n", game->tanjiro->count_moves);
			game->tanjiro->y += 75;
		}
		free(game->tanjiro->move);
		game->tanjiro->move = ft_strdup("do");
	}
	if (a == 126)
	{
		if (game->mapy->arr[(game->tanjiro->y / 75) - 1][(game->tanjiro->x / 75)] != '1')
		{
			game->tanjiro->count_moves += 1;
			printf("%d\n", game->tanjiro->count_moves);
			game->tanjiro->y -= 75;
		}
		free(game->tanjiro->move);
		game->tanjiro->move = ft_strdup("up");
	}
	if (a == 123)
	{
		if (game->mapy->arr[(game->tanjiro->y / 75)][(game->tanjiro->x / 75) - 1] != '1')
		{
			game->tanjiro->count_moves += 1;
			printf("%d\n", game->tanjiro->count_moves);	
			game->tanjiro->x -= 75;
		}
		free(game->tanjiro->move);
		game->tanjiro->move = ft_strdup("le");
	}
	if (a == 124)
	{
		if (game->mapy->arr[(game->tanjiro->y / 75)][(game->tanjiro->x / 75) + 1] != '1')
		{
			game->tanjiro->count_moves += 1;
			printf("%d\n", game->tanjiro->count_moves);	
			game->tanjiro->x += 75;
		}
		free(game->tanjiro->move);
		game->tanjiro->move = ft_strdup("ri");
	}
}

int	try(int a, t_game *game)
{
	if (a == 53)
		exit (0);
	try_harder(game, a);
	eaten_collect(game);
	mlx_clear_window(game->mlx.mlx, game->mlx.mlx_win);
	game->img.img = mlx_new_image(game->mlx.mlx, game->mapy->height, game->mapy->width);
	game->img.addr = mlx_get_data_addr(game->img.img, \
		&game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	draw_map2(game);
	return (0);
}

void	eaten_collect(t_game *game)
{
	if (game->mapy->arr[(game->tanjiro->y / 75)][(game->tanjiro->x / 75)] == 'C')
	{
		game->mapy->arr[(game->tanjiro->y / 75)][(game->tanjiro->x / 75)] = '0';
		game->tanjiro->eaten_collect++;
	}
	if (game->tanjiro->eaten_collect == game->mapy->collects && \
		game->mapy->arr[(game->tanjiro->y / 75)][(game->tanjiro->x / 75)] == 'E')
		exit (0);
}

int	clooose(t_game *game)
{
	free(game);
	exit (0);
}

int	draw_player_supports(t_game *game)
{
	int		w;
	int		h;

	if (!ft_strncmp(game->tanjiro->move, "do", 3))
	{
		game->mapy->player = mlx_xpm_file_to_image(game->mlx.mlx_win, \
			"mandatory/images_xpm/frontlook.xpm", &w, &h);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mapy->player, game->tanjiro->x, game->tanjiro->y);
		return (0);
	}
	else if (!ft_strncmp(game->tanjiro->move, "up", 3))
	{
		game->mapy->player = mlx_xpm_file_to_image(game->mlx.mlx_win, \
			"mandatory/images_xpm/backlook.xpm", &w, &h);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mapy->player, game->tanjiro->x, game->tanjiro->y);
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
			exit (0);
		draw_map(game);
		mlx_hook(game->mlx.mlx_win, 2, 0, try, game);
		mlx_hook(game->mlx.mlx_win, 17, 1L<<5, clooose, game);
		mlx_loop(game->mlx.mlx);
	}
	free(game);
	return (0);
}
