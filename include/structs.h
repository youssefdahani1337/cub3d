/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:21:37 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/21 21:21:00 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define SPACE ' '
# define HEIGHT 600
# define WIDTH 800
# include <mlx.h>
# include <stdio.h>

typedef struct s_pos
{
	int		x;
	int		y;
	char	v;
}	t_pos;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	t_pos			p; //position of player
	void			*txt_no;
	void			*txt_so;
	void			*txt_we;
	void			*txt_ea;
	int				f_color;
	int				c_color;
	size_t			r_len;
	size_t			c_len;
}	t_game;

#endif