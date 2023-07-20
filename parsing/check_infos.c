/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:14:18 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/18 14:32:03 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	check_firsts_infos(int fd, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	if (!line)
		printerror("Empty Map!!", NULL);
	i = 0;
	while (line && i < 5)
	{
		if (line && *line == '\n')
		{
			free(line);
			continue ;
		}	
		add_infos(game, line);
		i ++;
	}
}

void	add_infos(t_game *game, char *line)
{
	t_lexer	*lexer;

	lexer = init_lexer(line);
	skip_whitespace(lexer);
	if (lexer->c != '\0')
		printerror("Firsts information", "line with multiple space");
	if (ft_strchr("NSWE", lexer->c))
		add_textures(game, lexer);
	else if (ft_strchr("FC", lexer->c))
		add_color(game, line);
	else
		printerror("Invalid firsts information", NULL);
	free(line);
}
