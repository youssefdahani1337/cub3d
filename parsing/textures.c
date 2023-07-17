/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:50:41 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/17 07:36:46 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	add_textures(t_game *game, t_lexer *lexer)
{
	char	*str;
	char	*path;

	str = join_dir(lexer);
	if (lexer->c != SPACE)
		printerror("NO Sapce sparate texture path", lexer->src + lexer->i);
	skip_whitespace(lexer);
	if (!lexer->c)
		printerror("Path not found", NULL);
	path = ft_strdup(lexer->src + lexer->i);
	get_textures(game, str, path);
	free_lexer(lexer);
}

char	*join_dir(t_lexer *lexer)
{
	char	*str;

	str = join_char(NULL, lexer->c);
	lexer_iter(lexer);
	str = join_char(str, lexer->c);
	if (!lexer->c || !ft_strchr("OAE", lexer->c))
		printerror("Invalid texture ", str);
	return (str);
}

void	get_textures(t_game *game, char *type, char *path)
{
	if (ft_strncmp("NO", type, 2) == 0)
		set_path(&game->txt_no, path, type);
	else if (ft_strncmp("SO", type, 2) == 0)
		set_path(&game->txt_so, path, type);
	else if (ft_strncmp("WE", type, 2) == 0)
		set_path(&game->txt_we, path, type);
	else if (ft_strncmp("EA", type, 2) == 0)
		set_path(&game->txt_ea, path, type);
}

void	set_path(char **path, char *str, char *type)
{
	if (*path)
		printerror("texture already set for ", type);
	*path = str;
}
