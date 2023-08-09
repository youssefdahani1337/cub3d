/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:05:06 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 15:48:13 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/cub3D.h"

void  put_pixel_in_img(t_test *T, int x, int y,int color)
{
    char *add;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return ;
    add = T->imag->addr + (y * T->imag->line_length + x * (T->imag->bits_per_pixel / 8));
    *(int *)add = color;
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
    
    alpha = test->theta + 30;
    if (alpha >= 360)
        alpha = alpha - 360.0;
    while (k < WIDTH)
    {
        if (alpha < 0)
            alpha = alpha + 360.0;
        if (alpha >= 360.0)
            alpha =  alpha - 360.0;
        x_ray = 0;
        y_ray= 0;
        rx = ft_ray_x(test,alpha);
        ry = ft_ray_y(test,alpha);
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
        start = (HEIGHT - Height_wall) / 2;
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
                put_pixel_in_img(test, k, j,0x0B742B6);
            else if (alpha <= 90 && alpha > 0 && y_ray == 1)
                 put_pixel_in_img(test, k, j,0x4246B7);
            else if (alpha > 90 && alpha <= 180 && x_ray == 1)
                put_pixel_in_img(test, k, j,0xB742B6);
            else if (alpha > 90 && alpha <= 180 && y_ray == 1)
                put_pixel_in_img(test, k, j,0xACF709);
            else if (alpha > 180 && alpha <= 270 && x_ray == 1)
                put_pixel_in_img(test, k, j,0xB75242);
            else if (alpha > 180 && alpha <= 270 && y_ray == 1)
                put_pixel_in_img(test, k, j,0xACF709);
            else if (alpha > 270 && alpha <= 360 && x_ray == 1)
                put_pixel_in_img(test, k, j,0xB75242);
            else if (alpha > 270 && alpha <= 360 && y_ray == 1)
                put_pixel_in_img(test, k, j,0x4246B7);
            j++;
        }
        while(j < HEIGHT)
        {
            put_pixel_in_img(test, k, j,0xF39C12);
            j++;
        }
        k++;
        alpha -= 60.00 / WIDTH;
    }
    mlx_clear_window(test->mlx_ptr, test->mlx_win);
    mlx_put_image_to_window(test->mlx_ptr, test->mlx_win, 
    test->imag->ptr, 0, 0);
}
