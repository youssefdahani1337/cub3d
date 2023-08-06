/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:49:14 by yakhay            #+#    #+#             */
/*   Updated: 2023/08/04 15:02:47 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float theta = 90;
void  put_pixel_in_img(t_test *T, int x, int y)
{
    char *add;
    add = T->imag->addr + (x * T->imag->line_length + y * (T->imag->bits_per_pixel / 8));
    *(int *)add = 0xFF5733;
}

void put_pixel_in_case(t_test *T, int x,int y)
{
    int i = 1;
    int j = 1;
    while (i < 64 - 1)
    {
        j = 0;
        while (j < 64 - 1)
        {
            put_pixel_in_img(T, x * 64 + i, y * 64 + j);
            j++;
        }
        i++;
    }
}

void  mov_up(t_test *test)
{
    float t_rad;

    float x =test->px,y =test->py;
	t_rad = M_PI * theta / 180;
	x += cos(t_rad) * 3;
	y -= sin(t_rad) * 3;
     if (test->map[(int)y/64][(int)x/64] != '1')
    {
        test->i = 1;
        test->oy = 1;
        test->px = x;
        test->py = y;
    }

}
void mov_down(t_test *test)
{
    float t_rad;

    float x =test->px,y =test->py;
	t_rad = M_PI * theta/ 180;
	x -= cos(t_rad) * 3;
	y += sin(t_rad) * 3;
     if (test->map[(int)y/64][(int)x/64] != '1')
    {
        test->i = 1;
        test->oy = 1;
        test->px = x;
        test->py = y;
    }

}
void mov_rhit(t_test *test)
{
    float t_rad;

    float x =test->px,y =test->py;
	t_rad = M_PI * (theta - 90) / 180;
	x += cos(t_rad) * 3;
	y -= sin(t_rad) * 3;
    if (test->map[(int)y/64][(int)x/64] != '1')
    {
        test->i = 1;
        test->oy = 1;
        test->px = x;
        test->py = y;
    }
}
void mov_left(t_test *test)
{
    float t_rad;
    float x =test->px,y =test->py;
	t_rad = M_PI * (theta + 90) / 180;
	x += cos(t_rad) * 3;
	y -= sin(t_rad) * 3;
    if (test->map[(int)y/64][(int)x/64] != '1')
    {
        test->i = 1;
        test->oy = 1;
        test->px = x;
        test->py = y;
    }
}
void f1(t_test *T)
{
    int i = -1,j;
    while (T->map[++i])
    {
        j = -1;
        while (T->map[i][++j])
        {
            if (T->map[i][j] == '0')
                put_pixel_in_case(T, i,j);
        }
    }
    mlx_put_image_to_window(T->mlx_ptr, T->mlx_win, T->imag->ptr, 0, 0);
}

void f2(t_test *T,int c)
{
    int i = -1,j;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
        {
            if (c == 0)
                mlx_pixel_put(T->mlx_ptr, T->mlx_win, T->px + j ,T->py  + i, 0xF5F5DC);
        }
    }

}


int key_hook(int key, t_test *test)
{
    if (key == 2)
		test->rot_rhit = 1;
	if (key == 0)
		test->rot_left = 1;
	if (key == 126)
		test->m_u = 1;
	if (key == 125)
		test->m_d = 1;
	if (key == 124)
		test->m_r = 1;
	if (key == 123)
		test->m_l = 1;
	if (key == 53)
		exit(0);
	return (0);

}

int key_relesse(int key, t_test *test)
{
    if (key == 2)
		test->rot_rhit = 0;
	if (key == 0)
		test->rot_left = 0;
	if (key == 126)
		test->m_u = 0;
	if (key == 125)
		test->m_d = 0;
	if (key == 124)
		test->m_r = 0;
	if (key == 123)
		test->m_l = 0;
    return (0);
}
double ft_x(t_test *info,float thet)
{
    double r;
    float x, x1;
    float y;
    info->ox = 1;
    while (1)
    {
        if (sin(thet * M_PI/180) >= 0)
        {
            y = info->py - (floor((info->py / 64) - info->ox + 1) * 64);
            x1 = y / tan(thet * M_PI/180);
            x = x1 + info->px;
            if ((int)(x/64) > 10)
                break;
            if ((int)(x/64) >= 0 &&  info->map[(int)((info->py - floor(y) - 1)/ 64)][(int)(x/64)] == '1')
                break ;
            else
            {
                info->ox++;
                if (info->ox > 20)
                    break ;
            }
        }
        else
        {
            y = (floor((info->py / 64) + info->ox) * 64) - info->py;
            x1 = y / tan((thet - 180) * M_PI/180);
            x = info->px - x1;
            if ((int)((x)/64) > 10)
                break;
            if ((int)((x)/64) >= 0 && info->map[(int)((info->py + floor(y) + 1)/ 64)][(int)((x)/64)] == '1')
                break ;
                else
            {
                info->ox++;
                if (info->ox > 20)
                    break ;

            }
        }
    }
    r =sqrt(pow(x1,2) + pow(y,2));
    if (r < 0){
        return (2147483647);
    }
    return (r);
}

double ft_y(t_test *info, float thet)
{
    double r;
    float y ,y1;
    float x;
    info->j = 1;
    while (1)
    {
       if (cos(thet * M_PI/180) >= 0)
       {
            x = floor(((info->px/64) + info->j)) * 64 - info->px;
            y1 = x * tan(thet * M_PI/180);
            y = info->py - y1;
            if ((int)(y/64) > 7)
                break;
            if ((int)(y/64) >= 0 && info->map[(int)(y/64)][(int)(info->px + x + 1)/64] == '1')
                break ;
            else
            {
                info->j++;
                if (info->j > 20)
                    break ;
            }
       }
       else
       {
            x = info->px - floor((info->px/64) - info->j  + 1) * 64;
            y1 = x * tan((180 - thet) * M_PI/180);
            y = info->py - y1;
            if ((int)(y/64) > 7)
                break;
            if ((int)(y/64) >= 0 && info->map[(int)(y/64)][(int)((info->px - x)/64 -1)] == '1')
                break ;
            else
            {
                info->j++;
                if (info->j > 20)
                    break ;
            }
       }
    }
    r = sqrt(pow(x,2) + pow(y1,2));
    if (r < 0)
        r = 2147483647;
    return (r);
}

void ft_r(t_test *test)
{
    float ry,rx,r,x,y;
    float i = theta - 30;
    while (i < theta + 30)
    {
        rx = ft_x(test,i);
        ry = ft_y(test,i);
        if (rx > ry)
          r = ry;
        else
            r = rx;
        x = test->px + 1, y = test->py;
        float t_rad = M_PI * i / 180;
        for (int j = 0; j < r ; j++)
        {
            mlx_pixel_put(test->mlx_ptr, test->mlx_win, x ,y , 0xF5F5DC);
            x += cos(t_rad);
            y -= sin(t_rad);
        }
        i += 60.0/640;
    }
//    printf("--ry %f\n",ry);
//     printf("---rx %f\n",rx);
    // printf("---r %f\n",r);
}
int motion(t_test *test)
{
    if (test->m_r == 1)
        mov_rhit(test);
    if (test->m_l == 1)
        mov_left(test);
    if (test->m_u == 1)
        mov_up(test);
    if (test-> m_d == 1)
        mov_down(test);
    if (test->rot_left == 1)
    {
        test->i = 1;
        test->oy = 1;
		theta += 1;
    }
	if (test->rot_rhit == 1)
    {
        test->i = 1;
        test->oy = 1;
        theta -= 1;
    }
    f1(test);
    f2(test,0);
        ft_r(test);
    return (0);
}


int main(int ac, char **av)
{
    char *line;
    char *map_line;
    t_test *T;
    T = malloc(sizeof(t_test));
     T->imag = malloc(sizeof(t_img));
    (void)ac;
    int fd = open(av[1], O_RDWR);
    T->m_r = 0;
    T->m_l = 0;
    T->m_u = 0;
    T->m_d = 0;
    T->rot_rhit = 0;
	T->rot_left = 0;
    T->px = 98;
    T->py = 98;
    // T->theta_r = theta - 30;
    T->i = 0;
    T->j = 1;
    T->ox = 0;
    T->oy = 0;

    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        map_line = ft_strjoine(map_line,line);
        free(line);
    }
    T->map = ft_split(map_line,'\n');

    T->mlx_ptr = mlx_init();
    T->mlx_win = mlx_new_window(T->mlx_ptr, 640, 512, "test");
    T->imag->ptr = mlx_new_image(T->mlx_ptr, 640, 512);
	T->imag->addr = mlx_get_data_addr(T->imag->ptr, &T->imag->bits_per_pixel,
		&T->imag->line_length, &T->imag->endian);

    f1(T);
    f2(T,0);
    mlx_hook(T->mlx_win, 2, 0, key_hook, T);
    mlx_hook(T->mlx_win, 3, 0, key_relesse, T);
    mlx_loop_hook(T->mlx_ptr, motion, T);
    mlx_loop(T->mlx_ptr);
}
