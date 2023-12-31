/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:07:32 by yakhay            #+#    #+#             */
/*   Updated: 2023/01/16 21:07:12 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include<stdlib.h>
# include<unistd.h>

size_t		ft_strlen(const char *s);
char		*ft_itoa(int n);
void		ft_putstr(char *s, int c);
char		*ft_strdup(const char *src);
void		ft_bzero(void *s, size_t n);
long long	ft_atoi(const char *str);
void		ft_putnbr_fd(int nb, int fd);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
#endif
