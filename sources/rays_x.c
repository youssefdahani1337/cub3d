/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:06:09 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 16:17:28 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int check_to_berk_posix(t_test *info, float x1, float y)
{
	float x;
	int	i;
	int	j;

	x = x1 + info->px;
	i = (int)((info->py - floor(y) - 1)/ 64);
	j = (int)(x/64);
	if (j >= info->c_len || j < 0 || i < 0 ||  i >= info->r_len)
		return (0);
	if (info->map[i][j] == '1')
		return (0) ;
	else
		info->ox++;
	return (1);
}

int check_to_berk_nigax(t_test *info, float x1, float y)
{
	float x;
	int i;
	int	j;

	x = info->px - x1;
	i =(int)((info->py + floor(y) + 1)/ 64);
	j = (int)((x)/64);
	if (j >= info->c_len || j < 0 || i < 0 ||  i >= info->r_len)
		return (0);
	if (info->map[i][j] == '1')
		return (0);
	else
		info->ox++;
	return (1);
}

double ft_ray_x(t_test *info,float thet)
{
    double r;
	float x1;
    float y;

    info->ox = 1;
    while (1)
    {
        if (sin(thet * M_PI/180) >= 0)
        {
            y = info->py - (floor((info->py / 64) - info->ox + 1) * 64);
            x1 = y / tan(thet * M_PI/180);
			if (check_to_berk_posix(info, x1, y) == 0)
				break ;
        }
        else
        {
            y = (floor((info->py / 64) + info->ox) * 64) - info->py;
            x1 = y / tan((thet - 180) * M_PI/180);
			if (check_to_berk_nigax(info, x1, y) == 0)
				break;
        }
    }
    r =sqrt(pow(x1,2) + pow(y,2));
    if (r < 0)
	{
        return (2147483647);
    }
    return (r);
}
