/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:09:30 by skarim            #+#    #+#             */
/*   Updated: 2024/01/19 12:55:40 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_maperror(t_game *g, char *str)
{
	ft_free_map(g);
	ft_error_msg(str);
}

void	ft_map_parameters(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	g->map.coins = 0;
	g->map.exit = 0;
	g->map.player = 0;
	while (g->map.content[i])
	{
		j = 0;
		while (g->map.content[i][j])
		{
			if (g->map.content[i][j] == 'P')
				g->map.player++;
			else if (g->map.content[i][j] == 'E')
				g->map.exit++;
			else if (g->map.content[i][j] == 'C')
				g->map.coins++;
			else if (g->map.content[i][j] != '0' && g->map.content[i][j] != '1')
				ft_maperror(g, "the map contain invalid characters");
			j++;
		}
		i++;
	}
}

void	ft_intit_player(t_game *g, int y, int x)
{
	g->player.x = x;
	g->player.y = y;
	g->player.direction = "right";
	g->player.mv_nbr = 0;
}

void	ft_check_size(t_game *g)
{
	if (g->map.height >= WINDOW_HEIGHT / IMG_HEIGHT
		|| g->map.width >= WINDOW_WIDTH / IMG_WIDTH)
		ft_maperror(g, "The map size is too large for the screen!\n");
}

void	ft_checkmap(t_game *g)
{
	int	i;
	int	j;

	ft_map_parameters(g);
	if (g->map.exit != 1 || g->map.coins < 1 || g->map.player != 1)
		ft_maperror(g, "invalid components map!\n");
	i = 0;
	while (g->map.content[i])
	{
		j = 0;
		while (g->map.content[i][j])
		{
			if (i == 0 || i == g->map.height - 1
				|| j == 0 || j == g->map.width - 1)
				if (g->map.content[i][j] != '1')
					ft_maperror(g, "the map isn't closed by walls!\n");
			if (g->map.content[i][j] == 'P')
				ft_intit_player(g, i, j);
			j++;
		}
		i++;
	}
	ft_check_path(g);
	ft_check_size(g);
	check_ghost_patrol(g);
}
