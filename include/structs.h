/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:21:37 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/06 20:03:14 by yodahani         ###   ########.fr       */
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

typedef struct set_color
{
	long						f;
	long						c;

}	t_color;


typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_data_txt
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_data_txt;

typedef struct s_texture
{
	t_data_txt					no;
	t_data_txt					so;
	t_data_txt					we;
	t_data_txt					ea;
	t_data_txt					s;
}	t_texture;

typedef struct map
{
	char						**m;
	size_t						r_len;
	size_t						c_len;
}	t_map;

typedef struct s_game
{
	t_mlx						mlx;
	t_color						color;
	t_pos						p; //position of player
	t_texture					txt;
	t_map						map;
}	t_game;

#endif