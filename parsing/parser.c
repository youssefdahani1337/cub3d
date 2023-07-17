/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:32:55 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/17 07:54:37 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

t_game	*parsing(char *arg)
{
	t_game	*game;
	int		fd;

	fd = open_file(arg);
	game = init_game();
	check_firsts_infos(fd, game);
	return (NULL);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = ft_malloc(1, sizeof(t_game));
	game->txt_ea = NULL;
	game->txt_no = NULL;
	game->txt_so = NULL;
	game->txt_we = NULL;
	game->c_color[0] = -1;
	game->c_color[1] = -1;
	game->c_color[2] = -1;
	game->f_color[0] = -1;
	game->f_color[1] = -1;
	game->f_color[2] = -1;
	return (game);
}
