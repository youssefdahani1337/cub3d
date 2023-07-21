/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:32:55 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/21 11:52:46 by yodahani         ###   ########.fr       */
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
	parse_map(fd, game);
	//print_infos(game);
	return (NULL);
}


