/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhn <dhn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:37:36 by yodahani          #+#    #+#             */
/*   Updated: 2023/07/18 11:55:15 by dhn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	add_color(t_game *game, t_lexer *lexer)
{
	char	c;

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

void	set_color(int color[], t_lexer *lexer)
{
	int		i;
	int		j;
	char	*nb;

	i = -1;
	while (++i < 3 && lexer->c)
	{	
		nb = NULL;
		j = -1;
		while (!ft_strchr(",", lexer->c) && ft_isdigit(lexer->c) && ++j < 3)
		{
			nb = join_char(nb, lexer->c);
			lexer_iter(lexer);
		}
		if ((i < 2 && lexer->c != ',') || (i == 2 && lexer->c))
			printerror("Invalid color ", NULL);
		lexer_iter(lexer);
		get_color(color, nb, i);
		free(nb);
	}
	if (i != 3)
		printerror("Invalid color", NULL);
		printf("color: %d %d %d\n", color[0], color[1], color[2]);
}

void	get_color(int color[], char *nb, int i)
{
	if (color[i] != -1)
		printerror("color already set", NULL);
	color[i] = ft_atoi(nb);
	if (color[i] > 255 || (int)color[i] < 0)
		printerror("RGB color must be between 0 and 255", NULL);
}
