/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:05:19 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/21 21:44:43 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "parsing.h"

void	init_game(t_game *game);
void	init_textures(t_game *game);
void	init_texture_fill(t_game *game, void **txt);
int		ft_cross(t_game *game);
#endif