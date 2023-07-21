/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:34:52 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/21 11:48:21 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	print_map(char **map, int x, int y)
{
	int	i;
	int	j;

	system("clear");
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == x && j == y)
				printf("\033[0;31m%c\033[0m", map[i][j]);
			else
				printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_infos(t_game *game)
{
	int	j;

	j = 0;
	printf("Celling color: %d %d %d\n", game->c_color[0],
		game->c_color[1], game->c_color[2]);
	printf("Floor color: %d %d %d\n", game->f_color[0],
		game->f_color[1], game->f_color[2]);
	printf("EA[%p]\n", game->txt_ea);
	printf("NO[%p]\n", game->txt_no);
	printf("SO[%p]\n", game->txt_so);
	printf("WE[%p]\n", game->txt_we);
	print_map(game->map, -1, -1);
}
