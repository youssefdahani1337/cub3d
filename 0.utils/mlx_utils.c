/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:01:47 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/08 13:38:47 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	myget_data_adrr(t_game *game, t_data_txt *t)
{
	t->img = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	t->addr = mlx_get_data_addr(t->img, &t->bpp, &t->line_len, &t->endian);
}

void  put_pixel_in_img(t_game *game, int x, int y,int color)
{
    char *add;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return ;
    add = game->screen.addr + (y * game->screen.line_len + x * (game->screen.bpp / 8));
    *(int *)add = color;
}