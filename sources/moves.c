/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:27:49 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 11:18:00 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int is_can_move(t_game *game)
{
    double x ;
    double y ;

	x = ft_ray_x(game, game->ray.theta);
	y = ft_ray_y(game, game->ray.theta);
	if (x > y)
        x = y;
    if (x - 5 > 20)
        return (5);
    else if (x > 20)
        return (x - 20);
    return (-1);
}

void  mov_up(t_game *game)
{
    float	t_rad;
    int		move;
	float	x;
	float	y;

	// diffrence between up and down 
	move = is_can_move(game);
    if (move == -1)
        return ;
    x = game->ray.x;
	y = game->ray.y;
	t_rad = ft_rad(game->ray.theta);
	x += cos(t_rad) * SPEED_MOVE;
	y -= sin(t_rad) * SPEED_MOVE;
     if (game->map.m[(int)y/TILE_S][(int)x/TILE_S] != '1')
    {
        game->ray.i = 1;
        game->ray.x = x;
        game->ray.y = y;
    }
}

void mov_down(t_game *game)
{
    float	t_rad;
	float	x;
	float	y;


    x = game->ray.x;
	y = game->ray.y;
	t_rad = ft_rad(game->ray.theta);
	x -= cos(t_rad) * SPEED_MOVE;
	y += sin(t_rad) * SPEED_MOVE;
    if (game->map.m[(int) y /TILE_S][(int) x / TILE_S] != '1')
    {
        game->ray.i = 1;
        game->ray.x = x;
        game->ray.y = y;
    }
}

void	mov_side(t_game *game, char dir)
{
	float t_rad;
	float	x;
	float	y;
    
	t_rad = 0.0;
	x = game->ray.x;
	y = game->ray.y;
	if (dir == LEFT)
		t_rad =ft_rad(game->ray.theta + 90);
	else
		t_rad =ft_rad(game->ray.theta  - 90);
	x += cos(t_rad) * SPEED_ROT;
	y -= sin(t_rad) * SPEED_ROT;
    if (game->map.m[(int)y/TILE_S][(int)x/TILE_S] != '1')
    {
    	game->ray.i = 1;
        game->ray.x = x;
        game->ray.y = y;
    }
}

