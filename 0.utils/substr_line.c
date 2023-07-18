/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhn <dhn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:57:41 by dhn               #+#    #+#             */
/*   Updated: 2023/07/18 11:31:17 by dhn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

char	*substr_line(char *line)
{
    char    *str;
    int     i;

    i = 0;
    str = NULL;
    if (!line)
        return (NULL);
    while (line[i] && line[i] != '\n')
        str = join_char(str, line[i ++]);
    free(line);
    return (str);
}