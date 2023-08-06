/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:53:01 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/06 19:30:28 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/cub3D.h"

void	init_game(t_game *game)
{
	game->mlx.mlx = mlx_init();
	init_textures(game);
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIDTH, HEIGHT, "cub3D");
	
}

void	init_textures(t_game *game)
{
	init_texture_fill(game, &game->txt.no.img);
	init_texture_fill(game, &game->txt.so.img);
	init_texture_fill(game, &game->txt.we.img);
	init_texture_fill(game, &game->txt.ea.img);
}

void	init_texture_fill(t_game *game, void **txt)
{
	char	*path;
	int		w;
	int		h;

	path = *txt;
	*txt = mlx_xpm_file_to_image(game->mlx.mlx, path, &w, &h);
	if (!*txt)
		printerror("Error while loading texture", NULL);
	free(path);
}
