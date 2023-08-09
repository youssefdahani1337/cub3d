/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:03:49 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 14:58:31 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/cub3D.h"

int	presse_key(int key, t_test *test)
{
	if (key == 124)
		test->rot_rhit = 1;
	if (key == 123)
		test->rot_left = 1;
	if (key == 13)
		test->m_u = 1;
	if (key == 1)
		test->m_d = 1;
	if (key == 2)
		test->m_r = 1;
	if (key == 0)
		test->m_l = 1;
	if (key == 53)
		exit(0);
	return (0);
}

int	relesse_key(int key, t_test *test)
{
	if (key == 124)
		test->rot_rhit = 0;
	if (key == 123)
		test->rot_left = 0;
	if (key == 13)
		test->m_u = 0;
	if (key == 1)
		test->m_d = 0;
	if (key == 2)
		test->m_r = 0;
	if (key == 0)
		test->m_l = 0;
	return (0);
}

int motion(t_test *test)
{
    if (test->m_r == 1)
	    mov_rhit(test);
    if (test->m_l == 1)
	    mov_left(test);
    if (test->m_u == 1)
	    mov_up(test);
    if (test->m_d == 1)
	    mov_down(test);
    if (test->rot_rhit == 1)
    {
    test->theta -= 4;
        if (test->theta < 0)
            test->theta = 360.0 + test->theta;
    }
    if (test->rot_left == 1)
    {
		test->theta += 4;
        if (test->theta >= 360)
            test->theta = test->theta - 360.0;
    }
   ft_ray(test);
	return (0);
}