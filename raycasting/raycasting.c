/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:45:13 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 11:08:31 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	ft_raycasting(t_game *game)
{
	int		i;
	int		start;

	i = -1;
	game->ray.alpha = game->ray.theta + (FOV / 2);
	if (game->ray.alpha >= 360)
        game->ray.alpha = remainder(game->ray.alpha, 360.0);
	while (++i < WIDTH)
	{
		printf("ray->alpha = %f\n", game->ray.alpha);
		start = 0;
		best_ray(game);
		calc_dst(game);
		draw_cell(game, i, &start);
		draw_walls(game, i, &start);
		draw_floor(game, i, start);
		game->ray.alpha -= FOV / WIDTH;
		//print_infos(game);
	}
	mlx_clear_window(game->mlx.mlx, game->mlx.win);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->screen.img, 0, 0);
}

void	best_ray(t_game *game)
{

	if (game->ray.alpha < 0)
		game->ray.alpha = 360.0 + game->ray.alpha;
	if (game->ray.alpha >= 360.0)
		game->ray.alpha = game->ray.alpha - 360.0;
	game->ray.rx = ft_ray_x(game, game->ray.alpha);
	game->ray.ry = ft_ray_y(game, game->ray.alpha);
	printf("rx = %f, ry = %f\n", game->ray.rx, game->ray.ry);
	//scanf("%s", &game->ray.dir);
	if (game->ray.rx > game->ray.ry)
	{
		game->ray.dir = 'V';
		game->ray.r = game->ray.ry;
	}
	else
	{
		game->ray.dir = 'H';
		game->ray.r = game->ray.rx;
	}
}

void	calc_dst(t_game *game)
{
	game->ray.r *= cos(ft_rad(game->ray.alpha - game->ray.theta));
	game->ray.h_wall = (TILE_S / game->ray.r) * game->ray.dist_p;
	game->ray.start_wall = (HEIGHT - game->ray.h_wall) / 2;
	if (game->ray.start_wall < 0)
		game->ray.start_wall = 0;
	game->ray.end_wall = game->ray.start_wall + game->ray.h_wall;
}
