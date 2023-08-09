/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:47:53 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 11:07:30 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

int check_to_berk_posix(t_game *game, float x1, float y)
{
	float x;
	int i;
	int j;
	
	x = x1 + game->ray.x;
	i = (game->ray.y - floor(y) - 1) /  TILE_S;
	j = x / TILE_S;
	if (i < 0 || j < 0 || (size_t)(i) >= game->map.r_len || (size_t)(j) >= game->map.c_len)
		return (0);
	if (game->map.m[i][j] == '1')
		return (0) ;
	else
		game->ray.ox ++;
	return (1);
}

int check_to_berk_nigax(t_game *game, float x1, float y)
{
	float x;
	int i;
	int j;
	
	//why 15 ??
	x = game->ray.x - x1;
	printf("x = %f\n", x);
	i = ((game->ray.y + floor(y) + 1) / TILE_S);
	j = ((x) / TILE_S);
	if (i < 0 || j < 0 || (size_t)(i) >= game->map.r_len || (size_t)(j) >= game->map.c_len)
		return (0);
	if (game->map.m[i][j] == '1')
		return (0);
	else
		game->ray.ox ++;
	//scanf("%d", &i);
	return (1);
}

double ft_ray_x(t_game *game, float thet)
{
	double r;
	float x1;
	float y;

	game->ray.ox = 1;
	printf("thet = %f\n", game->ray.theta);
	while (1)
	{
		if (sin(ft_rad(thet)) >= 0)
		{
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>%f ray-> y : \n", game->ray.y);
			y =game->ray.y - (floor((game->ray.y / TILE_S) - game->ray.ox + 1) * TILE_S);
			x1 = y / tan(ft_rad(thet));
			printf("%f ray->y2 : \n", game->ray.y);
			if (check_to_berk_posix(game, x1, y) == 0)
				break;
		}
		else
		{
			y = (floor((game->ray.y / TILE_S) + game->ray.ox) * TILE_S) - game->ray.y;
			x1 = y / tan(ft_rad(thet - 180));
			printf("|>>>>>>>>>>>>>>>>>>>>>>>>>>>>%f Y \n",y);
			printf("|>>>>>>>>>>>>>>>>>>>>>>>>>>>>%f ray-> y : \n", game->ray.y);
				if (check_to_berk_nigax(game, x1, y) == 0)
				break;
		}
	}
	r = sqrt(pow(x1, 2) + pow(y, 2));
	printf("Y = %f\n", y);
	printf("X = %f\n", x1);
	//scanf("%f", &x1);
	if (r < 0)
		return (INT32_MAX);
	return (r);
}
