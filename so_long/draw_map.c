#include "so_long.h"

void	draw_map(t_game *game)
{
	int			x = 0;
	int			y = 0;
	
	game->mapy->v_ntiles = 0;
	game->mapy->collects = 0;
	while (game->mapy->arr[game->mapy->v_ntiles])
	{
		game->mapy->h_ntiles = 0;
		x = 0;
		while (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles])
		{
			if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == '0')
			{
				game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx_win, "./images_xpm/pastel.xpm", &width_tile, &height_tile);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.color, x, y);
			}
			if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == '1')
			{
				game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx_win, "./images_xpm/my_walls_xpm/wall.xpm", &width_tile, &height_tile);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.color, x, y);
			}
			else if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == 'C')
			{
				game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx_win,"./images_xpm/nizku75.xpm", &width_tile, &height_tile);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.color, x, y);
				game->mapy->collects++;
			}
			else if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == 'P')
			{
				game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx_win, "./images_xpm/tanjiro_xpm_moves/frontlook_tanjiro75.xpm", &width_tile, &height_tile);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.color, x, y);
				game->tanjiro->x = x + 15;
				game->tanjiro->y = y;
			}
			else if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == 'E')
			{
				game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx_win, "./images_xpm/nizku_box.xpm", &width_tile, &height_tile);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.color, x, y);
			}
			x += 75;
			game->mapy->h_ntiles += 1;
		}
		y += 75;
		game->mapy->v_ntiles += 1;
	}
	// printf("%d   %d", game->mapy->v_ntiles, game->mapy->h_ntiles);
}

void	draw_map2(t_game *game)
{
	int			x = 0;
	int			y = 0;
	
	game->mapy->v_ntiles = 0;
	
	while (game->mapy->arr[game->mapy->v_ntiles])
	{
		game->mapy->h_ntiles = 0;
		x = 0;
		while (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles])
		{
			if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == '0')
			{
				game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx_win, "./images_xpm/pastel.xpm", &width_tile, &height_tile);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.color, x, y);
			}
			if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == '1')
			{
				game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx_win, "./images_xpm/my_walls_xpm/wall.xpm", &width_tile, &height_tile);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.color, x, y);
			}
			else if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == 'C')
			{
				game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx_win,"./images_xpm/nizku75.xpm", &width_tile, &height_tile);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.color, x, y);
			}
			else if (game->mapy->arr[game->mapy->v_ntiles][game->mapy->h_ntiles] == 'E')
			{
				game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx_win, "./images_xpm/nizku_box.xpm", &width_tile, &height_tile);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.color, x, y);
			}
			else
				game->mlx.color = mlx_xpm_file_to_image(game->mlx.mlx_win, "./images_xpm/pastel.xpm", &width_tile, &height_tile);
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.color, x, y);
			x += 75;
			game->mapy->h_ntiles += 1;
		}
		y += 75;
		game->mapy->v_ntiles += 1;
	}
	draw_player(game);
}