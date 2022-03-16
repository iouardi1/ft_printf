/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:28:01 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/16 22:41:35 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map_support(t_game *game, int y)
{
	int		x;

	x = 0;
	while (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles])
	{
		if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == '1')
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mapy->wall, x, y);
		else if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == 'C')
		{
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mapy->collect, x, y);
			game->mapy->collects++;
		}
		else if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == 'P')
		{
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mapy->player, x, y);
			game->tanjiro->x = x;
			game->tanjiro->y = y;
		}
		else if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == 'E')
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mapy->exit, x, y);
		x += 75;
		game->mapy->h_ntiles += 1;
	}
}

void	draw_map(t_game *game)
{
	int			y;

	y = 0;
	game->mapy->v_ntiles = 0;
	game->mapy->collects = 0;
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx, \
		game->mapy->height, game->mapy->width, "Tanjirooooo");
	game->img.img = mlx_new_image(game->mlx.mlx, game->mapy->height, game->mapy->width);
	game->img.addr = mlx_get_data_addr(game->img.img, \
		&game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	while (game->mapy->arr[game->mapy->v_ntiles])
	{
		game->mapy->h_ntiles = 0;
		draw_map_support(game, y);
		y += 75;
		game->mapy->v_ntiles += 1;
	}
}

void	draw_player(t_game *game)
{
	int		w;
	int		h;

	if (draw_player_supports(game))
	{
		if (!ft_strncmp(game->tanjiro->move, "ri", 3))
		{
			game->mapy->player = mlx_xpm_file_to_image(game->mlx.mlx_win, \
				"mandatory/images_xpm/rightlook.xpm", &w, &h);
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
				game->mapy->player, game->tanjiro->x, game->tanjiro->y);
		}
		else if (!ft_strncmp(game->tanjiro->move, "le", 3))
		{
			game->mapy->player = mlx_xpm_file_to_image(game->mlx.mlx_win, \
				"mandatory/images_xpm/leftlook.xpm", &w, &h);
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
				game->mapy->player, game->tanjiro->x, game->tanjiro->y);
		}
	}
}

void	draw_map2(t_game *game)
{
	int			x;
	int			y;

	y = 0;
	game->mapy->v_ntiles = 0;
	while (game->mapy->arr[game->mapy->v_ntiles])
	{
		game->mapy->h_ntiles = 0;
		x = 0;
		while (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles])
		{
			if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mapy->wall, x, y);
			else if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == 'C')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mapy->collect, x, y);
			else if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == 'E')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mapy->exit, x, y);
			x += 75;
			game->mapy->h_ntiles += 1;
		}
		y += 75;
		game->mapy->v_ntiles += 1;
	}
	draw_player(game);
}
