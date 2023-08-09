/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:45:58 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/08 18:29:42 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "utils.h"

void	ft_raycasting(t_game *game);
double	ft_ray_x(t_game *game, float thet);
double 	ft_ray_y(t_game *game, float thet);
void	draw_cell(t_game *game, int cell, int *start);
void	draw_walls(t_game *game, int cell, int *start);
void	draw_floor(t_game *game, int cell, int start);
void	best_ray(t_game *game);
void	calc_dst(t_game *game);
#endif