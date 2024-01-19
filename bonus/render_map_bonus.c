/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:55:46 by skarim            #+#    #+#             */
/*   Updated: 2024/01/15 15:57:08 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_image_to_window(t_game *g, void *xpm, int j, int i)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, xpm,
		IMG_WIDTH * j, IMG_HEIGHT * i);
}

void	ft_put_image(t_game *g, char c, int j, int i)
{
	if (c == '1')
		ft_put_image_to_window(g, g->wall_xpm, j, i);
	else if (c == 'P')
	{
		if (ft_strcmp(g->player.direction, "right") == 0)
			ft_put_image_to_window(g, g->pac_man_ro_xpm, j, i);
		else if (ft_strcmp(g->player.direction, "left") == 0)
			ft_put_image_to_window(g, g->pac_man_lo_xpm, j, i);
		else if (ft_strcmp(g->player.direction, "down") == 0)
			ft_put_image_to_window(g, g->pac_man_do_xpm, j, i);
		else if (ft_strcmp(g->player.direction, "up") == 0)
			ft_put_image_to_window(g, g->pac_man_uo_xpm, j, i);
	}
	else if (c == '0')
		ft_put_image_to_window(g, g->floor_xpm, j, i);
	else if (c == 'C')
		ft_put_image_to_window(g, g->coin_xpm, j, i);
	else if (c == 'E')
		ft_put_image_to_window(g, g->exit_xpm, j, i);
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
