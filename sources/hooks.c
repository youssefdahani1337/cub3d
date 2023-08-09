/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:13:11 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 11:07:46 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	hook_mlx(t_game *game)
{
	mlx_hook(game->mlx.win, 17, 0, ft_cross, game);
	mlx_hook(game->mlx.win, 2, 0,presse_key, game);
	mlx_hook(game->mlx.win, 3, 0,relesse_key, game);
	mlx_loop_hook(game->mlx.mlx, motion, game);
}

int	presse_key(int key, t_game *game)
{
	if (key == 124)
		game->speed.rot_rhit = 1;
	if (key == 123)
		game->speed.rot_left = 1;
	if (key == 13)
		game->speed.m_u = 1;
	if (key == 1)
		game->speed.m_d = 1;
	if (key == 2)
		game->speed.m_r = 1;
	if (key == 0)
		game->speed.m_l = 1;
	if (key == 53)
		ft_echap(game);
	return (0);
}

int	relesse_key(int key, t_game *game)
{
	if (key == 124)
		game->speed.rot_rhit = 0;
	if (key == 123)
		game->speed.rot_left = 0;
	if (key == 13)
		game->speed.m_u = 0;
	if (key == 1)
		game->speed.m_d = 0;
	if (key == 2)
		game->speed.m_r = 0;
	if (key == 0)
		game->speed.m_l = 0;
	return (0);
}

int motion(t_game *game)
{
    if (game->speed.m_r)
	    mov_side(game, RIGHT);
    if (game->speed.m_l)
	    mov_side(game, LEFT);
    if (game->speed.m_u)
	    mov_up(game);
    if (game->speed.m_d)
	    mov_down(game);
    if (game->speed.rot_rhit)
    {
    	game->ray.theta -= 4;
        if (game->ray.theta < 0)
            game->ray.theta += 360.0;
    }
    if (game->speed.rot_left)
    {
		game->ray.theta += 4;
        if (game->ray.theta >= 360)
            game->ray.theta -= 360.0;
    }
	ft_raycasting(game);
	return (0);
}