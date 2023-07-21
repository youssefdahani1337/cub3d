/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:53:01 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/21 11:56:24 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/cub3D.h"

t_game	*init_game(void)
{
	
}

t_game	*init_attr(vod)
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
