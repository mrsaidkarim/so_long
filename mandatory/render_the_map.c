/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_the_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:51:36 by skarim            #+#    #+#             */
/*   Updated: 2024/01/07 19:26:47 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_put_xpm(t_game *g, char *path)
{
	void	*xpm;
	int		expected_width;
	int		expected_height;

	xpm = mlx_xpm_file_to_image(g->mlx_ptr, path, &expected_width,
			&expected_height);
	if (expected_width != IMG_WIDTH || expected_height != IMG_HEIGHT)
		ft_maperror(g, "Unexpected dimensions for XPM image");
	if (!xpm)
		ft_maperror(g, "Failed to create XPM image");
	return (xpm);
}

void	ft_put_image(t_game *g, char c, int j, int i)
{
	void	*xpm;

	xpm = NULL;
	if (c == '1')
		xpm = ft_put_xpm(g, "./textures/wall.xpm");
	else if (c == 'P')
	{
		if (ft_strcmp(g->player.direction, "right") == 0)
			xpm = ft_put_xpm(g, "./textures/pac_man_ro.xpm");
		else if (ft_strcmp(g->player.direction, "left") == 0)
			xpm = ft_put_xpm(g, "./textures/pac_man_lo.xpm");
		else if (ft_strcmp(g->player.direction, "down") == 0)
			xpm = ft_put_xpm(g, "./textures/pac_man_do.xpm");
		else if (ft_strcmp(g->player.direction, "up") == 0)
			xpm = ft_put_xpm(g, "./textures/pac_man_uo.xpm");
	}
	else if (c == '0')
		xpm = ft_put_xpm(g, "./textures/floor.xpm");
	else if (c == 'C')
		xpm = ft_put_xpm(g, "./textures/coin.xpm");
	else if (c == 'E')
		xpm = ft_put_xpm(g, "./textures/exit3.xpm");
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, xpm, IMG_WIDTH * j,
		IMG_HEIGHT * i);
}

void	ft_rendermap(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	while (i < g->map.height)
	{
		j = 0;
		while (j < g->map.width)
		{
			ft_put_image(g, g->map.content[i][j], j, i);
			j++;
		}
		i++;
	}
}
