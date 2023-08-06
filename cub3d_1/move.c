/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:20:01 by yakhay            #+#    #+#             */
/*   Updated: 2023/08/04 11:34:56 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void  mov_up(t_test *test)
{
    float t_rad;

    float x =test->px,y =test->py;
	t_rad = M_PI * test->theta / 180;
	x += cos(t_rad) * 10;
	y -= sin(t_rad) * 10;
     if (test->map[(int)y/64][(int)x/64] != '1')
    {
        test->i = 1;
        test->px = x;
        test->py = y;
    }

}
void mov_down(t_test *test)
{
    float t_rad;
    float x =test->px,y =test->py;
	t_rad = M_PI * test->theta/ 180;
	x -= cos(t_rad) * 10;
	y += sin(t_rad) * 10;
     if (test->map[(int)y/64][(int)x/64] != '1')
    {
        test->i = 1;
        test->px = x;
        test->py = y;
    }

}
void mov_rhit(t_test *test)
{
    float t_rad;

    float x =test->px,y =test->py;
	t_rad = M_PI * (test->theta - 90) / 180;
	x += cos(t_rad) * 10;
	y -= sin(t_rad) * 10;
    if (test->map[(int)y/64][(int)x/64] != '1')
    {
        test->i = 1;
        test->px = x;
        test->py = y;
    }
}
void mov_left(t_test *test)
{
    float t_rad;
    float x =test->px ,y =test->py;
	t_rad = M_PI * (test->theta + 90) / 180;
	x += cos(t_rad) * 10;
	y -= sin(t_rad) * 10;
    if (test->map[(int)y/64][(int)x/64] != '1')
    {
        test->i = 1;
        test->px = x;
        test->py = y;
    }
}
