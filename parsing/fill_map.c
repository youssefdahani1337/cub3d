/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:47:32 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/21 11:35:17 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	alloc_map(t_game *game, t_list *list)
{
	size_t	i;

	i = -1;
	game->c_len = get_max(list);
	game->r_len = ft_lstsize(list);
	game->map = ft_malloc(game->r_len + 1, sizeof(char *));
	while (++i < game->r_len)
	{
		game->map[i] = ft_malloc(game->c_len + 1, sizeof(char));
		ft_memset(game->map[i], ' ', game->c_len);
		game->map[i][game->c_len] = '\0';
	}
	game->map[i] = NULL;
}

t_list	*fill_list(int fd)
{
	char	*line;
	t_list	*list;

	list = NULL;
	line = get_next_line(fd);
	if (!line)
		printerror(" NO  map", NULL);
	while (line)
	{
		ft_lstadd_back(&list, ft_lstnew(substr_line(line)));
		line = get_next_line(fd);
	}
	ft_lstclear(&list, free);
	return (list);
}

void	fill_map(t_game *game, t_list *list)
{
	int		i;
	int		j;
	char	*s;

	j = 0;
	while (list)
	{
		i = -1;
		s = list->content;
		if (*s)
		{
			while (s[++i])
				game->map[j][i] = s[i];
		}
		list = list->next;
		j++;
	}
}
