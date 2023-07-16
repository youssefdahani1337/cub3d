/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:36:01 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/16 11:50:37 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	check_map_name(char *arg)
{
	if (ft_strlen(arg) <= 4)
		printerror("Invalid name map", arg);
	arg = arg + (ft_strlen(arg) - 4);
	if (ft_strncmp(".cub", arg, 4) != 0)
		printerror("Inavlid file extension", arg);
}