/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:47:07 by skarim            #+#    #+#             */
/*   Updated: 2024/01/15 22:23:05 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_game(t_game *g)
{
	ft_free_xpms(g);
	ft_free_map(g);
	mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	exit(1);
}

void	prepare_xpm(t_game *g)
{
	g->floor_xpm = NULL;
	g->coin_xpm = NULL;
	g->exit_xpm = NULL;
	g->ghost_right_xpm = NULL;
	g->ghost_left_xpm = NULL;
	g->wall_xpm = NULL;
	g->pac_man_do_xpm = NULL;
	g->pac_man_lo_xpm = NULL;
	g->pac_man_ro_xpm = NULL;
	g->pac_man_uo_xpm = NULL;
}

void	ft_free_xpms(t_game *g)
{
	if (g->floor_xpm)
		mlx_destroy_image(g->mlx_ptr, g->floor_xpm);
	if (g->coin_xpm)
		mlx_destroy_image(g->mlx_ptr, g->coin_xpm);
	if (g->exit_xpm)
		mlx_destroy_image(g->mlx_ptr, g->exit_xpm);
	if (g->ghost_right_xpm)
		mlx_destroy_image(g->mlx_ptr, g->ghost_right_xpm);
	if (g->ghost_left_xpm)
		mlx_destroy_image(g->mlx_ptr, g->ghost_left_xpm);
	if (g->wall_xpm)
		mlx_destroy_image(g->mlx_ptr, g->wall_xpm);
	if (g->pac_man_do_xpm)
		mlx_destroy_image(g->mlx_ptr, g->pac_man_do_xpm);
	if (g->pac_man_lo_xpm)
		mlx_destroy_image(g->mlx_ptr, g->pac_man_lo_xpm);
	if (g->pac_man_ro_xpm)
		mlx_destroy_image(g->mlx_ptr, g->pac_man_ro_xpm);
	if (g->pac_man_uo_xpm)
		mlx_destroy_image(g->mlx_ptr, g->pac_man_uo_xpm);
}

void	*ft_put_xpm(t_game *g, char *file_path)
{
	void	*xpm;
	int		expected_width;
	int		expected_height;

	xpm = mlx_xpm_file_to_image(g->mlx_ptr, file_path,
			&expected_width, &expected_height);
	if (!xpm)
	{
		write(1, "Error:\nFailed to create XPM image", 33);
		ft_free_game(g);
	}
	if (expected_width != IMG_WIDTH || expected_height != IMG_HEIGHT)
	{
		write(1, "Error:\nUnexpected dimensions for XPM image", 42);
		ft_free_game(g);
	}
	return (xpm);
}

void	ft_load_xpm_images(t_game *g)
{
	g->floor_xpm = ft_put_xpm(g, "./textures/floor.xpm");
	g->coin_xpm = ft_put_xpm(g, "./textures/coin.xpm");
	g->exit_xpm = ft_put_xpm(g, "./textures/exit.xpm");
	g->ghost_right_xpm = ft_put_xpm(g, "./textures/ghost_right.xpm");
	g->ghost_left_xpm = ft_put_xpm(g, "./textures/ghost_left.xpm");
	g->wall_xpm = ft_put_xpm(g, "./textures/wall.xpm");
	g->pac_man_do_xpm = ft_put_xpm(g, "./textures/pac_man_do.xpm");
	g->pac_man_lo_xpm = ft_put_xpm(g, "./textures/pac_man_lo.xpm");
	g->pac_man_ro_xpm = ft_put_xpm(g, "./textures/pac_man_ro.xpm");
	g->pac_man_uo_xpm = ft_put_xpm(g, "./textures/pac_man_uo.xpm");
}
