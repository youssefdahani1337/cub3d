/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:49:14 by yakhay            #+#    #+#             */
/*   Updated: 2023/08/05 11:32:52 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void  put_pixel_in_img(t_test *T, int x, int y,int color)
{
    char *add;

    if (x < 0 || x >= width || y < 0 || y >= height)
        return ;
    add = T->imag->addr + (y * T->imag->line_length + x * (T->imag->bits_per_pixel / 8));
    *(int *)add = color;
}

// void put_pixel_in_case(t_test *T, int x,int y, unsigned int clor)
// {
//     int i = 1;
//     int j = 1;
//     while (i < 64 - 1)
//     {
//         j = 0;
//         while (j < 64 - 1)
//         {
//             put_pixel_in_img(T, x * 64 + i, y * 64 + j, clor);
//             j++;
//         }
//         i++;
//     }
// }


// void f1(t_test *T)
// {
//     int i = -1,j;
//     while (T->map[++i])
//     {
//         j = -1;
//         while (T->map[i][++j])
//         {
//             if (T->map[i][j] == '0')
//                 put_pixel_in_case(T, i,j);
//         }
//     }
//     mlx_put_image_to_window(T->mlx_ptr, T->mlx_win, T->imag->ptr, 0, 0);
// }

// void f2(t_test *T,int c)
// {
//     int i = -1,j;
//     while (++i < 4)
//     {
//         j = -1;
//         while (++j < 4)
//         {
//             if (c == 0)
//                 mlx_pixel_put(T->mlx_ptr, T->mlx_win, T->px + j ,T->py  + i, 0xF5F5DC);
//         }
//     }

// }




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

void ft_ray(t_test *test)
{
    double r;
    float ry,rx;
    float Height_wall;
    int start;
    int j = 0;
    float alpha;;
    int k = 0;
    int x_ray,y_ray;
    float v_ray;
    alpha = test->theta + 30;
    v_ray = test->theta - 30;
    if (test->theta + 30 > 360)
        alpha = test->theta + 30 - 360.0;
    if (test->theta - 30 < 0)
        v_ray = 360.0 - test->theta - 30;
    while (k < width)
    {
        printf("%f\n",alpha);
        if (alpha < 0)
            alpha = 360.0 - alpha;
        if (alpha > 360.0)
            alpha =  alpha - 360.0;
        printf("%f===\n",test->theta);
        x_ray = 0;
        y_ray= 0;
        rx = ft_x(test,alpha);
        ry = ft_y(test,alpha);
        if (rx > ry)
        {
          r = ry;
          y_ray = 1;
        }
        else
        {
            r = rx;
            x_ray = 1;
        }
        r = cos((alpha - test->theta) * M_PI/180) * r;
        Height_wall = (64 / r) * 600;
        start = (height - Height_wall) / 2;
        if (start < 0)
            start = 0;
        j = 0;
        while (j < start)
        {
            put_pixel_in_img(test, k, j,0x09DAF7);
            j++;
        }
        while(j < start + Height_wall)
        {
            if (alpha <= 90 && alpha > 0 && x_ray == 1)
                put_pixel_in_img(test, k, j,0x0124);
            else if (alpha <= 90 && alpha > 0 && y_ray == 1)
                 put_pixel_in_img(test, k, j,0x000);
            else if (alpha > 90 && alpha <= 180 && x_ray == 1)
                put_pixel_in_img(test, k, j,0x0124);
            else if (alpha > 90 && alpha <= 180 && y_ray == 1)
                put_pixel_in_img(test, k, j,0xACF709);
            else if (alpha > 180 && alpha <= 270 && x_ray == 1)
                put_pixel_in_img(test, k, j,0xB75242);
            else if (alpha > 180 && alpha <= 270 && y_ray == 1)
                put_pixel_in_img(test, k, j,0xACF709);
            else if (alpha > 270 && alpha <= 360 && x_ray == 1)
                put_pixel_in_img(test, k, j,0xB75242);
            else if (alpha > 270 && alpha <= 360 && y_ray == 1)
                put_pixel_in_img(test, k, j,0x000);
            j++;
        }
        while(j < height)
        {
            put_pixel_in_img(test, k, j,0xF39C12);
            j++;
        }
        k++;
        alpha -= 60.00 / width;
    }
    mlx_put_image_to_window(test->mlx_ptr, test->mlx_win, test->imag->ptr, 0, 0);
}

int key_hook(int key, t_test *test)
{
     if (key == 124)
     {
		test->theta -= 10;
        if (test->theta < 0)
        test->theta = 360 -test->theta;
     }
	if (key == 123)
    {
		test->theta += 10;
        if (test->theta > 360)
        test->theta = test->theta - 360;
    }
	if (key == 13)
		mov_up(test);
	if (key == 1)
		mov_down(test);
	if (key == 2)
		mov_rhit(test);
	if (key == 0)
		mov_left(test);
	if (key == 53)
		exit(0);
    mlx_clear_window(test->mlx_ptr, test->mlx_win);
    ft_ray(test);
	return (0);

}

// int key_relesse(int key, t_test *test)
// {
//     if (key == 2)
// 		test->theta -= 8;
// 	if (key == 0)
// 		test->theta += 8;
// 	if (key == 126)
// 		mov_up(test);
// 	if (key == 125)
// 		mov_down(test);
// 	if (key == 124)
// 		mov_rhit(test);
// 	if (key == 123)
// 		mov_left(test);
//         ft_ray(test);
//     return (0);
// }

// int motion(t_test *test)
// {
//     ft_ray(test);
//     if (test->new_move == 1)
//         ft_ray(test);
//     test->new_move = 0;

//     return (0);
// }
int main(int ac, char **av)
{
    char *line;
    char *map_line;
    t_test *T;
    T = malloc(sizeof(t_test));
     T->imag = malloc(sizeof(t_img));
    (void)ac;
    int fd = open(av[1], O_RDWR);
    T->theta = 270;
    // T->m_r = 0;
    // T->m_l = 0;
    // T->m_u = 0;
    // T->m_d = 0;
    // T->rot_rhit = 0;
	// T->rot_left = 0;
    T->px = 98;
    T->py = 98;
    T->i = 0;
    T->j = 1;
    T->ox = 0;
    // T->new_move = 0;
    width = 800;
    height = 600;
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
    T->mlx_win = mlx_new_window(T->mlx_ptr, width, height, "CUB3D");
    T->imag->ptr = mlx_new_image(T->mlx_ptr, width, height);
	T->imag->addr = mlx_get_data_addr(T->imag->ptr, &T->imag->bits_per_pixel,
		&T->imag->line_length, &T->imag->endian);
    ft_ray(T);
    mlx_hook(T->mlx_win, 2, 0, key_hook, T);
    //printf("jfdn\n");
    //ft_ray(T);
    //mlx_hook(T->mlx_win, 3, 0, key_relesse, T);
    //mlx_loop_hook(T->mlx_ptr, motion, T);
    mlx_loop(T->mlx_ptr);
}