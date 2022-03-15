/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:12:13 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/14 18:43:11 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_the_map(t_game *game, int fd)
{
	char	*tab;
	char	*temp;
	char	*temp2;

	tab = get_next_line(fd);
	temp = NULL;
	while (tab)
	{
		temp2 = temp;
		temp = ft_strjoin(temp, tab);
		free (tab);
		free (temp2);
		tab = get_next_line(fd);
	}
	temp2 = temp;
	game->mapy->arr = ft_split(temp, '\n');
	free (temp2);
}
