/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 08:04:57 by yodahani          #+#    #+#             */
/*   Updated: 2023/08/09 16:01:37 by yodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int ac, char **av)
{
	t_game	*game;
	t_test	*test;

	test = malloc(sizeof(t_test));
	if (ac != 2)
		printerror("Enter just 1 argument", NULL);
	game = parsing(av[1]);
	game->test = test;
	init_game(game);
	test->mlx_ptr = mlx_init();
	test->mlx_win = mlx_new_window(game->test->mlx_ptr,  WIDTH, HEIGHT, "cub3D");
	test->imag = malloc(sizeof(t_img));
	test->imag->ptr = mlx_new_image(test->mlx_ptr, WIDTH, HEIGHT );
	test->imag->addr = mlx_get_data_addr(test->imag->ptr, &test->imag->bits_per_pixel,
		&test->imag->line_length, &test->imag->endian);
	//ft_ray(test);
	//mlx_hook(game->test->mlx_win, 2, 0, key_hook, game->test);

	test->py = (game->p.x * TILE_S) + (TILE_S / 2);
	test->px = (game->p.y * TILE_S) + (TILE_S / 2);
	test->map = game->map.m;
	printf("px = %d, py = %d\n", test->px, test->py);
	printf("theta = %f\n", test->theta);
	printf("r_len = %d\n", test->r_len);
	printf("c_len = %d\n", test->c_len);
  	mlx_hook(game->test->mlx_win, 2, 0,presse_key, test);
	mlx_hook(game->test->mlx_win, 3, 0,relesse_key, test);
	mlx_loop_hook(game->test->mlx_ptr, motion, test);
	mlx_loop(game->test->mlx_ptr);
	return (0);
}
