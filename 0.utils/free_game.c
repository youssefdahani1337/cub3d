/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:32:53 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/21 19:32:34 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
	if (game->txt_no)
		free(game->txt_no);
	if (game->txt_so)
		free(game->txt_so);
	if (game->txt_we)
		free(game->txt_we);
	if (game->txt_ea)
		free(game->txt_ea);
	if (game->txt_so)
		free(game->txt_so);
	if (game->mlx)
		free(game->mlx);
	if (game->win)
		free(game->win);
	free(game);
}
