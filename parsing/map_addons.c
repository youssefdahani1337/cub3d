/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_addons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:49:16 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/18 14:54:15 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

size_t	get_max(t_list *list)
{
	size_t	max;
	size_t	tmp;

	max = ft_strlen(list->content);
	while (list->next)
	{
		list = list->next;
		tmp = ft_strlen(list->content);
		if (tmp > max)
			max = tmp;
	}
	return (max);
}
