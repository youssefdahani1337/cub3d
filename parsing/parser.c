/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:32:55 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/21 21:31:38 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

t_game	*parsing(char *arg)
{
	int		fd;
	t_game	*game;

	fd = open_file(arg);
	game = init_attr();
	check_firsts_infos(fd, game);
	parse_map(fd, game);
	print_infos(game);
	return (game);
}

t_game	*init_attr(void)
{
	t_game	*game;

	game = ft_malloc(1, sizeof(t_game));
	game->txt_ea = NULL;
	game->txt_no = NULL;
	game->txt_so = NULL;
	game->txt_we = NULL;
	game->c_color = -1;
	game->f_color = -1;
	return (game);
}
