/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:37:36 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/17 10:29:11 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	add_color(t_game *game, char *line)
{
	char	c;
	t_lexer	*lexer;

	lexer = init_lexer(line);
	c = lexer->c;
	lexer_iter(lexer);
	if (lexer->c != ' ')
		printerror("No space sparate color", NULL);
	skip_whitespace(lexer);
	if (!lexer->c)
		printerror("No color set", NULL);
	if (c == 'F')
		set_color(game->f_color, lexer);
	if (c == 'C')
		set_color(game->c_color, lexer);
}

void	set_color(int *color, t_lexer *lexer)
{
	int		i;
	int		j;
	char	*nb;

	nb = NULL;
	i = -1;
	while (lexer->c && ++i < 3)
	{	
		j = -1;
		while (!ft_strchr(",", lexer->c) && ++j < 3)
		{
			nb = join_char(nb, lexer->c);
			lexer_iter(lexer);
		}
		if ((i < 2 && lexer->c != ',') || (i == 2 && lexer->c))
			printerror("Invalid color ", NULL);
		get_color(color, nb, i);
	}
}

void	get_color(int *color, char *nb, int i)
{
	if (color[i] != -1)
		printerror("color already set", NULL);
	color[i] = ft_atoi(nb);
	if (color[i] > 255 || (int)color[i] < 0)
		printerror("RGB color must be between 0 and 255", NULL);
}
