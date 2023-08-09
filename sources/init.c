/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:53:01 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 11:14:18 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/cub3D.h"

void	init_game(t_game *game)
{
	game->mlx.mlx = mlx_init();
	init_textures(game);
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIDTH, HEIGHT, "cub3D");
	myget_data_adrr(game, &game->screen);
	init_raycast(game);
	init_speed(game);
}
void	init_raycast(t_game *game)
{
	char	d;
	
	d = game->p.v;
	if (d == 'E')
		game->ray.theta = 0;
	else if (d == 'N')
		game->ray.theta = 90;
	else if (d == 'W')
		game->ray.theta = 180;
	else if (d == 'S')
		game->ray.theta = 270;
	 game->ray.x = (game->p.x * TILE_S) + (TILE_S / 2);
	 game->ray.y = (game->p.y * TILE_S) + (TILE_S / 2);
	//game->ray.x = 98;
	//game->ray.y = 98;
	game->ray.i =  0;
	game->ray.j =  1;
	game->ray.ox = 0;
	game->ray.dist_p = (WIDTH / 2) / tan(ft_rad(FOV / 2));
}

void	init_speed(t_game *game)
{
	game->speed.m_r = 0;
	game->speed.m_l = 0;
	game->speed.m_u = 0;
	game->speed.m_d = 0;
	game->speed.rot_rhit = 0;
	game->speed.rot_left = 0;
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
