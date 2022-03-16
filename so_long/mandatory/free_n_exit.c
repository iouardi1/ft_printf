/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:11:30 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/16 16:40:30 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int		i;

	i = 0;
	while (game->mapy->arr[i])
	{
		free(game->mapy->arr[i]);
		i++;
	}
	free(game->mapy->arr[i]);
	free(game->mapy->arr);
}

void	free_imgs(t_game *game)
{
	if (game->mapy->wall)
	{
		// game->mapy->wall = NULL;
		free(NULL);
	}
	if (game->mapy->collect)
	{
		// game->mapy->collect = NULL;
		free(NULL);
	}
	if (game->mapy->exit)
	{
		// game->mapy->exit = NULL;
		free(NULL);
	}
	if (game->mapy->player)
	{
		// game->mapy->player = NULL;
		free(NULL);
	}
}

void	free_struct(t_game *game)
{
	if (game->mapy)
		free(game->mapy);
	if (game->tanjiro)
		free(game->tanjiro);
	if (game->tanjiro->move)
		free(game->tanjiro->move);
}

void	free_n_exit(t_game *game)
{
	(void)game;
	// free_map(game);
	// free_imgs(game);
	// free_struct(game);
	// free(game);
	system ("leaks so_long");
	exit(0);
}