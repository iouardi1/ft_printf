/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_exit_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:11:30 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/14 16:29:10 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_bonus(t_game *game)
{
	int		i;

	i = 0;
	while (game->mapy->arr[i])
	{
		free(game->mapy->arr[i]);
		i++;
	}
}

void	free_imgs_bonus(t_game *game)
{
	free(game->mapy->wall);
	free(game->mapy->collect);
	free(game->mapy->exit);
	free(game->mapy->player);
}

void	free_struct_bonus(t_game *game)
{
	free(game->mapy);
	free(game->tanjiro);
	free(game->tanjiro->move);
}

void	free_n_exit_bonus(t_game *game)
{
	free_map_bonus(game);
	free_imgs_bonus(game);
	free_struct_bonus(game);
	free(game);
	// (void)game;
	exit(0);
}