/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soo_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:50:35 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/02 16:53:57 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	draw_map(t_mapy	map, void *color, void *mlx, void *mlx_win)
// {
// 	int		i;
// 	int		j;
// 	int		x;
// 	int		y;
	
// 	map->width_tile = 75;
// 	map->height_tile = 75;
// 	x = 0;
// 	y = 0;
// 	i = 0;
// 	while (map.arr[i][j])
// 	{
// 		if (map.arr[i][j] == '1')
// 		{
// 			color = mlx_xpm_file_to_image(mlx_win, "images_xpm/wall.xpm",  &map.width, &map.height);
// 			mlx_put_image_to_window(mlx, mlx_win, color, x, y);
// 		}
// 		else if (arr[i][j] == 'C')
// 		{
// 			color = mlx_xpm_file_to_image(mlx_win,"images_xpm/nizku75.xpm", &map.width, &map.height);
// 			mlx_put_image_to_window(mlx, mlx_win, color, x, y);
// 		}
// 		else if (arr[i][j] == 'P')
// 		{
// 			color = mlx_xpm_file_to_image(mlx_win, "images_xpm/frontlook_tanjiro75.xpm", &map.width, &map.height);
// 			mlx_put_image_to_window(mlx, mlx_win, color, x, y);
// 		}
// 		else if (arr[i][j] == 'E')
// 		{
// 			color = mlx_xpm_file_to_image(mlx_win, "images_xpm/nizku_box.xpm", &map.width, &map.height);
// 			mlx_put_image_to_window(mlx, mlx_win, color, x, y);
// 		}
// 		x += map->width_tile;
// 		j++;
// 	}
// 	y += map->height_tile;
// 	i++;
// }

#include "so_long.h"

int main()
{
	int		x = 1000;
	int		y = 1200;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	*relative_path = "images_xpm/nizku_box.xpm";
	int		img_width = 4542;
	int		img_height = 4542;
	void	*color;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, x, y, "here");
	img.img = mlx_new_image(mlx, 3000, 3000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img_width, &img_height);
	x = 10;
	y = 12;
	color = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, color, x, y);
	//mlx_loop_hook
	// mlx_destroy_image(mlx, img.img);
	
	x = 100;
	y = 120;

	img.img = mlx_new_image(mlx, 3000, 3000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img_width, &img_height);
	mlx_clear_window(mlx, mlx_win);
	mlx_put_image_to_window(mlx, mlx_win, color, x, y);
	mlx_loop(mlx);
}