/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:50:41 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/21 11:50:05 by yodahani         ###   ########.fr       */
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
	path = lexer->src + lexer->i;
	if (ft_strlen(path) <= 4)
		printerror("Invalid texture path", path);
	if (ft_strncmp(".xpm", path + ft_strlen(path) - 4, 4) != 0)
		printerror("Invalid texture extension", path);
	get_textures(game, str, path);
}

char	*join_dir(t_lexer *lexer)
{
	char	*str;

	str = join_char(NULL, lexer->c);
	lexer_iter(lexer);
	if (!lexer->c || !ft_strchr("OAE", lexer->c))
		printerror("Invalid texture ", NULL);
	str = join_char(str, lexer->c);
	lexer_iter(lexer);
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

void	set_path(void **texture, char *str, char *type)
{
	int	h;
	int	w;

	if (*texture)
		printerror("texture already set for ", type);
	*texture = mlx_xpm_file_to_image(str, str, &h, &w);
}
