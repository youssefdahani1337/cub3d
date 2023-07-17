/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:21:37 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/17 08:37:50 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCTS_H
# define STRUCTS_H
# define SPACE ' '

typedef struct s_game
{
	char			**map;
	char			*txt_no;
	char			*txt_so;
	char			*txt_we;
	char			*txt_ea;
	int				f_color[3];
	int				c_color[3];
}	t_game;

#endif