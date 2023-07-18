/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhn <dhn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:14:18 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/18 11:31:41 by dhn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	check_firsts_infos(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		printerror("Empty Map!!", NULL);
	line = substr_line(line);
	while (line)
	{
		if (*line == '\n')
		{
			free(line);
			continue ;
		}
		add_infos(game, line);
		line = get_next_line(fd);
		line = substr_line(line);
	}
}

void	add_infos(t_game *game, char *line)
{
	t_lexer	*lexer;

	lexer = init_lexer(line);
	skip_whitespace(lexer);
	if (lexer->c == '\0')
		printerror("Firsts information line with multiple space", lexer->src);
	if (ft_strchr("NSWE", lexer->c))
		add_textures(game, lexer);
	else if (ft_strchr("FC", lexer->c))
		add_color(game, lexer);
	else
		printerror("Invalid firsts information", NULL);
	free_lexer(lexer);
}
