/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_pictures_initialize_check_parsing.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:14:37 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/10 23:43:24 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	link_pictures(t_game *game)
{
	int		height_tile;
	int		width_tile;

	mp->wall = mlx_xpm_file_to_image(ml.mlx, \
		"./images_xpm/wall.xpm", &width_tile, &height_tile);
	mp->collect = mlx_xpm_file_to_image(ml.mlx, \
		"./images_xpm/nizku75.xpm", &width_tile, &height_tile);
	mp->exit = mlx_xpm_file_to_image(ml.mlx, \
		"./images_xpm/nizku_box.xpm", &width_tile, &height_tile);
	mp->player = mlx_xpm_file_to_image(ml.mlx, \
		"./images_xpm/frontlook.xpm", &width_tile, &height_tile);
}

void	initialize(t_game *game, char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	game->mapy = malloc(sizeof(t_mapy));
	game->tanjiro = malloc(sizeof(t_player));
	read_the_map(game, fd);
	game->tanjiro->move = malloc(sizeof(char) * 3);
	ml.mlx = mlx_init();
	game->mapy->h_ntiles = 0;
	game->tanjiro->eaten_collect = 0;
}

int	check_parsing(t_game *game)
{
	if (!parsing_map(game))
	{
		printf("this map is invalid asat!\n");
		return (0);
	}
	link_pictures(game);
	while (mp->arr[mp->h_ntiles])
		mp->h_ntiles++;
	mp->v_ntiles = ft_strlen(mp->arr[0]);
	mp->height = mp->v_ntiles * 75;
	mp->width = mp->h_ntiles * 75;
	return (1);
}
