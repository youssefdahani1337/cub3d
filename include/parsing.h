/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:29:59 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/17 10:29:03 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "../include/utils.h"

typedef struct s_lexer
{
	char			*src;
	unsigned int	i;
	char			c;
	size_t			size;
}	t_lexer;

t_lexer	*init_lexer(char *line);
void	lexer_iter(t_lexer *lexer);
void	skip_whitespace(t_lexer *lexer);
void	free_lexer(t_lexer *lexer);

void	add_color(t_game *game, char *line);
void	set_color(int *color, t_lexer *lexer);
void	get_color(int *color, char *nb, int i);

void	add_textures(t_game *game, t_lexer *lexer);
char	*join_dir(t_lexer *lexer);
void	get_textures(t_game *game, char *type, char *path);
void	set_path(char **path, char *str, char *type);

t_game	*parsing(char *arg);
t_game	*init_game(void);
int		open_file(const char *arg);

void	check_firsts_infos(int fd, t_game *game);
void	add_infos(t_game *game, char *line);

#endif