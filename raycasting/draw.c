/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:26:16 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 10:52:14 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/raycasting.h"

void	draw_cell(t_game *game, int cell, int *start)
{
	while (*start < game->ray.start_wall)
		put_pixel_in_img(game,cell, (*start) ++, game->color.c);
}
void	draw_walls(t_game *game, int cell, int *start)
{
	while (*start < game->ray.end_wall)
		put_pixel_in_img(game, cell, (*start) ++, 10824234);
}
void	draw_floor(t_game *game, int cell, int start)
{
	while (start < HEIGHT)
		put_pixel_in_img(game, cell, start ++, game->color.f);
}

