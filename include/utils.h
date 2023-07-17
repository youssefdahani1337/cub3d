/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:13:14 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/16 17:10:35 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "structs.h"
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

void	printerror(const char *msg, const char *sp);
int		open_file(const char *arg);
void	*ft_malloc(size_t count, size_t size);
char	*join_char(char *str, char c);


#endif