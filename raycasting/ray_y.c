/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:47:32 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 11:07:13 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

int check_to_berk_posi(t_game *game, float y1, float x)
{
	float y;
	int	i;
	int	j;

	y = game->ray.y - y1;
	i = (int)(y / TILE_S);
	j = (int)(game->ray.x + x + 1) / TILE_S;
	if (i < 0 || j < 0)
		return (0);
	if ((size_t)i >= game->map.r_len || (size_t)j >= game->map.c_len)
		return (0);

	if (game->map.m[i][j] == '1')
		return (0);
	else
		game->ray.j ++;
	return (1);
}

int check_to_berk_niga(t_game *game, float y1, float x)
{
	float y;
	int	i;
	int	j;

	y = game->ray.y - y1;
	i = (int)(y / TILE_S);
	j = (int)((game->ray.x - x) / TILE_S - 1);
	printf("Y niga i = %d, j = %d\n", i, j);
	if (i < 0 || j < 0)
		return (0);
	if ((size_t)(i) >= game->map.r_len || (size_t)j >= game->map.c_len)
		return (0);
	if (game->map.m[i][j] == '1')
		return (0);
	else
		game->ray.j++;
	return (1);
}

double ft_ray_y(t_game *game, float thet)
{
    double r;
    float y1;
    float x;

    game->ray.j = 1;
    while (1)
    {
       if (cos(ft_rad(thet)) >= 0)
       {
            x = floor(((game->ray.x / TILE_S) + game->ray.j)) * TILE_S - game->ray.x;
            y1 = x * tan(ft_rad(thet));
			if (check_to_berk_posi(game, y1, x) == 0)
				break;
       }
       else
       {
            x = game->ray.x - floor((game->ray.x / TILE_S) - game->ray.j  + 1) * TILE_S;
            y1 = x * tan(ft_rad(180 - thet));
			if (check_to_berk_niga(game, y1, x) == 0)
				break;
       }
    }
    r = sqrt(pow(x,2) + pow(y1,2));
    if (r < 0)
        r = INT32_MAX;
    return (r);
}
