/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:33:01 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/18 15:47:05 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	parse_map(int fd, t_game *game)
{
	t_list	*list;

	list = fill_list(fd);
	check_charmap(list);
	game->map = alloc_map(list);
	fill_map(game, list);
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
		ft_lstadd_back(&, ft_lstnew(sub_line(line)));
		line = get_next_line(fd);
	}
}

int	check_char(char *str)
{
	int	i;
	int	check;

	check = 0;
	i = -1;
	while (++i)
	{
		if (ft_strchr("10 ", str[i]))
			continue ;
		else if (ft_strchr("WENS", str[i]))
		{
			if (check)
				printerror("there is more than 1 palyer", NULL);
			check = 1;
		}
		else
			printerror("invalid character !!", NULL);
	}
}

void	check_charmap(t_list *list)
{
	while (list)
	{
		check_char(list->content);
		list = list->next;
	}
}

char	**alloc_map(t_list *list)
{
	char	**map;
	size_t	len;
	size_t	rows;
	size_t	i;

	i = -1;
	len = get_max(list);
	rows = ft_lstsize(list);
	map = ft_malloc(rows, sizeof(char *));
	while (++i < rows)
	{
		map[i] = ft_malloc(len + 1, sizeof(char));
		ft_memset(map[i], ' ', len);
		map[len] = '\0';
	}
	return (map);
}

void	fill_map(t_game *game, t_list *list)
{
	while (list)
	{
		if (*list->content)
		{
						
		}
		list = list->next;
	}
}