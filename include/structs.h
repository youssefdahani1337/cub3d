/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:21:37 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/08 19:59:31 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define SPACE ' '
# define HEIGHT 600
# define WIDTH 800
# define TILE_S 64
# define RIGHT '-'
# define LEFT '+'
# define SPEED_MOVE 5
# define SPEED_ROT 5
# define FOV 60

# include <mlx.h>
# include <stdio.h>
#include <math.h>
typedef struct s_pos
{
	int		x;
	int		y;
	int		v;
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
}	t_texture;

typedef struct map
{
	char						**m;
	size_t						r_len;
	size_t						c_len;
}	t_map;

typedef struct s_speed
{
	int 	m_r;
	int 	m_l;
	int 	m_u;
	int 	m_d;
	int 	rot_rhit;
	int 	rot_left;
} t_speed;

typedef struct s_ray
{
    int 	i;
    int 	j;
    float 	theta;
    float 	x;
    float 	y;
	float 	alpha;
    int		ox;
	double	r;
	float	ry;
	float	rx;
	float	h_wall;
	float	dist_p;
	int		start_wall;
	int		end_wall;
	char	dir;
} t_ray;

typedef struct s_game
{
	t_mlx						mlx;
	t_pos						p;
	t_speed						speed;
	t_ray						ray;
	t_color						color;
	t_texture					txt;
	t_map						map;
	t_data_txt					screen;
	
}	t_game;

#endif