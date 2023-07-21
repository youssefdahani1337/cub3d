/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:21:37 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/21 11:46:31 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define SPACE ' '

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
	char			**map;
	t_pos			p; //position of player
	void			*txt_no;
	void			*txt_so;
	void			*txt_we;
	void			*txt_ea;
	int				f_color[3];
	int				c_color[3];
	size_t			r_len;
	size_t			c_len;
}	t_game;

#endif