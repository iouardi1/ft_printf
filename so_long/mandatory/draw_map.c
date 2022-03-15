/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:28:01 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/14 18:02:25 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map_support(t_game *game, int y)
{
	int		x;

	x = 0;
	while (mp->arr[mp->v_ntiles][mp->h_ntiles])
	{
		if (mp->arr[mp->v_ntiles][mp->h_ntiles] == '1')
			mlx_put_image_to_window(ml.mlx, ml.mlx_win, mp->wall, x, y);
		else if (mp->arr[mp->v_ntiles][mp->h_ntiles] == 'C')
		{
			mlx_put_image_to_window(ml.mlx, ml.mlx_win, mp->collect, x, y);
			mp->collects++;
		}
		else if (mp->arr[mp->v_ntiles][mp->h_ntiles] == 'P')
		{
			mlx_put_image_to_window(ml.mlx, ml.mlx_win, mp->player, x, y);
			game->tanjiro->x = x;
			game->tanjiro->y = y;
		}
		else if (mp->arr[mp->v_ntiles][mp->h_ntiles] == 'E')
			mlx_put_image_to_window(ml.mlx, ml.mlx_win, mp->exit, x, y);
		x += 75;
		mp->h_ntiles += 1;
	}
}

void	draw_map(t_game *game)
{
	int			y;

	y = 0;
	mp->v_ntiles = 0;
	mp->collects = 0;
	ml.mlx_win = mlx_new_window(ml.mlx, \
		mp->height, mp->width, "Tanjirooooo");
	im.img = mlx_new_image(ml.mlx, mp->height, mp->width);
	im.addr = mlx_get_data_addr(im.img, \
		&im.bits_per_pixel, &im.line_length, &im.endian);
	while (mp->arr[mp->v_ntiles])
	{
		mp->h_ntiles = 0;
		draw_map_support(game, y);
		y += 75;
		mp->v_ntiles += 1;
	}
}

void	draw_player(t_game *game)
{
	int		w;
	int		h;

	if (draw_player_supports(game))
	{
		if (!ft_strncmp(pl->move, "ri", 3))
		{
			mp->player = mlx_xpm_file_to_image(ml.mlx_win, \
				"mandatory/images_xpm/rightlook.xpm", &w, &h);
			mlx_put_image_to_window(ml.mlx, ml.mlx_win, \
				mp->player, pl->x, pl->y);
		}
		else if (!ft_strncmp(pl->move, "le", 3))
		{
			mp->player = mlx_xpm_file_to_image(ml.mlx_win, \
				"mandatory/images_xpm/leftlook.xpm", &w, &h);
			mlx_put_image_to_window(ml.mlx, ml.mlx_win, \
				mp->player, pl->x, pl->y);
		}
	}
}

void	draw_map2(t_game *game)
{
	int			x;
	int			y;

	y = 0;
	mp->v_ntiles = 0;
	while (mp->arr[mp->v_ntiles])
	{
		mp->h_ntiles = 0;
		x = 0;
		while (mp->arr[mp->v_ntiles][mp->h_ntiles])
		{
			if (mp->arr[mp->v_ntiles][mp->h_ntiles] == '1')
				mlx_put_image_to_window(ml.mlx, ml.mlx_win, mp->wall, x, y);
			else if (mp->arr[mp->v_ntiles][mp->h_ntiles] == 'C')
				mlx_put_image_to_window(ml.mlx, ml.mlx_win, mp->collect, x, y);
			else if (mp->arr[mp->v_ntiles][mp->h_ntiles] == 'E')
				mlx_put_image_to_window(ml.mlx, ml.mlx_win, mp->exit, x, y);
			x += 75;
			mp->h_ntiles += 1;
		}
		y += 75;
		mp->v_ntiles += 1;
	}
	draw_player(game);
}
