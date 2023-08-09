/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:05:19 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/08 13:30:48 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "parsing.h"
# include "raycasting.h"

void	init_game(t_game *game);
void	init_textures(t_game *game);
void	init_raycast(t_game *game);
void	init_speed(t_game *game);

void	init_texture_fill(t_game *game, void **txt);


//hook
void	hook_mlx(t_game *game);
int		presse_key(int key, t_game *game);
int		relesse_key(int key, t_game *game);
int		motion(t_game *game);
void	mov_side(t_game *game, char dir);
int		is_can_move(t_game *game);
void	mov_up(t_game *game);
void	mov_down(t_game *game);
int		ft_cross(t_game *game);
int		ft_key(int key, t_game *game);
void	ft_echap(t_game *game);
int		presse_key(int key, t_game *game);
#endif