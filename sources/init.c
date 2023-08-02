/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:53:01 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/21 21:45:55 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/cub3D.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	init_textures(game);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	mlx_hook(game->win, 17, 0, ft_cross, game);
	mlx_loop(game->mlx);
}

void	init_textures(t_game *game)
{
	init_texture_fill(game, &game->txt_no);
	init_texture_fill(game, &game->txt_so);
	init_texture_fill(game, &game->txt_we);
	init_texture_fill(game, &game->txt_ea);
}

void	init_texture_fill(t_game *game, void **txt)
{
	char	*path;
	int		w;
	int		h;

	path = *txt;
	*txt = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!*txt)
		printerror("Error while loading texture", NULL);
	free(path);
}
