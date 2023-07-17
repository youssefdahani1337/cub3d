/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:57:28 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/16 17:10:09 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

char	*join_char(char *str, char c)
{
	char	*s;
	int		i;

	s = ft_malloc(ft_strlen(str) + 2, sizeof(char));
	i = -1;
	while (str && str[++i])
		s[i] = str[i];
	s[i] = c;
	s[i] = '\0';
	free(str);
	return (s);
}
