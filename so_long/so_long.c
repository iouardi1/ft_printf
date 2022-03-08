/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:14:43 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/09 00:43:48 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int try(int a, t_game *game)// worth every penis
{
	if (a == 125 && game->mapy->arr[(game->tanjiro->y / 75) + 1][(game->tanjiro->x / 75)] != '1') // lte7t
	{
		game->tanjiro->y += height_tile;
		game->tanjiro->move = "do";
	}
	if (a == 126 && game->mapy->arr[(game->tanjiro->y / 75) - 1][(game->tanjiro->x / 75)] != '1') //up
	{
		game->tanjiro->y -= height_tile;
		game->tanjiro->move = "up";
	}
	if (a == 123 && game->mapy->arr[(game->tanjiro->y / 75)][((game->tanjiro->x - 15) / 75) - 1] != '1') //left
	{
		game->tanjiro->x -= width_tile;
		game->tanjiro->move = "le";
	}
	if (a == 124 && game->mapy->arr[(game->tanjiro->y / 75)][((game->tanjiro->x - 15) / 75) + 1] != '1') //right
	{
		game->tanjiro->x += width_tile;
		game->tanjiro->move = "ri";
	}
	if (game->mapy->arr[(game->tanjiro->y / 75)][(game->tanjiro->x / 75)] == 'C')
	{
		game->mapy->arr[(game->tanjiro->y / 75)][(game->tanjiro->x / 75)] = '0';
		game->tanjiro->eaten_collect++;
	}
	mlx_clear_window(game->mlx.mlx, game->mlx.mlx_win);
	game->img.img = mlx_new_image(game->mlx.mlx, game->mapy->height, game->mapy->width);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	draw_map2(game);
	return 0;
}

void	draw_player(t_game *game)
{
	if (!ft_strncmp(game->tanjiro->move, "do", 3))
	{
		game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx_win, "./images_xpm/tanjiro_xpm_moves/frontlook_tanjiro75.xpm", &width_tile, &height_tile);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.color, game->tanjiro->x, game->tanjiro->y);
	}
	else if (!ft_strncmp(game->tanjiro->move, "up", 3))
	{
		game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx_win, "./images_xpm/tanjiro_xpm_moves/backlook_tanjiro75 .xpm", &width_tile, &height_tile);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.color, game->tanjiro->x, game->tanjiro->y);
	}
	else if (!ft_strncmp(game->tanjiro->move, "ri", 3))
	{
		game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx_win, "./images_xpm/tanjiro_xpm_moves/rightlook_tanjiro75.xpm", &width_tile, &height_tile);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.color, game->tanjiro->x, game->tanjiro->y);
	}
	else if (!ft_strncmp(game->tanjiro->move, "le", 3))
	{
		game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx_win, "./images_xpm/tanjiro_xpm_moves/leftlook_tanjiro75.xpm", &width_tile, &height_tile);
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.color, game->tanjiro->x, game->tanjiro->y);
	}
}

int	main(void)
{
	t_game *game;
	int		fd = open("my_map.ber", O_RDONLY);
	char	*relative_path = "./images_xpm/nizku75.xpm";
	width_tile = 75;
	height_tile = 75;
	
	game = malloc(sizeof(t_game));
	game->mapy = malloc(sizeof(t_mapy));
	game->mapy->arr = read_the_map(fd);
	game->mlx.mlx = mlx_init();
	game->mapy->h_ntiles = 0;
	game->tanjiro = malloc(sizeof(t_player));
	game->tanjiro->eaten_collect = 0;
	game->tanjiro->move = malloc(sizeof(char) * 3);
	
	if (!parsing_map(game))
	{
		printf("heeeeeere\n");
		return(0);
	}
	while (game->mapy->arr[game->mapy->h_ntiles])
	{
		game->mapy->v_ntiles = 0;
		while(game->mapy->arr[game->mapy->h_ntiles][game->mapy->v_ntiles])
			game->mapy->v_ntiles++;
		game->mapy->h_ntiles++;
	}
	game->mapy->height = game->mapy->v_ntiles * width_tile;
	game->mapy->width = game->mapy->h_ntiles * height_tile;
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx, game->mapy->height, game->mapy->width, "Tanjirooooo");
	game->img.img = mlx_new_image(game->mlx.mlx, game->mapy->height, game->mapy->width);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx, relative_path, &game->img.img_width, &game->img.img_height);
	draw_map(game);
	// printf("%d   %d", game->mapy->v_ntiles, game->mapy->h_ntiles);
	//mlx_key_hook(game->mlx.mlx_win, try, game); // new
	mlx_hook(game->mlx.mlx_win, 2, 1L >> 1, try, game); //
	// (arr, color, mlx, mlx_win); /// new
	mlx_loop(game->mlx.mlx);
}
