/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:48:01 by skarim            #+#    #+#             */
/*   Updated: 2024/01/16 11:58:11 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error_msg(char *msg)
{
	write(1, "Error:\n", 7);
	write(1, msg, ft_strlen(msg));
	exit(1);
}

void	ft_checkargs(int argc, char **argv)
{
	int	n;

	if (argc > 2)
		ft_error_msg("Too many arguments");
	if (argc < 2)
		ft_error_msg("The map file is missing");
	n = ft_strlen(argv[1]);
	if (n > 4 && ft_strcmp(&argv[1][n - 4], ".ber") != 0)
		ft_error_msg("Map file extention is wrong");
	else if (n < 4)
		ft_error_msg("Map file extention is wrong");
}

void	ft_init_game(t_game *g)
{
	g->mlx_ptr = mlx_init();
	if (g->mlx_ptr)
	{
		g->win_ptr = mlx_new_window(g->mlx_ptr, g->map.width * IMG_WIDTH,
				g->map.height * IMG_HEIGHT, "./so_long");
		if (!g->win_ptr)
			ft_maperror(g, "Unable to create a window!\n");
	}
	else
		ft_maperror(g, "MLX initialization failed!\n");
}

int	main(int argc, char **argv)
{
	t_game	my_game;

	ft_checkargs(argc, argv);
	ft_getmap(argv, &my_game);
	ft_map_dimensions(&my_game);
	ft_checkmap(&my_game);
	ft_init_game(&my_game);
	prepare_xpm(&my_game);
	ft_load_xpm_images(&my_game);
	ft_rendermap(&my_game);
	mlx_hook(my_game.win_ptr, 2, 0, ft_move_player, &my_game);
	mlx_hook(my_game.win_ptr, 17, 0, ft_destroy_notify, &my_game);
	mlx_loop(my_game.mlx_ptr);
}
