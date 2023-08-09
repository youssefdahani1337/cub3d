/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:53:01 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 15:46:18 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/cub3D.h"

void	init_game(t_game *game)
{
	game->test->mlx_ptr = mlx_init();
	game->test->mlx_win = mlx_new_window(game->test->mlx_ptr,  WIDTH, HEIGHT, "cub3D");
	
	//init_textures(game);
//	myget_data_adrr(game, &game->screen);
	init_raycast(game);
	init_speed(game);
	//game->test->imag->ptr = mlx_new_image(game->test->mlx_ptr, WIDTH, WIDTH);
	//game->test->imag->addr = mlx_get_data_addr(game->test->mlx_ptr, &game->test->imag->bits_per_pixel,
		//&game->test->imag->line_length, &game->test->imag->endian);
	game->test->map = game->map.m;
}
void	init_raycast(t_game *game)
{
	char	d;
	
	d = game->p.v;
	if (d == 'E')
		game->test->theta = 0;
	else if (d == 'N')
		game->test->theta = 90;
	else if (d == 'W')
		game->test->theta = 180;
	else if (d == 'S')
		game->test->theta = 270;
	 game->test->py = (game->p.x * TILE_S) + (TILE_S / 2);
	 game->test->px = (game->p.y * TILE_S) + (TILE_S / 2);
	//game->ray.x = 98;
	//game->ray.y = 98;
	game->test->i =  0;
	game->test->j =  1;
	game->test->ox = 0;
	game->ray.dist_p = (WIDTH / 2) / tan(ft_rad(FOV / 2));
	game->test->r_len = game->map.r_len;
	game->test->c_len = game->map.c_len;
}

void	init_speed(t_game *game)
{
	game->test->m_r = 0;
	game->test->m_l = 0;
	game->test->m_u = 0;
	game->test->m_d = 0;
	game->test->rot_rhit = 0;
	game->test->rot_left = 0;
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
